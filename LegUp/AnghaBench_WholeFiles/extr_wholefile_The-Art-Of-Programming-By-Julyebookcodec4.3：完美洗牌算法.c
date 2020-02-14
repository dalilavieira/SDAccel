#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */

/* Type definitions */

/* Variables and functions */
 int N ; 

void pefect_shuffle1(int *a, int n)
{
	int n2 = n * 2, i, b[N];
	for (i = 1; i <= n2; ++i)
	{
		b[(i * 2) % (n2 + 1)] = a[i];
	}
	for (i = 1; i <= n2; ++i)
	{
		a[i] = b[i];
	}
}

void perfect_shuffle2(int *a, int n)
{
	int t, i;
	if (n == 1)
	{
		t = a[1];
		a[1] = a[2];
		a[2] = t;
		return;
	}
	int n2 = n * 2, n3 = n / 2;
	if (n % 2 == 1)    //奇数的处理
	{
		t = a[n];
		for (i = n + 1; i <= n2; ++i)
		{
			a[i - 1] = a[i];
		}
		a[n2] = t;
		--n;
	}
	//到此n是偶数

	for (i = n3 + 1; i <= n; ++i)
	{
		t = a[i];
		a[i] = a[i + n3];
		a[i + n3] = t;
	}

	// [1.. n /2]
	perfect_shuffle2(a, n3);
	perfect_shuffle2(a + n, n3);
}

void cycle_leader(int *a, int from, int mod)
{
	int t,i;

	for (i = from * 2 % mod; i != from; i = i * 2 % mod)
	{
		t = a[i];
		a[i] = a[from];
		a[from] = t;
	}
}

void reverse(int *a, int from, int to)
{
	int t;
	for (; from < to; ++from, --to)
	{
		t = a[from];
		a[from] = a[to];
		a[to] = t;
	}
}

void right_rotate(int *a, int num, int n)
{
	reverse(a, 1, n - num);
	reverse(a, n - num + 1, n);
	reverse(a, 1, n);
}

void perfect_shuffle3(int *a, int n)
{
	int n2, m, i, k, t;
	for (; n > 1;)
	{
		// step 1
		n2 = n * 2;
		for (k = 0, m = 1; n2 / m >= 3; ++k, m *= 3)
			;
		m /= 2;
		// 2m = 3^k - 1 , 3^k <= 2n < 3^(k + 1)

		// step 2
		right_rotate(a + m, m, n);

		// step 3
		for (i = 0, t = 1; i < k; ++i, t *= 3)
		{
			cycle_leader(a , t, m * 2 + 1);
		}

		//step 4
		a += m * 2;
		n -= m;

	}
	// n = 1
	t = a[1];
	a[1] = a[2];
	a[2] = t;
}

void shuffle(int *a, int n)
{
	int i, t, n2 = n * 2;
	perfect_shuffle3(a, n);
	for (i = 2; i <= n2; i += 2)
	{
		t = a[i - 1];
		a[i - 1] = a[i];
		a[i] = t;
	}
}

