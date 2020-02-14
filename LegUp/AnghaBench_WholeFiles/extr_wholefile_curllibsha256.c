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
struct sha256_state {unsigned long* state; int curlen; int length; unsigned char* buf; } ;
typedef  struct sha256_state SHA256_CTX ;

/* Variables and functions */
 unsigned long CURLMIN (unsigned long,int) ; 
 unsigned long Ch (unsigned long,unsigned long,unsigned long) ; 
 unsigned long Gamma0 (unsigned long) ; 
 unsigned long Gamma1 (unsigned long) ; 
 unsigned long* K ; 
 unsigned long Maj (unsigned long,unsigned long,unsigned long) ; 
 unsigned long Sigma0 (unsigned long) ; 
 unsigned long Sigma1 (unsigned long) ; 
 unsigned long WPA_GET_BE32 (unsigned char*) ; 
 int /*<<< orphan*/  WPA_PUT_BE32 (unsigned char*,int) ; 
 int /*<<< orphan*/  WPA_PUT_BE64 (unsigned char*,int) ; 
 unsigned long curlx_uztoui (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  memcpy (unsigned char*,unsigned char const*,unsigned long) ; 
 int /*<<< orphan*/  strlen (char*) ; 

__attribute__((used)) static int sha256_compress(struct sha256_state *md,
                           unsigned char *buf)
{
  unsigned long S[8], W[64];
  int i;
  /* copy state into S */
  for(i = 0; i < 8; i++) {
    S[i] = md->state[i];
  }
  /* copy the state into 512-bits into W[0..15] */
  for(i = 0; i < 16; i++)
    W[i] = WPA_GET_BE32(buf + (4 * i));
  /* fill W[16..63] */
  for(i = 16; i < 64; i++) {
    W[i] = Gamma1(W[i - 2]) + W[i - 7] + Gamma0(W[i - 15]) +
      W[i - 16];
  }
  /* Compress */
#define RND(a,b,c,d,e,f,g,h,i)                                  \
  unsigned long t0 = h + Sigma1(e) + Ch(e, f, g) + K[i] + W[i]; \
  unsigned long t1 = Sigma0(a) + Maj(a, b, c);                  \
  d += t0;                                                      \
  h = t0 + t1;
  for(i = 0; i < 64; ++i) {
    unsigned long t;
    RND(S[0], S[1], S[2], S[3], S[4], S[5], S[6], S[7], i);
    t = S[7]; S[7] = S[6]; S[6] = S[5]; S[5] = S[4];
    S[4] = S[3]; S[3] = S[2]; S[2] = S[1]; S[1] = S[0]; S[0] = t;
  }
  /* feedback */
  for(i = 0; i < 8; i++) {
    md->state[i] = md->state[i] + S[i];
  }
  return 0;
}

__attribute__((used)) static void SHA256_Init(struct sha256_state *md)
{
  md->curlen = 0;
  md->length = 0;
  md->state[0] = 0x6A09E667UL;
  md->state[1] = 0xBB67AE85UL;
  md->state[2] = 0x3C6EF372UL;
  md->state[3] = 0xA54FF53AUL;
  md->state[4] = 0x510E527FUL;
  md->state[5] = 0x9B05688CUL;
  md->state[6] = 0x1F83D9ABUL;
  md->state[7] = 0x5BE0CD19UL;
}

__attribute__((used)) static int SHA256_Update(struct sha256_state *md,
                         const unsigned char *in,
                         unsigned long inlen)
{
  unsigned long n;
#define block_size 64
  if(md->curlen > sizeof(md->buf))
    return -1;
  while(inlen > 0) {
    if(md->curlen == 0 && inlen >= block_size) {
      if(sha256_compress(md, (unsigned char *)in) < 0)
        return -1;
      md->length += block_size * 8;
      in += block_size;
      inlen -= block_size;
    }
    else {
      n = CURLMIN(inlen, (block_size - md->curlen));
      memcpy(md->buf + md->curlen, in, n);
      md->curlen += n;
      in += n;
      inlen -= n;
      if(md->curlen == block_size) {
        if(sha256_compress(md, md->buf) < 0)
          return -1;
        md->length += 8 * block_size;
        md->curlen = 0;
      }
    }
  }
  return 0;
}

__attribute__((used)) static int SHA256_Final(unsigned char *out,
                        struct sha256_state *md)
{
  int i;
  if(md->curlen >= sizeof(md->buf))
    return -1;
  /* increase the length of the message */
  md->length += md->curlen * 8;
  /* append the '1' bit */
  md->buf[md->curlen++] = (unsigned char)0x80;
  /* if the length is currently above 56 bytes we append zeros
   * then compress.  Then we can fall back to padding zeros and length
   * encoding like normal.
   */
  if(md->curlen > 56) {
    while(md->curlen < 64) {
      md->buf[md->curlen++] = (unsigned char)0;
    }
    sha256_compress(md, md->buf);
    md->curlen = 0;
  }
  /* pad up to 56 bytes of zeroes */
  while(md->curlen < 56) {
    md->buf[md->curlen++] = (unsigned char)0;
  }
  /* store length */
  WPA_PUT_BE64(md->buf + 56, md->length);
  sha256_compress(md, md->buf);
  /* copy output */
  for(i = 0; i < 8; i++)
    WPA_PUT_BE32(out + (4 * i), md->state[i]);
  return 0;
}

void Curl_sha256it(unsigned char *outbuffer, /* 32 unsigned chars */
                   const unsigned char *input)
{
  SHA256_CTX ctx;
  SHA256_Init(&ctx);
  SHA256_Update(&ctx, input, curlx_uztoui(strlen((char *)input)));
  SHA256_Final(outbuffer, &ctx);
}

