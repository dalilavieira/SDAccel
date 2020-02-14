#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_1__ ;

/* Type definitions */
struct TYPE_8__ {int M11; double M12; double M21; int M22; double M31; double M32; } ;
typedef  TYPE_1__ uiDrawMatrix ;

/* Variables and functions */
 double tan (double) ; 
 int /*<<< orphan*/  uiDrawMatrixMultiply (TYPE_1__*,TYPE_1__*) ; 
 int /*<<< orphan*/  uiDrawMatrixTransformPoint (TYPE_1__*,double*,double*) ; 

void uiDrawMatrixSetIdentity(uiDrawMatrix *m)
{
	m->M11 = 1;
	m->M12 = 0;
	m->M21 = 0;
	m->M22 = 1;
	m->M31 = 0;
	m->M32 = 0;
}

void uiprivFallbackSkew(uiDrawMatrix *m, double x, double y, double xamount, double yamount)
{
	uiDrawMatrix n;

	uiDrawMatrixSetIdentity(&n);
	// TODO explain this
	n.M12 = tan(yamount);
	n.M21 = tan(xamount);
	n.M31 = -y * tan(xamount);
	n.M32 = -x * tan(yamount);
	uiDrawMatrixMultiply(m, &n);
}

void uiprivScaleCenter(double xCenter, double yCenter, double *x, double *y)
{
	*x = xCenter - (*x * xCenter);
	*y = yCenter - (*y * yCenter);
}

void uiprivFallbackTransformSize(uiDrawMatrix *m, double *x, double *y)
{
	uiDrawMatrix m2;

	m2 = *m;
	m2.M31 = 0;
	m2.M32 = 0;
	uiDrawMatrixTransformPoint(&m2, x, y);
}

