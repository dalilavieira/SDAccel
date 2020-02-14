#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_54__   TYPE_9__ ;
typedef  struct TYPE_53__   TYPE_8__ ;
typedef  struct TYPE_52__   TYPE_7__ ;
typedef  struct TYPE_51__   TYPE_6__ ;
typedef  struct TYPE_50__   TYPE_5__ ;
typedef  struct TYPE_49__   TYPE_4__ ;
typedef  struct TYPE_48__   TYPE_3__ ;
typedef  struct TYPE_47__   TYPE_33__ ;
typedef  struct TYPE_46__   TYPE_2__ ;
typedef  struct TYPE_45__   TYPE_1__ ;
typedef  struct TYPE_44__   TYPE_15__ ;
typedef  struct TYPE_43__   TYPE_12__ ;
typedef  struct TYPE_42__   TYPE_11__ ;
typedef  struct TYPE_41__   TYPE_10__ ;

/* Type definitions */
typedef  int dwOutsideConeAngle ;
struct TYPE_54__ {double x; double y; double z; } ;
struct TYPE_53__ {double x; double y; double z; } ;
struct TYPE_52__ {double x; double y; double z; } ;
struct TYPE_51__ {double x; double y; double z; } ;
struct TYPE_44__ {int x; int y; int z; } ;
struct TYPE_49__ {double x; double y; double z; } ;
struct TYPE_50__ {int dwMode; int flMaxDistance; int flMinDistance; int dwInsideConeAngle; int dwOutsideConeAngle; int lConeOutsideVolume; int dwSize; TYPE_15__ vConeOrientation; TYPE_4__ vVelocity; TYPE_15__ vPosition; } ;
struct TYPE_46__ {TYPE_15__ vOrientTop; TYPE_15__ vOrientFront; TYPE_15__ vPosition; } ;
struct TYPE_48__ {TYPE_2__ ds3dl; } ;
struct TYPE_47__ {int lVolume; int lPan; } ;
struct TYPE_45__ {int dwFlags; } ;
struct TYPE_43__ {TYPE_11__* device; int /*<<< orphan*/ * lpVtbl; scalar_t__ ref; TYPE_11__* dsb; } ;
struct TYPE_41__ {int dwSize; int /*<<< orphan*/  flDopplerFactor; int /*<<< orphan*/  flRolloffFactor; int /*<<< orphan*/  flDistanceFactor; TYPE_9__ vOrientTop; TYPE_8__ vOrientFront; TYPE_7__ vVelocity; TYPE_6__ vPosition; } ;
struct TYPE_42__ {int ds3db_lVolume; int nrofbuffers; void* ds3dl_need_recalc; TYPE_10__ ds3dl; void* ds3db_need_recalc; TYPE_5__ ds3db_ds3db; struct TYPE_42__** buffers; TYPE_33__ volpan; TYPE_3__* device; TYPE_1__ dsbd; } ;
typedef  int /*<<< orphan*/  LPDIRECTSOUND3DBUFFER ;
typedef  TYPE_11__ IDirectSoundBufferImpl ;
typedef  TYPE_12__ IDirectSound3DListenerImpl ;
typedef  TYPE_12__ IDirectSound3DBufferImpl ;
typedef  int /*<<< orphan*/  HRESULT ;
typedef  TYPE_11__ DirectSoundDevice ;
typedef  int DWORD ;
typedef  int /*<<< orphan*/  DS3DLISTENER ;
typedef  int /*<<< orphan*/  DS3DBUFFER ;
typedef  TYPE_15__ D3DVECTOR ;
typedef  int D3DVALUE ;

/* Variables and functions */
#define  DS3DMODE_DISABLE 130 
#define  DS3DMODE_HEADRELATIVE 129 
#define  DS3DMODE_NORMAL 128 
 void* DS3D_DEFAULTCONEANGLE ; 
 int DS3D_DEFAULTCONEOUTSIDEVOLUME ; 
 int /*<<< orphan*/  DS3D_DEFAULTDISTANCEFACTOR ; 
 int /*<<< orphan*/  DS3D_DEFAULTDOPPLERFACTOR ; 
 int DS3D_DEFAULTMAXDISTANCE ; 
 int DS3D_DEFAULTMINDISTANCE ; 
 int /*<<< orphan*/  DS3D_DEFAULTROLLOFFFACTOR ; 
 int DSBCAPS_MUTE3DATMAXDISTANCE ; 
 int DSBVOLUME_MIN ; 
 int /*<<< orphan*/  DSERR_OUTOFMEMORY ; 
 int /*<<< orphan*/  DSOUND_RecalcVolPan (TYPE_33__*) ; 
 int /*<<< orphan*/  GetProcessHeap () ; 
 int /*<<< orphan*/  HEAP_ZERO_MEMORY ; 
 TYPE_12__* HeapAlloc (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 scalar_t__ IDirectSound3DBufferImpl_Release (int /*<<< orphan*/ ) ; 
 int M_PI ; 
 int /*<<< orphan*/  S_OK ; 
 int /*<<< orphan*/  TRACE (char*,...) ; 
 void* TRUE ; 
 int /*<<< orphan*/  WARN (char*) ; 
 int acos (int) ; 
 int /*<<< orphan*/  ds3dbvt ; 
 int /*<<< orphan*/  ds3dlvt ; 
 int log10 (int) ; 
 int sqrt (int) ; 

__attribute__((used)) static inline D3DVALUE ScalarProduct (const D3DVECTOR *a, const D3DVECTOR *b)
{
	D3DVALUE c;
	c = (a->x*b->x) + (a->y*b->y) + (a->z*b->z);
	TRACE("(%f,%f,%f) * (%f,%f,%f) = %f)\n", a->x, a->y, a->z, b->x, b->y,
	      b->z, c);
	return c;
}

__attribute__((used)) static inline D3DVECTOR VectorProduct (const D3DVECTOR *a, const D3DVECTOR *b)
{
	D3DVECTOR c;
	c.x = (a->y*b->z) - (a->z*b->y);
	c.y = (a->z*b->x) - (a->x*b->z);
	c.z = (a->x*b->y) - (a->y*b->x);
	TRACE("(%f,%f,%f) x (%f,%f,%f) = (%f,%f,%f)\n", a->x, a->y, a->z, b->x, b->y,
	      b->z, c.x, c.y, c.z);
	return c;
}

__attribute__((used)) static inline D3DVALUE VectorMagnitude (const D3DVECTOR *a)
{
	D3DVALUE l;
	l = sqrt (ScalarProduct (a, a));
	TRACE("|(%f,%f,%f)| = %f\n", a->x, a->y, a->z, l);
	return l;
}

__attribute__((used)) static inline D3DVALUE RadToDeg (D3DVALUE angle)
{
	D3DVALUE newangle;
	newangle = angle * (360/(2*M_PI));
	TRACE("%f rad = %f deg\n", angle, newangle);
	return newangle;
}

__attribute__((used)) static inline D3DVALUE AngleBetweenVectorsRad (const D3DVECTOR *a, const D3DVECTOR *b)
{
	D3DVALUE la, lb, product, angle, cos;
	/* definition of scalar product: a*b = |a|*|b|*cos... therefore: */
	product = ScalarProduct (a,b);
	la = VectorMagnitude (a);
	lb = VectorMagnitude (b);
	if (!la || !lb)
		return 0;

	cos = product/(la*lb);
	angle = acos(cos);
	TRACE("angle between (%f,%f,%f) and (%f,%f,%f) = %f radians (%f degrees)\n",  a->x, a->y, a->z, b->x,
	      b->y, b->z, angle, RadToDeg(angle));
	return angle;	
}

__attribute__((used)) static inline D3DVALUE AngleBetweenVectorsDeg (const D3DVECTOR *a, const D3DVECTOR *b)
{
	return RadToDeg(AngleBetweenVectorsRad(a, b));
}

__attribute__((used)) static inline D3DVECTOR VectorBetweenTwoPoints (const D3DVECTOR *a, const D3DVECTOR *b)
{
	D3DVECTOR c;
	c.x = b->x - a->x;
	c.y = b->y - a->y;
	c.z = b->z - a->z;
	TRACE("A (%f,%f,%f), B (%f,%f,%f), AB = (%f,%f,%f)\n", a->x, a->y, a->z, b->x, b->y,
	      b->z, c.x, c.y, c.z);
	return c;
}

__attribute__((used)) static inline D3DVALUE ProjectVector (const D3DVECTOR *a, const D3DVECTOR *p)
{
	D3DVALUE prod, result;
	prod = ScalarProduct(a, p);
	result = prod/VectorMagnitude(p);
	TRACE("length projection of (%f,%f,%f) on (%f,%f,%f) = %f\n", a->x, a->y, a->z, p->x,
              p->y, p->z, result);
	return result;
}

void DSOUND_Calc3DBuffer(IDirectSoundBufferImpl *dsb)
{
	/* volume, at which the sound will be played after all calcs. */
	D3DVALUE lVolume = 0;
	/* stuff for distance related stuff calc. */
	D3DVECTOR vDistance;
	D3DVALUE flDistance = 0;
	/* panning related stuff */
	D3DVALUE flAngle;
	D3DVECTOR vLeft;
	/* doppler shift related stuff */
#if 0
	D3DVALUE flFreq, flBufferVel, flListenerVel;
#endif

	TRACE("(%p)\n",dsb);

	/* initial buffer volume */
	lVolume = dsb->ds3db_lVolume;
	
	switch (dsb->ds3db_ds3db.dwMode)
	{
		case DS3DMODE_DISABLE:
			TRACE("3D processing disabled\n");
			/* this one is here only to eliminate annoying warning message */
			DSOUND_RecalcVolPan (&dsb->volpan);
			break;
		case DS3DMODE_NORMAL:
			TRACE("Normal 3D processing mode\n");
			/* we need to calculate distance between buffer and listener*/
			vDistance = VectorBetweenTwoPoints(&dsb->ds3db_ds3db.vPosition, &dsb->device->ds3dl.vPosition);
			flDistance = VectorMagnitude (&vDistance);
			break;
		case DS3DMODE_HEADRELATIVE:
			TRACE("Head-relative 3D processing mode\n");
			/* distance between buffer and listener is same as buffer's position */
			flDistance = VectorMagnitude (&dsb->ds3db_ds3db.vPosition);
			break;
	}
	
	if (flDistance > dsb->ds3db_ds3db.flMaxDistance)
	{
		/* some apps don't want you to hear too distant sounds... */
		if (dsb->dsbd.dwFlags & DSBCAPS_MUTE3DATMAXDISTANCE)
		{
			dsb->volpan.lVolume = DSBVOLUME_MIN;
			DSOUND_RecalcVolPan (&dsb->volpan);		
			/* i guess mixing here would be a waste of power */
			return;
		}
		else
			flDistance = dsb->ds3db_ds3db.flMaxDistance;
	}		

	if (flDistance < dsb->ds3db_ds3db.flMinDistance)
		flDistance = dsb->ds3db_ds3db.flMinDistance;
	
	/* attenuation proportional to the distance squared, converted to millibels as in lVolume*/
	lVolume -= log10(flDistance/dsb->ds3db_ds3db.flMinDistance * flDistance/dsb->ds3db_ds3db.flMinDistance)*1000;
	TRACE("dist. att: Distance = %f, MinDistance = %f => adjusting volume %d to %f\n", flDistance, dsb->ds3db_ds3db.flMinDistance, dsb->ds3db_lVolume, lVolume);

	/* conning */
	/* sometimes it happens that vConeOrientation vector = (0,0,0); in this case angle is "nan" and it's useless*/
	if (dsb->ds3db_ds3db.vConeOrientation.x == 0 && dsb->ds3db_ds3db.vConeOrientation.y == 0 && dsb->ds3db_ds3db.vConeOrientation.z == 0)
	{
		TRACE("conning: cones not set\n");
	}
	else
	{
		/* calculate angle */
		flAngle = AngleBetweenVectorsDeg(&dsb->ds3db_ds3db.vConeOrientation, &vDistance);
		/* if by any chance it happens that OutsideConeAngle = InsideConeAngle (that means that conning has no effect) */
		if (dsb->ds3db_ds3db.dwInsideConeAngle != dsb->ds3db_ds3db.dwOutsideConeAngle)
		{
			/* my test show that for my way of calc., we need only half of angles */
			DWORD dwInsideConeAngle = dsb->ds3db_ds3db.dwInsideConeAngle/2;
			DWORD dwOutsideConeAngle = dsb->ds3db_ds3db.dwOutsideConeAngle/2;
			if (dwOutsideConeAngle == dwInsideConeAngle)
				++dwOutsideConeAngle;

			/* full volume */
			if (flAngle < dwInsideConeAngle)
				flAngle = dwInsideConeAngle;
			/* min (app defined) volume */
			if (flAngle > dwOutsideConeAngle)
				flAngle = dwOutsideConeAngle;
			/* this probably isn't the right thing, but it's ok for the time being */
			lVolume += ((dsb->ds3db_ds3db.lConeOutsideVolume)/((dwOutsideConeAngle) - (dwInsideConeAngle))) * flAngle;
		}
		TRACE("conning: Angle = %f deg; InsideConeAngle(/2) = %d deg; OutsideConeAngle(/2) = %d deg; ConeOutsideVolume = %d => adjusting volume to %f\n",
		       flAngle, dsb->ds3db_ds3db.dwInsideConeAngle/2, dsb->ds3db_ds3db.dwOutsideConeAngle/2, dsb->ds3db_ds3db.lConeOutsideVolume, lVolume);
	}
	dsb->volpan.lVolume = lVolume;
	
	/* panning */
	if (dsb->device->ds3dl.vPosition.x == dsb->ds3db_ds3db.vPosition.x &&
	    dsb->device->ds3dl.vPosition.y == dsb->ds3db_ds3db.vPosition.y &&
	    dsb->device->ds3dl.vPosition.z == dsb->ds3db_ds3db.vPosition.z) {
		dsb->volpan.lPan = 0;
		flAngle = 0.0;
	}
	else
	{
		vDistance = VectorBetweenTwoPoints(&dsb->device->ds3dl.vPosition, &dsb->ds3db_ds3db.vPosition);
		vLeft = VectorProduct(&dsb->device->ds3dl.vOrientFront, &dsb->device->ds3dl.vOrientTop);
		flAngle = AngleBetweenVectorsRad(&vLeft, &vDistance);
		/* for now, we'll use "linear formula" (which is probably incorrect); if someone has it in book, correct it */
		dsb->volpan.lPan = 10000*2*flAngle/M_PI - 10000;
	}
	TRACE("panning: Angle = %f rad, lPan = %d\n", flAngle, dsb->volpan.lPan);

	/* FIXME: Doppler Effect disabled since i have no idea which frequency to change and how to do it */
#if 0	
	/* doppler shift*/
	if ((VectorMagnitude(&ds3db_ds3db.vVelocity) == 0) && (VectorMagnitude(&dsb->device->ds3dl.vVelocity) == 0))
	{
		TRACE("doppler: Buffer and Listener don't have velocities\n");
	}
	else if (ds3db_ds3db.vVelocity != dsb->device->ds3dl.vVelocity)
	{
		/* calculate length of ds3db_ds3db.vVelocity component which causes Doppler Effect
		   NOTE: if buffer moves TOWARDS the listener, it's velocity component is NEGATIVE
		         if buffer moves AWAY from listener, it's velocity component is POSITIVE */
		flBufferVel = ProjectVector(&dsb->ds3db_ds3db.vVelocity, &vDistance);
		/* calculate length of ds3dl.vVelocity component which causes Doppler Effect
		   NOTE: if listener moves TOWARDS the buffer, it's velocity component is POSITIVE
		         if listener moves AWAY from buffer, it's velocity component is NEGATIVE */
		flListenerVel = ProjectVector(&dsb->device->ds3dl.vVelocity, &vDistance);
		/* formula taken from Gianicoli D.: Physics, 4th edition: */
		/* FIXME: replace dsb->freq with appropriate frequency ! */
		flFreq = dsb->freq * ((DEFAULT_VELOCITY + flListenerVel)/(DEFAULT_VELOCITY + flBufferVel));
		TRACE("doppler: Buffer velocity (component) = %lf, Listener velocity (component) = %lf => Doppler shift: %ld Hz -> %lf Hz\n", flBufferVel, flListenerVel,
		      dsb->freq, flFreq);
		/* FIXME: replace following line with correct frequency setting ! */
		dsb->freq = flFreq;
		DSOUND_RecalcFormat(dsb);
		DSOUND_MixToTemporary(dsb, 0, dsb->buflen);
	}
#endif	
	
	/* time for remix */
	DSOUND_RecalcVolPan(&dsb->volpan);
}

__attribute__((used)) static void DSOUND_Mix3DBuffer(IDirectSoundBufferImpl *dsb)
{
	TRACE("(%p)\n",dsb);

	DSOUND_Calc3DBuffer(dsb);
}

__attribute__((used)) static void DSOUND_ChangeListener(IDirectSound3DListenerImpl *ds3dl)
{
	int i;
	TRACE("(%p)\n",ds3dl);
	for (i = 0; i < ds3dl->device->nrofbuffers; i++)
	{
		/* check if this buffer is waiting for recalculation */
		if (ds3dl->device->buffers[i]->ds3db_need_recalc)
		{
			DSOUND_Mix3DBuffer(ds3dl->device->buffers[i]);
		}
	}
}

HRESULT IDirectSound3DBufferImpl_Create(
	IDirectSoundBufferImpl *dsb,
	IDirectSound3DBufferImpl **pds3db)
{
	IDirectSound3DBufferImpl *ds3db;
	TRACE("(%p,%p)\n",dsb,pds3db);

	ds3db = HeapAlloc(GetProcessHeap(),HEAP_ZERO_MEMORY,sizeof(*ds3db));

	if (ds3db == NULL) {
		WARN("out of memory\n");
		*pds3db = 0;
		return DSERR_OUTOFMEMORY;
	}

	ds3db->ref = 0;
	ds3db->dsb = dsb;
	ds3db->lpVtbl = &ds3dbvt;

	ds3db->dsb->ds3db_ds3db.dwSize = sizeof(DS3DBUFFER);
	ds3db->dsb->ds3db_ds3db.vPosition.x = 0.0;
	ds3db->dsb->ds3db_ds3db.vPosition.y = 0.0;
	ds3db->dsb->ds3db_ds3db.vPosition.z = 0.0;
	ds3db->dsb->ds3db_ds3db.vVelocity.x = 0.0;
	ds3db->dsb->ds3db_ds3db.vVelocity.y = 0.0;
	ds3db->dsb->ds3db_ds3db.vVelocity.z = 0.0;
	ds3db->dsb->ds3db_ds3db.dwInsideConeAngle = DS3D_DEFAULTCONEANGLE;
	ds3db->dsb->ds3db_ds3db.dwOutsideConeAngle = DS3D_DEFAULTCONEANGLE;
	ds3db->dsb->ds3db_ds3db.vConeOrientation.x = 0.0;
	ds3db->dsb->ds3db_ds3db.vConeOrientation.y = 0.0;
	ds3db->dsb->ds3db_ds3db.vConeOrientation.z = 0.0;
	ds3db->dsb->ds3db_ds3db.lConeOutsideVolume = DS3D_DEFAULTCONEOUTSIDEVOLUME;
	ds3db->dsb->ds3db_ds3db.flMinDistance = DS3D_DEFAULTMINDISTANCE;
	ds3db->dsb->ds3db_ds3db.flMaxDistance = DS3D_DEFAULTMAXDISTANCE;
	ds3db->dsb->ds3db_ds3db.dwMode = DS3DMODE_NORMAL;

	ds3db->dsb->ds3db_need_recalc = TRUE;

	*pds3db = ds3db;
	return S_OK;
}

HRESULT IDirectSound3DBufferImpl_Destroy(
    IDirectSound3DBufferImpl *pds3db)
{
    TRACE("(%p)\n",pds3db);

    while (IDirectSound3DBufferImpl_Release((LPDIRECTSOUND3DBUFFER)pds3db) > 0);

    return S_OK;
}

HRESULT IDirectSound3DListenerImpl_Create(
	DirectSoundDevice * device,
	IDirectSound3DListenerImpl ** ppdsl)
{
	IDirectSound3DListenerImpl *pdsl;
	TRACE("(%p,%p)\n",device,ppdsl);

	pdsl = HeapAlloc(GetProcessHeap(),HEAP_ZERO_MEMORY,sizeof(*pdsl));

	if (pdsl == NULL) {
		WARN("out of memory\n");
		*ppdsl = 0;
		return DSERR_OUTOFMEMORY;
	}

	pdsl->ref = 0;
	pdsl->lpVtbl = &ds3dlvt;

	pdsl->device = device;

	pdsl->device->ds3dl.dwSize = sizeof(DS3DLISTENER);
	pdsl->device->ds3dl.vPosition.x = 0.0;
	pdsl->device->ds3dl.vPosition.y = 0.0;
	pdsl->device->ds3dl.vPosition.z = 0.0;
	pdsl->device->ds3dl.vVelocity.x = 0.0;
	pdsl->device->ds3dl.vVelocity.y = 0.0;
	pdsl->device->ds3dl.vVelocity.z = 0.0;
	pdsl->device->ds3dl.vOrientFront.x = 0.0;
	pdsl->device->ds3dl.vOrientFront.y = 0.0;
	pdsl->device->ds3dl.vOrientFront.z = 1.0;
	pdsl->device->ds3dl.vOrientTop.x = 0.0;
	pdsl->device->ds3dl.vOrientTop.y = 1.0;
	pdsl->device->ds3dl.vOrientTop.z = 0.0;
	pdsl->device->ds3dl.flDistanceFactor = DS3D_DEFAULTDISTANCEFACTOR;
	pdsl->device->ds3dl.flRolloffFactor = DS3D_DEFAULTROLLOFFFACTOR;
	pdsl->device->ds3dl.flDopplerFactor = DS3D_DEFAULTDOPPLERFACTOR;

	pdsl->device->ds3dl_need_recalc = TRUE;

	*ppdsl = pdsl;
	return S_OK;
}

