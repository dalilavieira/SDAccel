#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_20__   TYPE_6__ ;
typedef  struct TYPE_19__   TYPE_5__ ;
typedef  struct TYPE_18__   TYPE_4__ ;
typedef  struct TYPE_17__   TYPE_3__ ;
typedef  struct TYPE_16__   TYPE_1__ ;

/* Type definitions */
typedef  scalar_t__ uint8_t ;
typedef  int uint32_t ;
typedef  int /*<<< orphan*/  uiWindow ;
typedef  int /*<<< orphan*/  uiSpinbox ;
struct TYPE_16__ {int Thickness; int /*<<< orphan*/  MiterLimit; int /*<<< orphan*/  Join; int /*<<< orphan*/  Cap; } ;
typedef  TYPE_1__ uiInitOptions ;
typedef  TYPE_1__ uiDrawStrokeParams ;
typedef  int /*<<< orphan*/  uiDrawPath ;
typedef  int /*<<< orphan*/  uiDrawMatrix ;
struct TYPE_17__ {double R; double G; double B; double A; void* Type; } ;
typedef  TYPE_3__ uiDrawBrush ;
typedef  int /*<<< orphan*/  uiColorButton ;
typedef  int /*<<< orphan*/  uiBox ;
struct TYPE_18__ {double AreaWidth; double AreaHeight; double X; double Y; } ;
typedef  TYPE_4__ uiAreaMouseEvent ;
typedef  int /*<<< orphan*/  uiAreaKeyEvent ;
typedef  int /*<<< orphan*/  uiAreaHandler ;
struct TYPE_19__ {double AreaWidth; double AreaHeight; int /*<<< orphan*/  Context; } ;
typedef  TYPE_5__ uiAreaDrawParams ;
typedef  int /*<<< orphan*/  uiArea ;
struct TYPE_20__ {void (* Draw ) (int /*<<< orphan*/ *,int /*<<< orphan*/ *,TYPE_5__*) ;void (* MouseEvent ) (int /*<<< orphan*/ *,int /*<<< orphan*/ *,TYPE_4__*) ;void (* MouseCrossed ) (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int) ;void (* DragBroken ) (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ;int (* KeyEvent ) (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ;} ;

/* Variables and functions */
 int colorBlack ; 
 int /*<<< orphan*/ * colorButton ; 
 int colorDodgerBlue ; 
 int colorWhite ; 
 int currentPoint ; 
 int /*<<< orphan*/ ** datapoints ; 
 int /*<<< orphan*/  fprintf (int /*<<< orphan*/ ,char*,char const*) ; 
 TYPE_6__ handler ; 
 int /*<<< orphan*/ * histogram ; 
 int /*<<< orphan*/ * mainwin ; 
 int /*<<< orphan*/  memset (TYPE_1__*,int /*<<< orphan*/ ,int) ; 
 double pointRadius ; 
 int rand () ; 
 int /*<<< orphan*/  srand (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stderr ; 
 int /*<<< orphan*/  time (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  uiAreaQueueRedrawAll (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  uiBoxAppend (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  uiBoxSetPadded (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  uiColorButtonColor (int /*<<< orphan*/ *,double*,double*,double*,double*) ; 
 int /*<<< orphan*/  uiColorButtonOnChanged (int /*<<< orphan*/ *,void (*) (int /*<<< orphan*/ *,void*),int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  uiColorButtonSetColor (int /*<<< orphan*/ *,double,double,double,double) ; 
 int /*<<< orphan*/  uiControl (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  uiControlDestroy (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  uiControlShow (int /*<<< orphan*/ ) ; 
 void* uiDrawBrushTypeSolid ; 
 int /*<<< orphan*/  uiDrawDefaultMiterLimit ; 
 int /*<<< orphan*/  uiDrawFill (int /*<<< orphan*/ ,int /*<<< orphan*/ *,TYPE_3__*) ; 
 int /*<<< orphan*/  uiDrawFillModeWinding ; 
 int /*<<< orphan*/  uiDrawFreePath (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  uiDrawLineCapFlat ; 
 int /*<<< orphan*/  uiDrawLineJoinMiter ; 
 int /*<<< orphan*/  uiDrawMatrixSetIdentity (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  uiDrawMatrixTranslate (int /*<<< orphan*/ *,double,double) ; 
 int /*<<< orphan*/ * uiDrawNewPath (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  uiDrawPathAddRectangle (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ,double,double) ; 
 int /*<<< orphan*/  uiDrawPathCloseFigure (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  uiDrawPathEnd (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  uiDrawPathLineTo (int /*<<< orphan*/ *,double,double) ; 
 int /*<<< orphan*/  uiDrawPathNewFigure (int /*<<< orphan*/ *,double,double) ; 
 int /*<<< orphan*/  uiDrawPathNewFigureWithArc (int /*<<< orphan*/ *,double,double,double,int /*<<< orphan*/ ,double,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  uiDrawStroke (int /*<<< orphan*/ ,int /*<<< orphan*/ *,TYPE_3__*,TYPE_1__*) ; 
 int /*<<< orphan*/  uiDrawTransform (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  uiFreeInitError (char const*) ; 
 char* uiInit (TYPE_1__*) ; 
 int /*<<< orphan*/  uiMain () ; 
 int /*<<< orphan*/ * uiNewArea (TYPE_6__*) ; 
 int /*<<< orphan*/ * uiNewColorButton () ; 
 int /*<<< orphan*/ * uiNewHorizontalBox () ; 
 int /*<<< orphan*/ * uiNewSpinbox (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/ * uiNewVerticalBox () ; 
 int /*<<< orphan*/ * uiNewWindow (char*,int,int,int) ; 
 int /*<<< orphan*/  uiOnShouldQuit (int (*) (void*),int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  uiQuit () ; 
 int /*<<< orphan*/  uiSpinboxOnChanged (int /*<<< orphan*/ *,void (*) (int /*<<< orphan*/ *,void*),int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  uiSpinboxSetValue (int /*<<< orphan*/ *,int) ; 
 int uiSpinboxValue (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  uiUninit () ; 
 int /*<<< orphan*/  uiWindowOnClosing (int /*<<< orphan*/ *,int (*) (int /*<<< orphan*/ *,void*),int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  uiWindowSetChild (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  uiWindowSetMargined (int /*<<< orphan*/ *,int) ; 
 double xoffLeft ; 
 double xoffRight ; 
 double yoffBottom ; 
 double yoffTop ; 

__attribute__((used)) static void setSolidBrush(uiDrawBrush *brush, uint32_t color, double alpha)
{
	uint8_t component;

	brush->Type = uiDrawBrushTypeSolid;
	component = (uint8_t) ((color >> 16) & 0xFF);
	brush->R = ((double) component) / 255;
	component = (uint8_t) ((color >> 8) & 0xFF);
	brush->G = ((double) component) / 255;
	component = (uint8_t) (color & 0xFF);
	brush->B = ((double) component) / 255;
	brush->A = alpha;
}

__attribute__((used)) static void pointLocations(double width, double height, double *xs, double *ys)
{
	double xincr, yincr;
	int i, n;

	xincr = width / 9;		// 10 - 1 to make the last point be at the end
	yincr = height / 100;

	for (i = 0; i < 10; i++) {
		// get the value of the point
		n = uiSpinboxValue(datapoints[i]);
		// because y=0 is the top but n=0 is the bottom, we need to flip
		n = 100 - n;
		xs[i] = xincr * i;
		ys[i] = yincr * n;
	}
}

__attribute__((used)) static uiDrawPath *constructGraph(double width, double height, int extend)
{
	uiDrawPath *path;
	double xs[10], ys[10];
	int i;

	pointLocations(width, height, xs, ys);

	path = uiDrawNewPath(uiDrawFillModeWinding);

	uiDrawPathNewFigure(path, xs[0], ys[0]);
	for (i = 1; i < 10; i++)
		uiDrawPathLineTo(path, xs[i], ys[i]);

	if (extend) {
		uiDrawPathLineTo(path, width, height);
		uiDrawPathLineTo(path, 0, height);
		uiDrawPathCloseFigure(path);
	}

	uiDrawPathEnd(path);
	return path;
}

__attribute__((used)) static void graphSize(double clientWidth, double clientHeight, double *graphWidth, double *graphHeight)
{
	*graphWidth = clientWidth - xoffLeft - xoffRight;
	*graphHeight = clientHeight - yoffTop - yoffBottom;
}

__attribute__((used)) static void handlerDraw(uiAreaHandler *a, uiArea *area, uiAreaDrawParams *p)
{
	uiDrawPath *path;
	uiDrawBrush brush;
	uiDrawStrokeParams sp;
	uiDrawMatrix m;
	double graphWidth, graphHeight;
	double graphR, graphG, graphB, graphA;

	// fill the area with white
	setSolidBrush(&brush, colorWhite, 1.0);
	path = uiDrawNewPath(uiDrawFillModeWinding);
	uiDrawPathAddRectangle(path, 0, 0, p->AreaWidth, p->AreaHeight);
	uiDrawPathEnd(path);
	uiDrawFill(p->Context, path, &brush);
	uiDrawFreePath(path);

	// figure out dimensions
	graphSize(p->AreaWidth, p->AreaHeight, &graphWidth, &graphHeight);

	// clear sp to avoid passing garbage to uiDrawStroke()
	// for example, we don't use dashing
	memset(&sp, 0, sizeof (uiDrawStrokeParams));

	// make a stroke for both the axes and the histogram line
	sp.Cap = uiDrawLineCapFlat;
	sp.Join = uiDrawLineJoinMiter;
	sp.Thickness = 2;
	sp.MiterLimit = uiDrawDefaultMiterLimit;

	// draw the axes
	setSolidBrush(&brush, colorBlack, 1.0);
	path = uiDrawNewPath(uiDrawFillModeWinding);
	uiDrawPathNewFigure(path,
		xoffLeft, yoffTop);
	uiDrawPathLineTo(path,
		xoffLeft, yoffTop + graphHeight);
	uiDrawPathLineTo(path,
		xoffLeft + graphWidth, yoffTop + graphHeight);
	uiDrawPathEnd(path);
	uiDrawStroke(p->Context, path, &brush, &sp);
	uiDrawFreePath(path);

	// now transform the coordinate space so (0, 0) is the top-left corner of the graph
	uiDrawMatrixSetIdentity(&m);
	uiDrawMatrixTranslate(&m, xoffLeft, yoffTop);
	uiDrawTransform(p->Context, &m);

	// now get the color for the graph itself and set up the brush
	uiColorButtonColor(colorButton, &graphR, &graphG, &graphB, &graphA);
	brush.Type = uiDrawBrushTypeSolid;
	brush.R = graphR;
	brush.G = graphG;
	brush.B = graphB;
	// we set brush->A below to different values for the fill and stroke

	// now create the fill for the graph below the graph line
	path = constructGraph(graphWidth, graphHeight, 1);
	brush.A = graphA / 2;
	uiDrawFill(p->Context, path, &brush);
	uiDrawFreePath(path);

	// now draw the histogram line
	path = constructGraph(graphWidth, graphHeight, 0);
	brush.A = graphA;
	uiDrawStroke(p->Context, path, &brush, &sp);
	uiDrawFreePath(path);

	// now draw the point being hovered over
	if (currentPoint != -1) {
		double xs[10], ys[10];

		pointLocations(graphWidth, graphHeight, xs, ys);
		path = uiDrawNewPath(uiDrawFillModeWinding);
		uiDrawPathNewFigureWithArc(path,
			xs[currentPoint], ys[currentPoint],
			pointRadius,
			0, 6.23,		// TODO pi
			0);
		uiDrawPathEnd(path);
		// use the same brush as for the histogram lines
		uiDrawFill(p->Context, path, &brush);
		uiDrawFreePath(path);
	}
}

__attribute__((used)) static int inPoint(double x, double y, double xtest, double ytest)
{
	// TODO switch to using a matrix
	x -= xoffLeft;
	y -= yoffTop;
	return (x >= xtest - pointRadius) &&
		(x <= xtest + pointRadius) &&
		(y >= ytest - pointRadius) &&
		(y <= ytest + pointRadius);
}

__attribute__((used)) static void handlerMouseEvent(uiAreaHandler *a, uiArea *area, uiAreaMouseEvent *e)
{
	double graphWidth, graphHeight;
	double xs[10], ys[10];
	int i;

	graphSize(e->AreaWidth, e->AreaHeight, &graphWidth, &graphHeight);
	pointLocations(graphWidth, graphHeight, xs, ys);

	for (i = 0; i < 10; i++)
		if (inPoint(e->X, e->Y, xs[i], ys[i]))
			break;
	if (i == 10)		// not in a point
		i = -1;

	currentPoint = i;
	// TODO only redraw the relevant area
	uiAreaQueueRedrawAll(histogram);
}

__attribute__((used)) static void handlerMouseCrossed(uiAreaHandler *ah, uiArea *a, int left)
{
	// do nothing
}

__attribute__((used)) static void handlerDragBroken(uiAreaHandler *ah, uiArea *a)
{
	// do nothing
}

__attribute__((used)) static int handlerKeyEvent(uiAreaHandler *ah, uiArea *a, uiAreaKeyEvent *e)
{
	// reject all keys
	return 0;
}

__attribute__((used)) static void onDatapointChanged(uiSpinbox *s, void *data)
{
	uiAreaQueueRedrawAll(histogram);
}

__attribute__((used)) static void onColorChanged(uiColorButton *b, void *data)
{
	uiAreaQueueRedrawAll(histogram);
}

__attribute__((used)) static int onClosing(uiWindow *w, void *data)
{
	uiControlDestroy(uiControl(mainwin));
	uiQuit();
	return 0;
}

__attribute__((used)) static int shouldQuit(void *data)
{
	uiControlDestroy(uiControl(mainwin));
	return 1;
}

int main(void)
{
	uiInitOptions o;
	const char *err;
	uiBox *hbox, *vbox;
	int i;
	uiDrawBrush brush;

	handler.Draw = handlerDraw;
	handler.MouseEvent = handlerMouseEvent;
	handler.MouseCrossed = handlerMouseCrossed;
	handler.DragBroken = handlerDragBroken;
	handler.KeyEvent = handlerKeyEvent;

	memset(&o, 0, sizeof (uiInitOptions));
	err = uiInit(&o);
	if (err != NULL) {
		fprintf(stderr, "error initializing ui: %s\n", err);
		uiFreeInitError(err);
		return 1;
	}

	uiOnShouldQuit(shouldQuit, NULL);

	mainwin = uiNewWindow("libui Histogram Example", 640, 480, 1);
	uiWindowSetMargined(mainwin, 1);
	uiWindowOnClosing(mainwin, onClosing, NULL);

	hbox = uiNewHorizontalBox();
	uiBoxSetPadded(hbox, 1);
	uiWindowSetChild(mainwin, uiControl(hbox));

	vbox = uiNewVerticalBox();
	uiBoxSetPadded(vbox, 1);
	uiBoxAppend(hbox, uiControl(vbox), 0);

	srand(time(NULL));
	for (i = 0; i < 10; i++) {
		datapoints[i] = uiNewSpinbox(0, 100);
		uiSpinboxSetValue(datapoints[i], rand() % 101);
		uiSpinboxOnChanged(datapoints[i], onDatapointChanged, NULL);
		uiBoxAppend(vbox, uiControl(datapoints[i]), 0);
	}

	colorButton = uiNewColorButton();
	// TODO inline these
	setSolidBrush(&brush, colorDodgerBlue, 1.0);
	uiColorButtonSetColor(colorButton,
		brush.R,
		brush.G,
		brush.B,
		brush.A);
	uiColorButtonOnChanged(colorButton, onColorChanged, NULL);
	uiBoxAppend(vbox, uiControl(colorButton), 0);

	histogram = uiNewArea(&handler);
	uiBoxAppend(hbox, uiControl(histogram), 1);

	uiControlShow(uiControl(mainwin));
	uiMain();
	uiUninit();
	return 0;
}

