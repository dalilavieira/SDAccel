#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_7__   TYPE_1__ ;

/* Type definitions */
struct kissf_fftndr_state {int dummy; } ;
typedef  int nrbins ;
typedef  TYPE_1__* kissf_fftndr_cfg ;
typedef  int /*<<< orphan*/  kissf_fft_scalar ;
typedef  int /*<<< orphan*/  kissf_fft_cpx ;
struct TYPE_7__ {int dimReal; int dimOther; char* tmpbuf; scalar_t__ cfg_r; scalar_t__ cfg_nd; } ;

/* Variables and functions */
 int MAX (int,int) ; 
 int /*<<< orphan*/  kissf_fftnd (scalar_t__,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 scalar_t__ kissf_fftnd_alloc (int const*,int,int,char*,size_t*) ; 
 int /*<<< orphan*/  kissf_fftr (scalar_t__,int /*<<< orphan*/  const*,int /*<<< orphan*/ *) ; 
 scalar_t__ kissf_fftr_alloc (int,int,TYPE_1__*,size_t*) ; 
 int /*<<< orphan*/  kissf_fftri (scalar_t__,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 scalar_t__ malloc (size_t) ; 
 int /*<<< orphan*/  memset (TYPE_1__*,int /*<<< orphan*/ ,size_t) ; 

__attribute__((used)) static int prod(const int *dims, int ndims)
{
    int x=1;
    while (ndims--) 
        x *= *dims++;
    return x;
}

kissf_fftndr_cfg kissf_fftndr_alloc(const int *dims,int ndims,int inverse_fft,void*mem,size_t*lenmem)
{
    kissf_fftndr_cfg st = NULL;
    size_t nr=0 , nd=0,ntmp=0;
    int dimReal = dims[ndims-1];
    int dimOther = prod(dims,ndims-1);
    size_t memneeded;
    
    (void)kissf_fftr_alloc(dimReal,inverse_fft,NULL,&nr);
    (void)kissf_fftnd_alloc(dims,ndims-1,inverse_fft,NULL,&nd);
    ntmp =
        MAX( 2*dimOther , dimReal+2) * sizeof(kissf_fft_scalar)  // freq buffer for one pass
        + dimOther*(dimReal+2) * sizeof(kissf_fft_scalar);  // large enough to hold entire input in case of in-place

    memneeded = sizeof( struct kissf_fftndr_state ) + nr + nd + ntmp;

    if (lenmem==NULL) {
        st = (kissf_fftndr_cfg) malloc(memneeded);
    }else{
        if (*lenmem >= memneeded)
            st = (kissf_fftndr_cfg)mem;
        *lenmem = memneeded; 
    }
    if (st==NULL)
        return NULL;
    memset( st , 0 , memneeded);
    
    st->dimReal = dimReal;
    st->dimOther = dimOther;
    st->cfg_r = kissf_fftr_alloc( dimReal,inverse_fft,st+1,&nr);
    st->cfg_nd = kissf_fftnd_alloc(dims,ndims-1,inverse_fft, ((char*) st->cfg_r)+nr,&nd);
    st->tmpbuf = (char*)st->cfg_nd + nd;

    return st;
}

void kissf_fftndr(kissf_fftndr_cfg st,const kissf_fft_scalar *timedata,kissf_fft_cpx *freqdata)
{
    int k1,k2;
    int dimReal = st->dimReal;
    int dimOther = st->dimOther;
    int nrbins = dimReal/2+1;

    kissf_fft_cpx * tmp1 = (kissf_fft_cpx*)st->tmpbuf; 
    kissf_fft_cpx * tmp2 = tmp1 + MAX(nrbins,dimOther);

    // timedata is N0 x N1 x ... x Nk real

    // take a real chunk of data, fft it and place the output at correct intervals
    for (k1=0;k1<dimOther;++k1) {
        kissf_fftr( st->cfg_r, timedata + k1*dimReal , tmp1 ); // tmp1 now holds nrbins complex points
        for (k2=0;k2<nrbins;++k2)
           tmp2[ k2*dimOther+k1 ] = tmp1[k2];
    }

    for (k2=0;k2<nrbins;++k2) {
        kissf_fftnd(st->cfg_nd, tmp2+k2*dimOther, tmp1);  // tmp1 now holds dimOther complex points
        for (k1=0;k1<dimOther;++k1) 
            freqdata[ k1*(nrbins) + k2] = tmp1[k1];
    }
}

void kissf_fftndri(kissf_fftndr_cfg st,const kissf_fft_cpx *freqdata,kissf_fft_scalar *timedata)
{
    int k1,k2;
    int dimReal = st->dimReal;
    int dimOther = st->dimOther;
    int nrbins = dimReal/2+1;
    kissf_fft_cpx * tmp1 = (kissf_fft_cpx*)st->tmpbuf; 
    kissf_fft_cpx * tmp2 = tmp1 + MAX(nrbins,dimOther);

    for (k2=0;k2<nrbins;++k2) {
        for (k1=0;k1<dimOther;++k1) 
            tmp1[k1] = freqdata[ k1*(nrbins) + k2 ];
        kissf_fftnd(st->cfg_nd, tmp1, tmp2+k2*dimOther);
    }

    for (k1=0;k1<dimOther;++k1) {
        for (k2=0;k2<nrbins;++k2)
            tmp1[k2] = tmp2[ k2*dimOther+k1 ];
        kissf_fftri( st->cfg_r,tmp1,timedata + k1*dimReal);
    }
}

