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
 int QR_MAXI (int,int /*<<< orphan*/ ) ; 
 int abs (int) ; 
 int qr_ilog (unsigned int) ; 

unsigned qr_isqrt(unsigned _val){
  unsigned g;
  unsigned b;
  int      bshift;
  /*Uses the second method from
     http://www.azillionmonkeys.com/qed/sqroot.html
    The main idea is to search for the largest binary digit b such that
     (g+b)*(g+b) <= _val, and add it to the solution g.*/
  g=0;
  b=0x8000;
  for(bshift=16;bshift-->0;){
    unsigned t;
    t=(g<<1)+b<<bshift;
    if(t<=_val){
      g+=b;
      _val-=t;
    }
    b>>=1;
  }
  return g;
}

unsigned qr_ihypot(int _x,int _y){
  unsigned x;
  unsigned y;
  int      mask;
  int      shift;
  int      u;
  int      v;
  int      i;
  x=_x=abs(_x);
  y=_y=abs(_y);
  mask=-(x>y)&(_x^_y);
  x^=mask;
  y^=mask;
  _y^=mask;
  shift=31-qr_ilog(y);
  shift=QR_MAXI(shift,0);
  x=(unsigned)((x<<shift)*0x9B74EDAAULL>>32);
  _y=(int)((_y<<shift)*0x9B74EDA9LL>>32);
  u=x;
  mask=-(_y<0);
  x+=_y+mask^mask;
  _y-=u+mask^mask;
  u=x+1>>1;
  v=_y+1>>1;
  mask=-(_y<0);
  x+=v+mask^mask;
  _y-=u+mask^mask;
  for(i=1;i<16;i++){
    int r;
    u=x+1>>2;
    r=(1<<2*i)>>1;
    v=_y+r>>2*i;
    mask=-(_y<0);
    x+=v+mask^mask;
    _y=_y-(u+mask^mask)<<1;
  }
  return x+((1U<<shift)>>1)>>shift;
}

int qr_ilog(unsigned _v){
#if defined(QR_CLZ)
/*Note that __builtin_clz is not defined when _x==0, according to the gcc
   documentation (and that of the x86 BSR instruction that implements it), so
   we have to special-case it.*/
  return QR_CLZ0-QR_CLZ(_v)&-!!_v;
#else
  int ret;
  int m;
  m=!!(_v&0xFFFF0000)<<4;
  _v>>=m;
  ret=m;
  m=!!(_v&0xFF00)<<3;
  _v>>=m;
  ret|=m;
  m=!!(_v&0xF0)<<2;
  _v>>=m;
  ret|=m;
  m=!!(_v&0xC)<<1;
  _v>>=m;
  ret|=m;
  ret|=!!(_v&0x2);
  return ret + !!_v;
#endif
}

