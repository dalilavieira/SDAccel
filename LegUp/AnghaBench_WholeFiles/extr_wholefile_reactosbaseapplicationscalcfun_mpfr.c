#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_54__   TYPE_49__ ;
typedef  struct TYPE_53__   TYPE_3__ ;
typedef  struct TYPE_52__   TYPE_2__ ;
typedef  struct TYPE_51__   TYPE_1__ ;

/* Type definitions */
struct TYPE_51__ {int /*<<< orphan*/  mf; } ;
struct TYPE_52__ {scalar_t__ next; TYPE_1__ num; } ;
typedef  TYPE_2__ statistic_t ;
typedef  int /*<<< orphan*/  mpz_t ;
typedef  int /*<<< orphan*/  mpfr_t ;
struct TYPE_53__ {int /*<<< orphan*/  mf; } ;
typedef  TYPE_3__ calc_number_t ;
struct TYPE_54__ {int size; int degr; scalar_t__ base; TYPE_2__* stat; int /*<<< orphan*/  hStatWnd; void* is_nan; } ;

/* Variables and functions */
 int /*<<< orphan*/  IDC_LIST_STAT ; 
#define  IDC_RADIO_BYTE 134 
 scalar_t__ IDC_RADIO_DEC ; 
#define  IDC_RADIO_DEG 133 
#define  IDC_RADIO_DWORD 132 
#define  IDC_RADIO_GRAD 131 
#define  IDC_RADIO_QWORD 130 
#define  IDC_RADIO_RAD 129 
#define  IDC_RADIO_WORD 128 
 int /*<<< orphan*/  LB_GETCOUNT ; 
 int /*<<< orphan*/  MPFR_DEFAULT_RND ; 
 void* SendDlgItemMessage (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 void* TRUE ; 
 TYPE_49__ calc ; 
 int /*<<< orphan*/  mpfr_acos (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mpfr_acosh (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mpfr_add (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mpfr_asin (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mpfr_asinh (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mpfr_atan (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mpfr_atanh (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mpfr_cbrt (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mpfr_ceil (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mpfr_clear (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mpfr_cmp (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mpfr_const_pi (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mpfr_cos (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mpfr_cosh (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mpfr_div (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mpfr_div_ui (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mpfr_exp (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mpfr_exp10 (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mpfr_fac_ui (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 scalar_t__ mpfr_fits_ulong_p (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mpfr_frac (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mpfr_get_ui (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mpfr_get_z (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mpfr_init (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mpfr_log (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mpfr_log10 (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mpfr_mul (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mpfr_mul_si (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mpfr_mul_ui (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mpfr_number_p (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mpfr_pow_ui (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mpfr_set (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mpfr_set_si (int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mpfr_set_ui (int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mpfr_set_z (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 scalar_t__ mpfr_sgn (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mpfr_sin (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mpfr_sinh (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mpfr_sqr (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mpfr_sqrt (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mpfr_sub (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mpfr_tan (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mpfr_tanh (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mpfr_trunc (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mpfr_ui_div (int /*<<< orphan*/ ,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mpz_and (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mpz_clear (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mpz_com (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mpz_init (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mpz_init_set_si (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  mpz_init_set_str (int /*<<< orphan*/ ,char*,int) ; 
 int rpn_is_zero (TYPE_3__*) ; 
 void rpn_zero (TYPE_3__*) ; 

void apply_int_mask(calc_number_t *r)
{
    mpz_t a, mask;

    switch (calc.size) {
    case IDC_RADIO_QWORD:
        mpz_init_set_str(mask, "FFFFFFFFFFFFFFFF", 16);
        break;
    case IDC_RADIO_DWORD:
        mpz_init_set_str(mask, "00000000FFFFFFFF", 16);
        break;
    case IDC_RADIO_WORD:
        mpz_init_set_str(mask, "000000000000FFFF", 16);
        break;
    case IDC_RADIO_BYTE:
        mpz_init_set_str(mask, "00000000000000FF", 16);
        break;
    default:
        mpz_init_set_si(mask, -1);
    }
    mpz_init(a);
    mpfr_get_z(a, r->mf, MPFR_DEFAULT_RND);
    mpz_and(a, a, mask);
    mpfr_set_z(r->mf, a, MPFR_DEFAULT_RND);
    mpz_clear(a);
    mpz_clear(mask);
}

__attribute__((used)) static void validate_rad2angle(calc_number_t *r)
{
    mpfr_t mult, divs;

    mpfr_init(mult);
    mpfr_init(divs);
    switch (calc.degr) {
    case IDC_RADIO_DEG:
        mpfr_set_ui(mult, 180, MPFR_DEFAULT_RND);
        mpfr_const_pi(divs, MPFR_DEFAULT_RND);
        break;
    case IDC_RADIO_RAD:
        mpfr_set_ui(mult, 1, MPFR_DEFAULT_RND);
        mpfr_set_ui(divs, 1, MPFR_DEFAULT_RND);
        break;
    case IDC_RADIO_GRAD:
        mpfr_set_ui(mult, 200, MPFR_DEFAULT_RND);
        mpfr_const_pi(divs, MPFR_DEFAULT_RND);
        break;
    }
    mpfr_mul(r->mf, r->mf, mult, MPFR_DEFAULT_RND);
    mpfr_div(r->mf, r->mf, divs, MPFR_DEFAULT_RND);

    mpfr_clear(mult);
    mpfr_clear(divs);
}

__attribute__((used)) static void validate_angle2rad(calc_number_t *r)
{
    mpfr_t mult, divs;

    if (!mpfr_number_p(r->mf)) {
        calc.is_nan = TRUE;
        return;
    }
    mpfr_init(mult);
    mpfr_init(divs);
    switch (calc.degr) {
    case IDC_RADIO_DEG:
        mpfr_const_pi(mult, MPFR_DEFAULT_RND);
        mpfr_set_ui(divs, 180, MPFR_DEFAULT_RND);
        break;
    case IDC_RADIO_RAD:
        mpfr_set_ui(mult, 1, MPFR_DEFAULT_RND);
        mpfr_set_ui(divs, 1, MPFR_DEFAULT_RND);
        break;
    case IDC_RADIO_GRAD:
        mpfr_const_pi(mult, MPFR_DEFAULT_RND);
        mpfr_set_ui(divs, 200, MPFR_DEFAULT_RND);
        break;
    }
    mpfr_mul(r->mf, r->mf, mult, MPFR_DEFAULT_RND);
    mpfr_div(r->mf, r->mf, divs, MPFR_DEFAULT_RND);

    mpfr_clear(mult);
    mpfr_clear(divs);
}

__attribute__((used)) static void build_rad_const(
    mpfr_t *mp_pi,
    mpfr_t *mp_pi_2,
    mpfr_t *mp_3_pi_2,
    mpfr_t *mp_2_pi)
{
    mpfr_init(*mp_pi);
    mpfr_init(*mp_pi_2);
    mpfr_init(*mp_3_pi_2);
    mpfr_init(*mp_2_pi);
    mpfr_const_pi(*mp_pi, MPFR_DEFAULT_RND);
    mpfr_div_ui(*mp_pi_2, *mp_pi, 2, MPFR_DEFAULT_RND);
    mpfr_mul_ui(*mp_3_pi_2, *mp_pi, 3, MPFR_DEFAULT_RND);
    mpfr_div_ui(*mp_3_pi_2, *mp_3_pi_2, 2, MPFR_DEFAULT_RND);
    mpfr_mul_ui(*mp_2_pi, *mp_pi, 2, MPFR_DEFAULT_RND);
}

void rpn_sin(calc_number_t *c)
{
    mpfr_t mp_pi, mp_pi_2, mp_3_pi_2, mp_2_pi;

    validate_angle2rad(c);
    build_rad_const(&mp_pi, &mp_pi_2, &mp_3_pi_2, &mp_2_pi);

    if (rpn_is_zero(c) || !mpfr_cmp(c->mf, mp_pi) || !mpfr_cmp(c->mf, mp_2_pi))
        rpn_zero(c);
    else
    if (!mpfr_cmp(c->mf, mp_3_pi_2))
        mpfr_set_si(c->mf, -1, MPFR_DEFAULT_RND);
    else
    if (!mpfr_cmp(c->mf, mp_pi_2))
        mpfr_set_si(c->mf, 1, MPFR_DEFAULT_RND);
    else {
        mpfr_sin(c->mf, c->mf, MPFR_DEFAULT_RND);
        if (!mpfr_number_p(c->mf)) calc.is_nan = TRUE;
    }
    mpfr_clear(mp_pi);
    mpfr_clear(mp_pi_2);
    mpfr_clear(mp_3_pi_2);
    mpfr_clear(mp_2_pi);
}

void rpn_cos(calc_number_t *c)
{
    mpfr_t mp_pi, mp_pi_2, mp_3_pi_2, mp_2_pi;

    validate_angle2rad(c);
    build_rad_const(&mp_pi, &mp_pi_2, &mp_3_pi_2, &mp_2_pi);

    if (!mpfr_cmp(c->mf, mp_pi_2) || !mpfr_cmp(c->mf, mp_3_pi_2))
        rpn_zero(c);
    else
    if (!mpfr_cmp(c->mf, mp_pi))
        mpfr_set_si(c->mf, -1, MPFR_DEFAULT_RND);
    else
    if (!mpfr_cmp(c->mf, mp_2_pi))
        mpfr_set_si(c->mf, 1, MPFR_DEFAULT_RND);
    else {
        mpfr_cos(c->mf, c->mf, MPFR_DEFAULT_RND);
        if (!mpfr_number_p(c->mf)) calc.is_nan = TRUE;
    }
    mpfr_clear(mp_pi);
    mpfr_clear(mp_pi_2);
    mpfr_clear(mp_3_pi_2);
    mpfr_clear(mp_2_pi);
}

void rpn_tan(calc_number_t *c)
{
    mpfr_t mp_pi, mp_pi_2, mp_3_pi_2, mp_2_pi;

    validate_angle2rad(c);
    build_rad_const(&mp_pi, &mp_pi_2, &mp_3_pi_2, &mp_2_pi);

    if (!mpfr_cmp(c->mf, mp_pi_2) || !mpfr_cmp(c->mf, mp_3_pi_2))
        calc.is_nan = TRUE;
    else
    if (!mpfr_cmp(c->mf, mp_pi) || !mpfr_cmp(c->mf, mp_2_pi))
        rpn_zero(c);
    else {
        mpfr_tan(c->mf, c->mf, MPFR_DEFAULT_RND);
        if (!mpfr_number_p(c->mf)) calc.is_nan = TRUE;
    }
    mpfr_clear(mp_pi);
    mpfr_clear(mp_pi_2);
    mpfr_clear(mp_3_pi_2);
    mpfr_clear(mp_2_pi);
}

void rpn_asin(calc_number_t *c)
{
    mpfr_asin(c->mf, c->mf, MPFR_DEFAULT_RND);
    validate_rad2angle(c);
}

void rpn_acos(calc_number_t *c)
{
    mpfr_acos(c->mf, c->mf, MPFR_DEFAULT_RND);
    validate_rad2angle(c);
}

void rpn_atan(calc_number_t *c)
{
    mpfr_atan(c->mf, c->mf, MPFR_DEFAULT_RND);
    validate_rad2angle(c);
}

void rpn_sinh(calc_number_t *c)
{
    mpfr_sinh(c->mf, c->mf, MPFR_DEFAULT_RND);
    if (!mpfr_number_p(c->mf)) calc.is_nan = TRUE;
}

void rpn_cosh(calc_number_t *c)
{
    mpfr_cosh(c->mf, c->mf, MPFR_DEFAULT_RND);
    if (!mpfr_number_p(c->mf)) calc.is_nan = TRUE;
}

void rpn_tanh(calc_number_t *c)
{
    mpfr_tanh(c->mf, c->mf, MPFR_DEFAULT_RND);
    if (!mpfr_number_p(c->mf)) calc.is_nan = TRUE;
}

void rpn_asinh(calc_number_t *c)
{
    mpfr_asinh(c->mf, c->mf, MPFR_DEFAULT_RND);
    if (!mpfr_number_p(c->mf)) calc.is_nan = TRUE;
}

void rpn_acosh(calc_number_t *c)
{
    mpfr_acosh(c->mf, c->mf, MPFR_DEFAULT_RND);
    if (!mpfr_number_p(c->mf)) calc.is_nan = TRUE;
}

void rpn_atanh(calc_number_t *c)
{
    mpfr_atanh(c->mf, c->mf, MPFR_DEFAULT_RND);
    if (!mpfr_number_p(c->mf)) calc.is_nan = TRUE;
}

void rpn_int(calc_number_t *c)
{
    mpfr_trunc(c->mf, c->mf);
}

void rpn_frac(calc_number_t *c)
{
    mpfr_frac(c->mf, c->mf, MPFR_DEFAULT_RND);
}

void rpn_reci(calc_number_t *c)
{
    if (mpfr_sgn(c->mf) == 0)
        calc.is_nan = TRUE;
    else
        mpfr_ui_div(c->mf, 1, c->mf, MPFR_DEFAULT_RND);
}

void rpn_fact(calc_number_t *c)
{
    if (mpfr_sgn(c->mf) < 0) {
        calc.is_nan = TRUE;
        return;
    }

    mpfr_trunc(c->mf, c->mf);
    if (mpfr_fits_ulong_p(c->mf, MPFR_DEFAULT_RND) == 0)
        calc.is_nan = TRUE;
    else {
        mpfr_fac_ui(c->mf, mpfr_get_ui(c->mf, MPFR_DEFAULT_RND), MPFR_DEFAULT_RND);
        if (!mpfr_number_p(c->mf)) calc.is_nan = TRUE;
    }
}

void rpn_not(calc_number_t *c)
{
    mpz_t a;

    mpz_init(a);
    mpfr_get_z(a, c->mf, MPFR_DEFAULT_RND);
    mpz_com(a, a);
    mpfr_set_z(c->mf, a, MPFR_DEFAULT_RND);
    mpz_clear(a);
}

void rpn_pi(calc_number_t *c)
{
    mpfr_const_pi(c->mf, MPFR_DEFAULT_RND);
}

void rpn_2pi(calc_number_t *c)
{
    mpfr_const_pi(c->mf, MPFR_DEFAULT_RND);
    mpfr_mul_ui(c->mf, c->mf, 2, MPFR_DEFAULT_RND);
}

void rpn_sign(calc_number_t *c)
{
    mpfr_mul_si(c->mf, c->mf, -1, MPFR_DEFAULT_RND);
}

void rpn_exp2(calc_number_t *c)
{
    mpfr_sqr(c->mf, c->mf, MPFR_DEFAULT_RND);
    if (!mpfr_number_p(c->mf)) calc.is_nan = TRUE;
}

void rpn_exp3(calc_number_t *c)
{
    mpfr_pow_ui(c->mf, c->mf, 3, MPFR_DEFAULT_RND);
    if (!mpfr_number_p(c->mf)) calc.is_nan = TRUE;
}

void rpn_sqrt(calc_number_t *c)
{
    mpfr_sqrt(c->mf, c->mf, MPFR_DEFAULT_RND);
    if (!mpfr_number_p(c->mf)) calc.is_nan = TRUE;
}

void rpn_cbrt(calc_number_t *c)
{
    mpfr_cbrt(c->mf, c->mf, MPFR_DEFAULT_RND);
    if (!mpfr_number_p(c->mf)) calc.is_nan = TRUE;
}

void rpn_exp(calc_number_t *c)
{
    mpfr_exp(c->mf, c->mf, MPFR_DEFAULT_RND);
    if (!mpfr_number_p(c->mf)) calc.is_nan = TRUE;
}

void rpn_exp10(calc_number_t *c)
{
    mpfr_exp10(c->mf, c->mf, MPFR_DEFAULT_RND);
    if (!mpfr_number_p(c->mf)) calc.is_nan = TRUE;
}

void rpn_ln(calc_number_t *c)
{
    mpfr_log(c->mf, c->mf, MPFR_DEFAULT_RND);
    if (!mpfr_number_p(c->mf)) calc.is_nan = TRUE;
}

void rpn_log(calc_number_t *c)
{
    mpfr_log10(c->mf, c->mf, MPFR_DEFAULT_RND);
    if (!mpfr_number_p(c->mf)) calc.is_nan = TRUE;
}

__attribute__((used)) static void stat_sum(mpfr_t sum)
{
    statistic_t *p = calc.stat;

    mpfr_set_ui(sum, 0, MPFR_DEFAULT_RND);
    while (p != NULL) {
        mpfr_add(sum, sum, p->num.mf, MPFR_DEFAULT_RND);
        p = (statistic_t *)(p->next);
    }
}

__attribute__((used)) static void stat_sum2(mpfr_t sum)
{
    statistic_t *p = calc.stat;
    mpfr_t       sqr;

    mpfr_init(sqr);
    mpfr_set_ui(sum, 0, MPFR_DEFAULT_RND);
    while (p != NULL) {
        mpfr_mul(sqr, p->num.mf, p->num.mf, MPFR_DEFAULT_RND);
        mpfr_add(sum, sum, sqr, MPFR_DEFAULT_RND);
        p = (statistic_t *)(p->next);
    }
    mpfr_clear(sqr);
}

void rpn_ave(calc_number_t *c)
{
    int     n;

    stat_sum(c->mf);
    n = SendDlgItemMessage(calc.hStatWnd, IDC_LIST_STAT, LB_GETCOUNT, 0, 0);

    if (n)
        mpfr_div_ui(c->mf, c->mf, n, MPFR_DEFAULT_RND);

    if (calc.base != IDC_RADIO_DEC)
        mpfr_trunc(c->mf, c->mf);
}

void rpn_ave2(calc_number_t *c)
{
    int     n;

    stat_sum2(c->mf);
    n = SendDlgItemMessage(calc.hStatWnd, IDC_LIST_STAT, LB_GETCOUNT, 0, 0);

    if (n)
        mpfr_div_ui(c->mf, c->mf, n, MPFR_DEFAULT_RND);

    if (calc.base != IDC_RADIO_DEC)
        mpfr_trunc(c->mf, c->mf);
}

void rpn_sum(calc_number_t *c)
{
    stat_sum(c->mf);

    if (calc.base != IDC_RADIO_DEC)
        mpfr_trunc(c->mf, c->mf);
}

void rpn_sum2(calc_number_t *c)
{
    stat_sum2(c->mf);

    if (calc.base != IDC_RADIO_DEC)
        mpfr_trunc(c->mf, c->mf);
}

__attribute__((used)) static void rpn_s_ex(calc_number_t *c, int pop_type)
{
    mpfr_t        dev;
    mpfr_t        num;
    unsigned long n = 0;
    statistic_t  *p = calc.stat;

    n = SendDlgItemMessage(calc.hStatWnd, IDC_LIST_STAT, LB_GETCOUNT, 0, 0);
    if (n < 2) {
        mpfr_set_ui(c->mf, 0, MPFR_DEFAULT_RND);
        return;
    }

    stat_sum(c->mf);
    mpfr_div_ui(c->mf, c->mf, n, MPFR_DEFAULT_RND);

    mpfr_init(dev);
    mpfr_init(num);

    mpfr_set_ui(dev, 0, MPFR_DEFAULT_RND);
    p = calc.stat;
    while (p != NULL) {
        mpfr_sub(num, p->num.mf, c->mf, MPFR_DEFAULT_RND);
        mpfr_sqr(num, num, MPFR_DEFAULT_RND);
        mpfr_add(dev, dev, num, MPFR_DEFAULT_RND);
        p = (statistic_t *)(p->next);
    }
    mpfr_div_ui(c->mf, dev, pop_type ? n-1 : n, MPFR_DEFAULT_RND);
    mpfr_sqrt(c->mf, c->mf, MPFR_DEFAULT_RND);

    if (calc.base != IDC_RADIO_DEC)
        mpfr_trunc(c->mf, c->mf);

    mpfr_clear(dev);
    mpfr_clear(num);
}

void rpn_s(calc_number_t *c)
{
    rpn_s_ex(c, 0);
}

void rpn_s_m1(calc_number_t *c)
{
    rpn_s_ex(c, 1);
}

void rpn_dms2dec(calc_number_t *c)
{
    mpfr_t d, m, s;

    mpfr_init(d);
    mpfr_init(m);
    mpfr_init(s);

    mpfr_trunc(d, c->mf);
    mpfr_frac(m, c->mf, MPFR_DEFAULT_RND);
    mpfr_mul_ui(m, m, 100, MPFR_DEFAULT_RND);

    mpfr_frac(s, m, MPFR_DEFAULT_RND);
    mpfr_trunc(m, m);
    mpfr_mul_ui(s, s, 100, MPFR_DEFAULT_RND);
    mpfr_ceil(s, s);

    mpfr_div_ui(m, m, 60, MPFR_DEFAULT_RND);
    mpfr_div_ui(s, s, 3600, MPFR_DEFAULT_RND);
    mpfr_add(c->mf, d, m, MPFR_DEFAULT_RND);
    mpfr_add(c->mf, c->mf, s, MPFR_DEFAULT_RND);

    mpfr_clear(d);
    mpfr_clear(m);
    mpfr_clear(s);
}

void rpn_dec2dms(calc_number_t *c)
{
    mpfr_t d, m, s;

    mpfr_init(d);
    mpfr_init(m);
    mpfr_init(s);

    mpfr_trunc(d, c->mf);
    mpfr_frac(m, c->mf, MPFR_DEFAULT_RND);
    mpfr_mul_ui(m, m, 60, MPFR_DEFAULT_RND);

    mpfr_frac(s, m, MPFR_DEFAULT_RND);
    mpfr_trunc(m, m);
    mpfr_mul_ui(s, s, 60, MPFR_DEFAULT_RND);
    mpfr_ceil(s, s);

    mpfr_div_ui(m, m, 100, MPFR_DEFAULT_RND);
    mpfr_div_ui(s, s, 10000, MPFR_DEFAULT_RND);
    mpfr_add(c->mf, d, m, MPFR_DEFAULT_RND);
    mpfr_add(c->mf, c->mf, s, MPFR_DEFAULT_RND);

    mpfr_clear(d);
    mpfr_clear(m);
    mpfr_clear(s);
}

void rpn_zero(calc_number_t *c)
{
    mpfr_set_ui(c->mf, 0, MPFR_DEFAULT_RND);
}

void rpn_copy(calc_number_t *dst, calc_number_t *src)
{
    mpfr_set(dst->mf, src->mf, MPFR_DEFAULT_RND);
}

int rpn_is_zero(calc_number_t *c)
{
    return (mpfr_sgn(c->mf) == 0);
}

void rpn_alloc(calc_number_t *c)
{
    mpfr_init(c->mf);
}

void rpn_free(calc_number_t *c)
{
    mpfr_clear(c->mf);
}

