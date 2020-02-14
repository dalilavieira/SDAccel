#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct kissf_fftnd_state {int dummy; } ;
typedef  TYPE_1__* kissf_fftnd_cfg ;
typedef  int /*<<< orphan*/  const kissf_fft_cpx ;
typedef  int /*<<< orphan*/  kissf_fft_cfg ;
struct TYPE_4__ {int dimprod; int ndims; int* dims; int /*<<< orphan*/  const* tmpbuf; int /*<<< orphan*/ * states; } ;

/* Variables and functions */
 int /*<<< orphan*/  fprintf (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  kissf_fft_alloc (int const,int,char*,size_t*) ; 
 int /*<<< orphan*/  kissf_fft_stride (int /*<<< orphan*/ ,int /*<<< orphan*/  const*,int /*<<< orphan*/  const*,int) ; 
 scalar_t__ malloc (size_t) ; 
 int /*<<< orphan*/  memcpy (int /*<<< orphan*/  const*,int /*<<< orphan*/  const*,int) ; 
 int /*<<< orphan*/  stderr ; 

kissf_fftnd_cfg kissf_fftnd_alloc(const int *dims,int ndims,int inverse_fft,void*mem,size_t*lenmem)
{
    kissf_fftnd_cfg st = NULL;
    int i;
    int dimprod=1;
    size_t memneeded = sizeof(struct kissf_fftnd_state);
    char * ptr;

    for (i=0;i<ndims;++i) {
        size_t sublen=0;
        kissf_fft_alloc (dims[i], inverse_fft, NULL, &sublen);
        memneeded += sublen;   /* st->states[i] */
        dimprod *= dims[i];
    }
    memneeded += sizeof(int) * ndims;/*  st->dims */
    memneeded += sizeof(void*) * ndims;/* st->states  */
    memneeded += sizeof(kissf_fft_cpx) * dimprod; /* st->tmpbuf */

    if (lenmem == NULL) {/* allocate for the caller*/
        st = (kissf_fftnd_cfg) malloc (memneeded);
    } else { /* initialize supplied buffer if big enough */
        if (*lenmem >= memneeded)
            st = (kissf_fftnd_cfg) mem;
        *lenmem = memneeded; /*tell caller how big struct is (or would be) */
    }
    if (!st)
        return NULL; /*malloc failed or buffer too small */

    st->dimprod = dimprod;
    st->ndims = ndims;
    ptr=(char*)(st+1);

    st->states = (kissf_fft_cfg *)ptr;
    ptr += sizeof(void*) * ndims;

    st->dims = (int*)ptr;
    ptr += sizeof(int) * ndims;

    st->tmpbuf = (kissf_fft_cpx*)ptr;
    ptr += sizeof(kissf_fft_cpx) * dimprod;

    for (i=0;i<ndims;++i) {
        size_t len;
        st->dims[i] = dims[i];
        kissf_fft_alloc (st->dims[i], inverse_fft, NULL, &len);
        st->states[i] = kissf_fft_alloc (st->dims[i], inverse_fft, ptr,&len);
        ptr += len;
    }
    /*
Hi there!

If you're looking at this particular code, it probably means you've got a brain-dead bounds checker 
that thinks the above code overwrites the end of the array.

It doesn't.

-- Mark 

P.S.
The below code might give you some warm fuzzies and help convince you.
       */
    if ( ptr - (char*)st != (int)memneeded ) {
        fprintf(stderr,
                "################################################################################\n"
                "Internal error! Memory allocation miscalculation\n"
                "################################################################################\n"
               );
    }
    return st;
}

void kissf_fftnd(kissf_fftnd_cfg st,const kissf_fft_cpx *fin,kissf_fft_cpx *fout)
{
    int i,k;
    const kissf_fft_cpx * bufin=fin;
    kissf_fft_cpx * bufout;

    /*arrange it so the last bufout == fout*/
    if ( st->ndims & 1 ) {
        bufout = fout;
        if (fin==fout) {
            memcpy( st->tmpbuf, fin, sizeof(kissf_fft_cpx) * st->dimprod );
            bufin = st->tmpbuf;
        }
    }else
        bufout = st->tmpbuf;

    for ( k=0; k < st->ndims; ++k) {
        int curdim = st->dims[k];
        int stride = st->dimprod / curdim;

        for ( i=0 ; i<stride ; ++i ) 
            kissf_fft_stride( st->states[k], bufin+i , bufout+i*curdim, stride );

        /*toggle back and forth between the two buffers*/
        if (bufout == st->tmpbuf){
            bufout = fout;
            bufin = st->tmpbuf;
        }else{
            bufout = st->tmpbuf;
            bufin = fout;
        }
    }
}

