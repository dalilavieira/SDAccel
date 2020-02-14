#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_18__   TYPE_5__ ;
typedef  struct TYPE_17__   TYPE_4__ ;
typedef  struct TYPE_16__   TYPE_3__ ;
typedef  struct TYPE_15__   TYPE_2__ ;
typedef  struct TYPE_14__   TYPE_1__ ;

/* Type definitions */
struct TYPE_14__ {int numpoints; int /*<<< orphan*/ * p; } ;
typedef  TYPE_1__ winding_t ;
struct TYPE_15__ {size_t planenum; TYPE_3__* frontarea; struct TYPE_15__** next; TYPE_1__* winding; } ;
typedef  TYPE_2__ tmp_face_t ;
struct TYPE_16__ {struct TYPE_16__* l_next; TYPE_2__* tmpfaces; } ;
typedef  TYPE_3__ tmp_area_t ;
struct TYPE_17__ {int /*<<< orphan*/  dist; int /*<<< orphan*/  normal; } ;
typedef  TYPE_4__ plane_t ;
struct TYPE_18__ {TYPE_3__* areas; } ;

/* Variables and functions */
 TYPE_1__* AddWindingPoint (TYPE_1__*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  FreeWinding (TYPE_1__*) ; 
 int /*<<< orphan*/  Log_Write (char*,...) ; 
 scalar_t__ PointOnWinding (TYPE_1__*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int*) ; 
 TYPE_4__* mapplanes ; 
 int /*<<< orphan*/  qprintf (char*,...) ; 
 TYPE_5__ tmpaasworld ; 

int AAS_MeltFaceWinding(tmp_face_t *face1, tmp_face_t *face2)
{
	int i, n;
	int splits = 0;
	winding_t *w2, *neww;
	plane_t *plane1;

#ifdef DEBUG
	if (!face1->winding) Error("face1 %d without winding", face1->num);
	if (!face2->winding) Error("face2 %d without winding", face2->num);
#endif //DEBUG
	w2 = face2->winding;
	plane1 = &mapplanes[face1->planenum];
	for (i = 0; i < w2->numpoints; i++)
	{
		if (PointOnWinding(face1->winding, plane1->normal, plane1->dist, w2->p[i], &n))
		{
			neww = AddWindingPoint(face1->winding, w2->p[i], n);
			FreeWinding(face1->winding);
			face1->winding = neww;

			splits++;
		} //end if
	} //end for
	return splits;
}

int AAS_MeltFaceWindingsOfArea(tmp_area_t *tmparea)
{
	int side1, side2, num_windingsplits = 0;
	tmp_face_t *face1, *face2;

	for (face1 = tmparea->tmpfaces; face1; face1 = face1->next[side1])
	{
		side1 = face1->frontarea != tmparea;
		for (face2 = tmparea->tmpfaces; face2; face2 = face2->next[side2])
		{
			side2 = face2->frontarea != tmparea;
			if (face1 == face2) continue;
			num_windingsplits += AAS_MeltFaceWinding(face1, face2);
		} //end for
	} //end for
	return num_windingsplits;
}

void AAS_MeltAreaFaceWindings(void)
{
	tmp_area_t *tmparea;
	int num_windingsplits = 0;

	Log_Write("AAS_MeltAreaFaceWindings\r\n");
	qprintf("%6d edges melted", num_windingsplits);
	//NOTE: first convex area (zero) is a dummy
	for (tmparea = tmpaasworld.areas; tmparea; tmparea = tmparea->l_next)
	{
		num_windingsplits += AAS_MeltFaceWindingsOfArea(tmparea);
		qprintf("\r%6d", num_windingsplits);
	} //end for
	qprintf("\n");
	Log_Write("%6d edges melted\r\n", num_windingsplits);
}

