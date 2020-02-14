#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_30__   TYPE_2__ ;
typedef  struct TYPE_29__   TYPE_1__ ;

/* Type definitions */
struct TYPE_29__ {int /*<<< orphan*/  M32; int /*<<< orphan*/  M31; int /*<<< orphan*/  M22; int /*<<< orphan*/  M21; int /*<<< orphan*/  M12; int /*<<< orphan*/  M11; } ;
typedef  TYPE_1__ uiDrawMatrix ;
struct TYPE_30__ {int /*<<< orphan*/  y0; int /*<<< orphan*/  x0; int /*<<< orphan*/  yy; int /*<<< orphan*/  xy; int /*<<< orphan*/  yx; int /*<<< orphan*/  xx; } ;
typedef  TYPE_2__ cairo_matrix_t ;

/* Variables and functions */
 scalar_t__ CAIRO_STATUS_SUCCESS ; 
 scalar_t__ cairo_matrix_invert (TYPE_2__*) ; 
 int /*<<< orphan*/  cairo_matrix_multiply (TYPE_2__*,TYPE_2__*,TYPE_2__*) ; 
 int /*<<< orphan*/  cairo_matrix_rotate (TYPE_2__*,double) ; 
 int /*<<< orphan*/  cairo_matrix_scale (TYPE_2__*,double,double) ; 
 int /*<<< orphan*/  cairo_matrix_transform_distance (TYPE_2__*,double*,double*) ; 
 int /*<<< orphan*/  cairo_matrix_transform_point (TYPE_2__*,double*,double*) ; 
 int /*<<< orphan*/  cairo_matrix_translate (TYPE_2__*,double,double) ; 
 int /*<<< orphan*/  uiprivFallbackSkew (TYPE_1__*,double,double,double,double) ; 
 int /*<<< orphan*/  uiprivScaleCenter (double,double,double*,double*) ; 

__attribute__((used)) static void m2c(uiDrawMatrix *m, cairo_matrix_t *c)
{
	c->xx = m->M11;
	c->yx = m->M12;
	c->xy = m->M21;
	c->yy = m->M22;
	c->x0 = m->M31;
	c->y0 = m->M32;
}

void uiprivM2C(uiDrawMatrix *m, cairo_matrix_t *c)
{
	m2c(m, c);
}

__attribute__((used)) static void c2m(cairo_matrix_t *c, uiDrawMatrix *m)
{
	m->M11 = c->xx;
	m->M12 = c->yx;
	m->M21 = c->xy;
	m->M22 = c->yy;
	m->M31 = c->x0;
	m->M32 = c->y0;
}

void uiDrawMatrixTranslate(uiDrawMatrix *m, double x, double y)
{
	cairo_matrix_t c;

	m2c(m, &c);
	cairo_matrix_translate(&c, x, y);
	c2m(&c, m);
}

void uiDrawMatrixScale(uiDrawMatrix *m, double xCenter, double yCenter, double x, double y)
{
	cairo_matrix_t c;
	double xt, yt;

	m2c(m, &c);
	xt = x;
	yt = y;
	uiprivScaleCenter(xCenter, yCenter, &xt, &yt);
	cairo_matrix_translate(&c, xt, yt);
	cairo_matrix_scale(&c, x, y);
	cairo_matrix_translate(&c, -xt, -yt);
	c2m(&c, m);
}

void uiDrawMatrixRotate(uiDrawMatrix *m, double x, double y, double amount)
{
	cairo_matrix_t c;

	m2c(m, &c);
	cairo_matrix_translate(&c, x, y);
	cairo_matrix_rotate(&c, amount);
	cairo_matrix_translate(&c, -x, -y);
	c2m(&c, m);
}

void uiDrawMatrixSkew(uiDrawMatrix *m, double x, double y, double xamount, double yamount)
{
	uiprivFallbackSkew(m, x, y, xamount, yamount);
}

void uiDrawMatrixMultiply(uiDrawMatrix *dest, uiDrawMatrix *src)
{
	cairo_matrix_t c;
	cairo_matrix_t d;

	m2c(dest, &c);
	m2c(src, &d);
	cairo_matrix_multiply(&c, &c, &d);
	c2m(&c, dest);
}

int uiDrawMatrixInvertible(uiDrawMatrix *m)
{
	cairo_matrix_t c;

	m2c(m, &c);
	return cairo_matrix_invert(&c) == CAIRO_STATUS_SUCCESS;
}

int uiDrawMatrixInvert(uiDrawMatrix *m)
{
	cairo_matrix_t c;

	m2c(m, &c);
	if (cairo_matrix_invert(&c) != CAIRO_STATUS_SUCCESS)
		return 0;
	c2m(&c, m);
	return 1;
}

void uiDrawMatrixTransformPoint(uiDrawMatrix *m, double *x, double *y)
{
	cairo_matrix_t c;

	m2c(m, &c);
	cairo_matrix_transform_point(&c, x, y);
}

void uiDrawMatrixTransformSize(uiDrawMatrix *m, double *x, double *y)
{
	cairo_matrix_t c;

	m2c(m, &c);
	cairo_matrix_transform_distance(&c, x, y);
}

