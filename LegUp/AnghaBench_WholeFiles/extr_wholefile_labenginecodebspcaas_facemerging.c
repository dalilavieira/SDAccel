#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_15__   TYPE_4__ ;
typedef  struct TYPE_14__   TYPE_3__ ;
typedef  struct TYPE_13__   TYPE_2__ ;
typedef  struct TYPE_12__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  winding_t ;
struct TYPE_12__ {scalar_t__ faceflags; scalar_t__ frontarea; scalar_t__ backarea; size_t planenum; struct TYPE_12__** next; int /*<<< orphan*/ * winding; int /*<<< orphan*/  num; } ;
typedef  TYPE_1__ tmp_face_t ;
struct TYPE_13__ {TYPE_1__* tmpfaces; scalar_t__ invalid; struct TYPE_13__* l_next; } ;
typedef  TYPE_2__ tmp_area_t ;
struct TYPE_15__ {int /*<<< orphan*/  normal; } ;
struct TYPE_14__ {TYPE_2__* areas; } ;

/* Variables and functions */
 int /*<<< orphan*/  AAS_CheckArea (TYPE_2__*) ; 
 int /*<<< orphan*/  AAS_FreeTmpFace (TYPE_1__*) ; 
 int /*<<< orphan*/  AAS_RemoveFaceFromArea (TYPE_1__*,scalar_t__) ; 
 int /*<<< orphan*/  FreeWinding (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  Log_Write (char*,...) ; 
 int /*<<< orphan*/ * MergeWindings (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * TryMergeWinding (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 TYPE_4__* mapplanes ; 
 int /*<<< orphan*/  qprintf (char*,...) ; 
 TYPE_3__ tmpaasworld ; 

int AAS_TryMergeFaces(tmp_face_t *face1, tmp_face_t *face2)
{
	winding_t *neww;

#ifdef DEBUG
	if (!face1->winding) Error("face1 %d without winding", face1->num);
	if (!face2->winding) Error("face2 %d without winding", face2->num);
#endif //DEBUG
	//
	if (face1->faceflags != face2->faceflags) return false;
	//NOTE: if the front or back area is zero this doesn't mean there's
	//a real area. It means there's solid at that side of the face
	//if both faces have the same front area
	if (face1->frontarea == face2->frontarea)
	{
		//if both faces have the same back area
		if (face1->backarea == face2->backarea)
		{
			//if the faces are in the same plane
			if (face1->planenum == face2->planenum)
			{
				//if they have both a front and a back area (no solid on either side)
				if (face1->frontarea && face1->backarea)
				{
					neww = MergeWindings(face1->winding, face2->winding,
								mapplanes[face1->planenum].normal);
				} //end if
				else
				{
					//this function is to be found in l_poly.c
					neww = TryMergeWinding(face1->winding, face2->winding,
									mapplanes[face1->planenum].normal);
				} //end else
				if (neww)
				{
					FreeWinding(face1->winding);
					face1->winding = neww;
					if (face2->frontarea) AAS_RemoveFaceFromArea(face2, face2->frontarea);
					if (face2->backarea) AAS_RemoveFaceFromArea(face2, face2->backarea);
					AAS_FreeTmpFace(face2);
					return true;
				} //end if
			} //end if
			else if ((face1->planenum & ~1) == (face2->planenum & ~1))
			{
				Log_Write("face %d and %d, same front and back area but flipped planes\r\n",
							face1->num, face2->num);
			} //end if
		} //end if
	} //end if
	return false;
}

void AAS_MergeAreaFaces(void)
{
	int num_facemerges = 0;
	int side1, side2, restart;
	tmp_area_t *tmparea, *lasttmparea;
	tmp_face_t *face1, *face2;

	Log_Write("AAS_MergeAreaFaces\r\n");
	qprintf("%6d face merges", num_facemerges);
	//NOTE: first convex area is a dummy
	lasttmparea = tmpaasworld.areas;
	for (tmparea = tmpaasworld.areas; tmparea; tmparea = tmparea->l_next)
	{
		restart = false;
		//
		if (tmparea->invalid) continue;
		//
		for (face1 = tmparea->tmpfaces; face1; face1 = face1->next[side1])
		{
			side1 = face1->frontarea != tmparea;
			for (face2 = face1->next[side1]; face2; face2 = face2->next[side2])
			{
				side2 = face2->frontarea != tmparea;
				//if succesfully merged
				if (AAS_TryMergeFaces(face1, face2))
				{
					//start over again after merging two faces
					restart = true;
					num_facemerges++;
					qprintf("\r%6d", num_facemerges);
					AAS_CheckArea(tmparea);
					break;
				} //end if
			} //end for
			if (restart)
			{
				tmparea = lasttmparea;
				break;
			} //end if
		} //end for
		lasttmparea = tmparea;
	} //end for
	qprintf("\n");
	Log_Write("%6d face merges\r\n", num_facemerges);
}

void AAS_MergePlaneFaces(tmp_area_t *tmparea, int planenum)
{
	tmp_face_t *face1, *face2, *nextface2;
	winding_t *neww;
	int side1, side2;

	for (face1 = tmparea->tmpfaces; face1; face1 = face1->next[side1])
	{
		side1 = face1->frontarea != tmparea;
		if (face1->planenum != planenum) continue;
		//
		for (face2 = face1->next[side1]; face2; face2 = nextface2)
		{
			side2 = face2->frontarea != tmparea;
			nextface2 = face2->next[side2];
			//
			if ((face2->planenum & ~1) != (planenum & ~1)) continue;
			//
			neww = MergeWindings(face1->winding, face2->winding,
								mapplanes[face1->planenum].normal);
			FreeWinding(face1->winding);
			face1->winding = neww;
			if (face2->frontarea) AAS_RemoveFaceFromArea(face2, face2->frontarea);
			if (face2->backarea) AAS_RemoveFaceFromArea(face2, face2->backarea);
			AAS_FreeTmpFace(face2);
			//
			nextface2 = face1->next[side1];
		} //end for
	} //end for
}

int AAS_CanMergePlaneFaces(tmp_area_t *tmparea, int planenum)
{
	tmp_area_t *frontarea, *backarea;
	tmp_face_t *face1;
	int side1, merge, faceflags;

	frontarea = backarea = NULL;
	merge = false;
	for (face1 = tmparea->tmpfaces; face1; face1 = face1->next[side1])
	{
		side1 = face1->frontarea != tmparea;
		if ((face1->planenum & ~1) != (planenum & ~1)) continue;
		if (!frontarea && !backarea)
		{
			frontarea = face1->frontarea;
			backarea = face1->backarea;
			faceflags = face1->faceflags;
		} //end if
		else
		{
			if (frontarea != face1->frontarea) return false;
			if (backarea != face1->backarea) return false;
			if (faceflags != face1->faceflags) return false;
			merge = true;
		} //end else
	} //end for
	return merge;
}

void AAS_MergeAreaPlaneFaces(void)
{
	int num_facemerges = 0;
	int side1;
	tmp_area_t *tmparea, *nexttmparea;
	tmp_face_t *face1;

	Log_Write("AAS_MergePlaneFaces\r\n");
	qprintf("%6d plane face merges", num_facemerges);
	//NOTE: first convex area is a dummy
	for (tmparea = tmpaasworld.areas; tmparea; tmparea = nexttmparea)
	{
		nexttmparea = tmparea->l_next;
		//
		if (tmparea->invalid) continue;
		//
		for (face1 = tmparea->tmpfaces; face1; face1 = face1->next[side1])
		{
			side1 = face1->frontarea != tmparea;
			//
			if (AAS_CanMergePlaneFaces(tmparea, face1->planenum))
			{
				AAS_MergePlaneFaces(tmparea, face1->planenum);
				nexttmparea = tmparea;
				num_facemerges++;
				qprintf("\r%6d", num_facemerges);
				break;
			} //end if
		} //end for
	} //end for
	qprintf("\n");
	Log_Write("%6d plane face merges\r\n", num_facemerges);
}

