#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
typedef  int krint64_t ;
struct TYPE_6__ {int* mt; int mti; } ;
typedef  TYPE_1__ krand_t ;
typedef  double (* kmin_f ) (int,double*,void*) ;
typedef  double (* kmin1_f ) (double,void*) ;

/* Variables and functions */
 double KF_GAMMA_EPS ; 
 double KF_TINY ; 
 int KR_LM ; 
 int KR_MM ; 
 int KR_NN ; 
 int KR_UM ; 
 int M_SQRT2 ; 
 scalar_t__ calloc (int,int) ; 
 double exp (double) ; 
 double fabs (double) ; 
 int /*<<< orphan*/  free (double*) ; 
 double log (int) ; 
 TYPE_1__* malloc (int) ; 
 int /*<<< orphan*/  memcpy (double*,double*,int) ; 

__attribute__((used)) static void kr_srand0(krint64_t seed, krand_t *kr)
{
	kr->mt[0] = seed;
	for (kr->mti = 1; kr->mti < KR_NN; ++kr->mti) 
		kr->mt[kr->mti] = 6364136223846793005ULL * (kr->mt[kr->mti - 1] ^ (kr->mt[kr->mti - 1] >> 62)) + kr->mti;
}

krand_t *kr_srand(krint64_t seed)
{
	krand_t *kr;
	kr = malloc(sizeof(krand_t));
	kr_srand0(seed, kr);
	return kr;
}

krint64_t kr_rand(krand_t *kr)
{
	krint64_t x;
	static const krint64_t mag01[2] = { 0, 0xB5026F5AA96619E9ULL };
    if (kr->mti >= KR_NN) {
		int i;
		if (kr->mti == KR_NN + 1) kr_srand0(5489ULL, kr);
        for (i = 0; i < KR_NN - KR_MM; ++i) {
            x = (kr->mt[i] & KR_UM) | (kr->mt[i+1] & KR_LM);
            kr->mt[i] = kr->mt[i + KR_MM] ^ (x>>1) ^ mag01[(int)(x&1)];
        }
        for (; i < KR_NN - 1; ++i) {
            x = (kr->mt[i] & KR_UM) | (kr->mt[i+1] & KR_LM);
            kr->mt[i] = kr->mt[i + (KR_MM - KR_NN)] ^ (x>>1) ^ mag01[(int)(x&1)];
        }
        x = (kr->mt[KR_NN - 1] & KR_UM) | (kr->mt[0] & KR_LM);
        kr->mt[KR_NN - 1] = kr->mt[KR_MM - 1] ^ (x>>1) ^ mag01[(int)(x&1)];
        kr->mti = 0;
    }
    x = kr->mt[kr->mti++];
    x ^= (x >> 29) & 0x5555555555555555ULL;
    x ^= (x << 17) & 0x71D67FFFEDA60000ULL;
    x ^= (x << 37) & 0xFFF7EEE000000000ULL;
    x ^= (x >> 43);
    return x;
}

__attribute__((used)) static double __kmin_hj_aux(kmin_f func, int n, double *x1, void *data, double fx1, double *dx, int *n_calls)
{
	int k, j = *n_calls;
	double ftmp;
	for (k = 0; k != n; ++k) {
		x1[k] += dx[k];
		ftmp = func(n, x1, data); ++j;
		if (ftmp < fx1) fx1 = ftmp;
		else { /* search the opposite direction */
			dx[k] = 0.0 - dx[k];
			x1[k] += dx[k] + dx[k];
			ftmp = func(n, x1, data); ++j;
			if (ftmp < fx1) fx1 = ftmp;
			else x1[k] -= dx[k]; /* back to the original x[k] */
		}
	}
	*n_calls = j;
	return fx1; /* here: fx1=f(n,x1) */
}

double kmin_hj(kmin_f func, int n, double *x, void *data, double r, double eps, int max_calls)
{
	double fx, fx1, *x1, *dx, radius;
	int k, n_calls = 0;
	x1 = (double*)calloc(n, sizeof(double));
	dx = (double*)calloc(n, sizeof(double));
	for (k = 0; k != n; ++k) { /* initial directions, based on MGJ */
		dx[k] = fabs(x[k]) * r;
		if (dx[k] == 0) dx[k] = r;
	}
	radius = r;
	fx1 = fx = func(n, x, data); ++n_calls;
	for (;;) {
		memcpy(x1, x, n * sizeof(double)); /* x1 = x */
		fx1 = __kmin_hj_aux(func, n, x1, data, fx, dx, &n_calls);
		while (fx1 < fx) {
			for (k = 0; k != n; ++k) {
				double t = x[k];
				dx[k] = x1[k] > x[k]? fabs(dx[k]) : 0.0 - fabs(dx[k]);
				x[k] = x1[k];
				x1[k] = x1[k] + x1[k] - t;
			}
			fx = fx1;
			if (n_calls >= max_calls) break;
			fx1 = func(n, x1, data); ++n_calls;
			fx1 = __kmin_hj_aux(func, n, x1, data, fx1, dx, &n_calls);
			if (fx1 >= fx) break;
			for (k = 0; k != n; ++k)
				if (fabs(x1[k] - x[k]) > .5 * fabs(dx[k])) break;
			if (k == n) break;
		}
		if (radius >= eps) {
			if (n_calls >= max_calls) break;
			radius *= r;
			for (k = 0; k != n; ++k) dx[k] *= r;
		} else break; /* converge */
	}
	free(x1); free(dx);
	return fx1;
}

double kmin_brent(kmin1_f func, double a, double b, void *data, double tol, double *xmin)
{
	double bound, u, r, q, fu, tmp, fa, fb, fc, c;
	const double gold1 = 1.6180339887;
	const double gold2 = 0.3819660113;
	const double tiny = 1e-20;
	const int max_iter = 100;

	double e, d, w, v, mid, tol1, tol2, p, eold, fv, fw;
	int iter;

	fa = func(a, data); fb = func(b, data);
	if (fb > fa) { // swap, such that f(a) > f(b)
		tmp = a; a = b; b = tmp;
		tmp = fa; fa = fb; fb = tmp;
	}
	c = b + gold1 * (b - a), fc = func(c, data); // golden section extrapolation
	while (fb > fc) {
		bound = b + 100.0 * (c - b); // the farthest point where we want to go
		r = (b - a) * (fb - fc);
		q = (b - c) * (fb - fa);
		if (fabs(q - r) < tiny) { // avoid 0 denominator
			tmp = q > r? tiny : 0.0 - tiny;
		} else tmp = q - r;
		u = b - ((b - c) * q - (b - a) * r) / (2.0 * tmp); // u is the parabolic extrapolation point
		if ((b > u && u > c) || (b < u && u < c)) { // u lies between b and c
			fu = func(u, data);
			if (fu < fc) { // (b,u,c) bracket the minimum
				a = b; b = u; fa = fb; fb = fu;
				break;
			} else if (fu > fb) { // (a,b,u) bracket the minimum
				c = u; fc = fu;
				break;
			}
			u = c + gold1 * (c - b); fu = func(u, data); // golden section extrapolation
		} else if ((c > u && u > bound) || (c < u && u < bound)) { // u lies between c and bound
			fu = func(u, data);
			if (fu < fc) { // fb > fc > fu
				b = c; c = u; u = c + gold1 * (c - b);
				fb = fc; fc = fu; fu = func(u, data);
			} else { // (b,c,u) bracket the minimum
				a = b; b = c; c = u;
				fa = fb; fb = fc; fc = fu;
				break;
			}
		} else if ((u > bound && bound > c) || (u < bound && bound < c)) { // u goes beyond the bound
			u = bound; fu = func(u, data);
		} else { // u goes the other way around, use golden section extrapolation
			u = c + gold1 * (c - b); fu = func(u, data);
		}
		a = b; b = c; c = u;
		fa = fb; fb = fc; fc = fu;
	}
	if (a > c) u = a, a = c, c = u; // swap

	// now, a<b<c, fa>fb and fb<fc, move on to Brent's algorithm
	e = d = 0.0;
	w = v = b; fv = fw = fb;
	for (iter = 0; iter != max_iter; ++iter) {
		mid = 0.5 * (a + c);
		tol2 = 2.0 * (tol1 = tol * fabs(b) + tiny);
		if (fabs(b - mid) <= (tol2 - 0.5 * (c - a))) {
			*xmin = b; return fb; // found
		}
		if (fabs(e) > tol1) {
			// related to parabolic interpolation
			r = (b - w) * (fb - fv);
			q = (b - v) * (fb - fw);
			p = (b - v) * q - (b - w) * r;
			q = 2.0 * (q - r);
			if (q > 0.0) p = 0.0 - p;
			else q = 0.0 - q;
			eold = e; e = d;
			if (fabs(p) >= fabs(0.5 * q * eold) || p <= q * (a - b) || p >= q * (c - b)) {
				d = gold2 * (e = (b >= mid ? a - b : c - b));
			} else {
				d = p / q; u = b + d; // actual parabolic interpolation happens here
				if (u - a < tol2 || c - u < tol2)
					d = (mid > b)? tol1 : 0.0 - tol1;
			}
		} else d = gold2 * (e = (b >= mid ? a - b : c - b)); // golden section interpolation
		u = fabs(d) >= tol1 ? b + d : b + (d > 0.0? tol1 : -tol1);
		fu = func(u, data);
		if (fu <= fb) { // u is the minimum point so far
			if (u >= b) a = b;
			else c = b;
			v = w; w = b; b = u; fv = fw; fw = fb; fb = fu;
		} else { // adjust (a,c) and (u,v,w)
			if (u < b) a = u;
			else c = u;
			if (fu <= fw || w == b) {
				v = w; w = u;
				fv = fw; fw = fu;
			} else if (fu <= fv || v == b || v == w) {
				v = u; fv = fu;
			}
		}
	}
	*xmin = b;
	return fb;
}

double kf_lgamma(double z)
{
	double x = 0;
	x += 0.1659470187408462e-06 / (z+7);
	x += 0.9934937113930748e-05 / (z+6);
	x -= 0.1385710331296526     / (z+5);
	x += 12.50734324009056      / (z+4);
	x -= 176.6150291498386      / (z+3);
	x += 771.3234287757674      / (z+2);
	x -= 1259.139216722289      / (z+1);
	x += 676.5203681218835      / z;
	x += 0.9999999999995183;
	return log(x) - 5.58106146679532777 - z + (z-0.5) * log(z+6.5);
}

double kf_erfc(double x)
{
	const double p0 = 220.2068679123761;
	const double p1 = 221.2135961699311;
	const double p2 = 112.0792914978709;
	const double p3 = 33.912866078383;
	const double p4 = 6.37396220353165;
	const double p5 = .7003830644436881;
	const double p6 = .03526249659989109;
	const double q0 = 440.4137358247522;
	const double q1 = 793.8265125199484;
	const double q2 = 637.3336333788311;
	const double q3 = 296.5642487796737;
	const double q4 = 86.78073220294608;
	const double q5 = 16.06417757920695;
	const double q6 = 1.755667163182642;
	const double q7 = .08838834764831844;
	double expntl, z, p;
	z = fabs(x) * M_SQRT2;
	if (z > 37.) return x > 0.? 0. : 2.;
	expntl = exp(z * z * - .5);
	if (z < 10. / M_SQRT2) // for small z
	    p = expntl * ((((((p6 * z + p5) * z + p4) * z + p3) * z + p2) * z + p1) * z + p0)
			/ (((((((q7 * z + q6) * z + q5) * z + q4) * z + q3) * z + q2) * z + q1) * z + q0);
	else p = expntl / 2.506628274631001 / (z + 1. / (z + 2. / (z + 3. / (z + 4. / (z + .65)))));
	return x > 0.? 2. * p : 2. * (1. - p);
}

__attribute__((used)) static double _kf_gammap(double s, double z)
{
	double sum, x;
	int k;
	for (k = 1, sum = x = 1.; k < 100; ++k) {
		sum += (x *= z / (s + k));
		if (x / sum < KF_GAMMA_EPS) break;
	}
	return exp(s * log(z) - z - kf_lgamma(s + 1.) + log(sum));
}

__attribute__((used)) static double _kf_gammaq(double s, double z)
{
	int j;
	double C, D, f;
	f = 1. + z - s; C = f; D = 0.;
	// Modified Lentz's algorithm for computing continued fraction
	// See Numerical Recipes in C, 2nd edition, section 5.2
	for (j = 1; j < 100; ++j) {
		double a = j * (s - j), b = (j<<1) + 1 + z - s, d;
		D = b + a * D;
		if (D < KF_TINY) D = KF_TINY;
		C = b + a / C;
		if (C < KF_TINY) C = KF_TINY;
		D = 1. / D;
		d = C * D;
		f *= d;
		if (fabs(d - 1.) < KF_GAMMA_EPS) break;
	}
	return exp(s * log(z) - z - kf_lgamma(s) - log(f));
}

double kf_gammap(double s, double z)
{
	return z <= 1. || z < s? _kf_gammap(s, z) : 1. - _kf_gammaq(s, z);
}

double kf_gammaq(double s, double z)
{
	return z <= 1. || z < s? 1. - _kf_gammap(s, z) : _kf_gammaq(s, z);
}

__attribute__((used)) static double kf_betai_aux(double a, double b, double x)
{
	double C, D, f;
	int j;
	if (x == 0.) return 0.;
	if (x == 1.) return 1.;
	f = 1.; C = f; D = 0.;
	// Modified Lentz's algorithm for computing continued fraction
	for (j = 1; j < 200; ++j) {
		double aa, d;
		int m = j>>1;
		aa = (j&1)? -(a + m) * (a + b + m) * x / ((a + 2*m) * (a + 2*m + 1))
			: m * (b - m) * x / ((a + 2*m - 1) * (a + 2*m));
		D = 1. + aa * D;
		if (D < KF_TINY) D = KF_TINY;
		C = 1. + aa / C;
		if (C < KF_TINY) C = KF_TINY;
		D = 1. / D;
		d = C * D;
		f *= d;
		if (fabs(d - 1.) < KF_GAMMA_EPS) break;
	}
	return exp(kf_lgamma(a+b) - kf_lgamma(a) - kf_lgamma(b) + a * log(x) + b * log(1.-x)) / a / f;
}

double kf_betai(double a, double b, double x)
{
	return x < (a + 1.) / (a + b + 2.)? kf_betai_aux(a, b, x) : 1. - kf_betai_aux(b, a, 1. - x);
}

double km_ks_dist(int na, const double a[], int nb, const double b[]) // a[] and b[] MUST BE sorted
{
	int ia = 0, ib = 0;
	double fa = 0, fb = 0, sup = 0, na1 = 1. / na, nb1 = 1. / nb;
	while (ia < na || ib < nb) {
		if (ia == na) fb += nb1, ++ib;
		else if (ib == nb) fa += na1, ++ia;
		else if (a[ia] < b[ib]) fa += na1, ++ia;
		else if (a[ia] > b[ib]) fb += nb1, ++ib;
		else fa += na1, fb += nb1, ++ia, ++ib;
		if (sup < fabs(fa - fb)) sup = fabs(fa - fb);
	}
	return sup;
}

