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
typedef  size_t v ;
typedef  int uint8_t ;
typedef  int uint64_t ;
typedef  int uint32_t ;
typedef  int /*<<< orphan*/  lua_State ;
typedef  int /*<<< orphan*/  luaL_Buffer ;
typedef  int /*<<< orphan*/  decoding ;
typedef  int Y ;
typedef  size_t X ;

/* Variables and functions */
 int /*<<< orphan*/  DES_FP (int,int) ; 
 int /*<<< orphan*/  DES_IP (int,int) ; 
 int /*<<< orphan*/  DES_ROUND (int,int) ; 
 int G ; 
 int /*<<< orphan*/  GET_UINT32 (int,int const*,int) ; 
 int /*<<< orphan*/  HEX (int,char const) ; 
 int LEFTROTATE (int,int /*<<< orphan*/ ) ; 
 int* LHs ; 
 int P ; 
 int /*<<< orphan*/  PUT_UINT32 (int,int*,int) ; 
 int* RHs ; 
 int SMALL_CHUNK ; 
 int* k ; 
 int /*<<< orphan*/  luaL_addsize (int /*<<< orphan*/ *,size_t) ; 
 char* luaL_buffinitsize (int /*<<< orphan*/ *,int /*<<< orphan*/ *,size_t) ; 
 void* luaL_checklstring (int /*<<< orphan*/ *,int,size_t*) ; 
 int luaL_error (int /*<<< orphan*/ *,char*,...) ; 
 int /*<<< orphan*/  luaL_pushresult (int /*<<< orphan*/ *) ; 
 void* lua_newuserdata (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  lua_pushlstring (int /*<<< orphan*/ *,char const*,int) ; 
 int /*<<< orphan*/ * r ; 
 int random () ; 

__attribute__((used)) static void 
des_main_ks( uint32_t SK[32], const uint8_t key[8] ) {
	int i;
	uint32_t X, Y, T;

	GET_UINT32( X, key, 0 );
	GET_UINT32( Y, key, 4 );

	/* Permuted Choice 1 */

	T =  ((Y >>  4) ^ X) & 0x0F0F0F0F;  X ^= T; Y ^= (T <<  4);
	T =  ((Y	  ) ^ X) & 0x10101010;  X ^= T; Y ^= (T	  );

	X =   (LHs[ (X	  ) & 0xF] << 3) | (LHs[ (X >>  8) & 0xF ] << 2)
		| (LHs[ (X >> 16) & 0xF] << 1) | (LHs[ (X >> 24) & 0xF ]	 )
		| (LHs[ (X >>  5) & 0xF] << 7) | (LHs[ (X >> 13) & 0xF ] << 6)
		| (LHs[ (X >> 21) & 0xF] << 5) | (LHs[ (X >> 29) & 0xF ] << 4);

	Y =   (RHs[ (Y >>  1) & 0xF] << 3) | (RHs[ (Y >>  9) & 0xF ] << 2)
		| (RHs[ (Y >> 17) & 0xF] << 1) | (RHs[ (Y >> 25) & 0xF ]	 )
		| (RHs[ (Y >>  4) & 0xF] << 7) | (RHs[ (Y >> 12) & 0xF ] << 6)
		| (RHs[ (Y >> 20) & 0xF] << 5) | (RHs[ (Y >> 28) & 0xF ] << 4);

	X &= 0x0FFFFFFF;
	Y &= 0x0FFFFFFF;

	/* calculate subkeys */

	for( i = 0; i < 16; i++ )
	{
		if( i < 2 || i == 8 || i == 15 )
		{
			X = ((X <<  1) | (X >> 27)) & 0x0FFFFFFF;
			Y = ((Y <<  1) | (Y >> 27)) & 0x0FFFFFFF;
		}
		else
		{
			X = ((X <<  2) | (X >> 26)) & 0x0FFFFFFF;
			Y = ((Y <<  2) | (Y >> 26)) & 0x0FFFFFFF;
		}

		*SK++ =   ((X <<  4) & 0x24000000) | ((X << 28) & 0x10000000)
				| ((X << 14) & 0x08000000) | ((X << 18) & 0x02080000)
				| ((X <<  6) & 0x01000000) | ((X <<  9) & 0x00200000)
				| ((X >>  1) & 0x00100000) | ((X << 10) & 0x00040000)
				| ((X <<  2) & 0x00020000) | ((X >> 10) & 0x00010000)
				| ((Y >> 13) & 0x00002000) | ((Y >>  4) & 0x00001000)
				| ((Y <<  6) & 0x00000800) | ((Y >>  1) & 0x00000400)
				| ((Y >> 14) & 0x00000200) | ((Y	  ) & 0x00000100)
				| ((Y >>  5) & 0x00000020) | ((Y >> 10) & 0x00000010)
				| ((Y >>  3) & 0x00000008) | ((Y >> 18) & 0x00000004)
				| ((Y >> 26) & 0x00000002) | ((Y >> 24) & 0x00000001);

		*SK++ =   ((X << 15) & 0x20000000) | ((X << 17) & 0x10000000)
				| ((X << 10) & 0x08000000) | ((X << 22) & 0x04000000)
				| ((X >>  2) & 0x02000000) | ((X <<  1) & 0x01000000)
				| ((X << 16) & 0x00200000) | ((X << 11) & 0x00100000)
				| ((X <<  3) & 0x00080000) | ((X >>  6) & 0x00040000)
				| ((X << 15) & 0x00020000) | ((X >>  4) & 0x00010000)
				| ((Y >>  2) & 0x00002000) | ((Y <<  8) & 0x00001000)
				| ((Y >> 14) & 0x00000808) | ((Y >>  9) & 0x00000400)
				| ((Y	  ) & 0x00000200) | ((Y <<  7) & 0x00000100)
				| ((Y >>  7) & 0x00000020) | ((Y >>  3) & 0x00000011)
				| ((Y <<  2) & 0x00000004) | ((Y >> 21) & 0x00000002);
	}
}

__attribute__((used)) static void 
des_crypt( const uint32_t SK[32], const uint8_t input[8], uint8_t output[8] ) {
	uint32_t X, Y, T;

	GET_UINT32( X, input, 0 );
	GET_UINT32( Y, input, 4 );

	DES_IP( X, Y );

	DES_ROUND( Y, X );  DES_ROUND( X, Y );
	DES_ROUND( Y, X );  DES_ROUND( X, Y );
	DES_ROUND( Y, X );  DES_ROUND( X, Y );
	DES_ROUND( Y, X );  DES_ROUND( X, Y );
	DES_ROUND( Y, X );  DES_ROUND( X, Y );
	DES_ROUND( Y, X );  DES_ROUND( X, Y );
	DES_ROUND( Y, X );  DES_ROUND( X, Y );
	DES_ROUND( Y, X );  DES_ROUND( X, Y );

	DES_FP( Y, X );

	PUT_UINT32( Y, output, 0 );
	PUT_UINT32( X, output, 4 );
}

__attribute__((used)) static int
lrandomkey(lua_State *L) {
	char tmp[8];
	int i;
	char x = 0;
	for (i=0;i<8;i++) {
		tmp[i] = random() & 0xff;
		x ^= tmp[i];
	}
	if (x==0) {
		tmp[0] |= 1;	// avoid 0
	}
	lua_pushlstring(L, tmp, 8);
	return 1;
}

__attribute__((used)) static void
des_key(lua_State *L, uint32_t SK[32]) {
	size_t keysz = 0;
	const void * key = luaL_checklstring(L, 1, &keysz);
	if (keysz != 8) {
		luaL_error(L, "Invalid key size %d, need 8 bytes", (int)keysz);
	}
	des_main_ks(SK, key);
}

__attribute__((used)) static int
ldesencode(lua_State *L) {
	uint32_t SK[32];
	des_key(L, SK);

	size_t textsz = 0;
	const uint8_t * text = (const uint8_t *)luaL_checklstring(L, 2, &textsz);
	size_t chunksz = (textsz + 8) & ~7;
	uint8_t tmp[SMALL_CHUNK];
	uint8_t *buffer = tmp;
	if (chunksz > SMALL_CHUNK) {
		buffer = lua_newuserdata(L, chunksz);
	}
	int i;
	for (i=0;i<(int)textsz-7;i+=8) {
		des_crypt(SK, text+i, buffer+i);
	}
	int bytes = textsz - i;
	uint8_t tail[8];
	int j;
	for (j=0;j<8;j++) {
		if (j < bytes) {
			tail[j] = text[i+j];
		} else if (j==bytes) {
			tail[j] = 0x80;
		} else {
			tail[j] = 0;
		}
	}
	des_crypt(SK, tail, buffer+i);
	lua_pushlstring(L, (const char *)buffer, chunksz);

	return 1;
}

__attribute__((used)) static int
ldesdecode(lua_State *L) {
	uint32_t ESK[32];
	des_key(L, ESK);
	uint32_t SK[32];
	int i;
	for( i = 0; i < 32; i += 2 ) {
		SK[i] = ESK[30 - i];
		SK[i + 1] = ESK[31 - i];
	}
	size_t textsz = 0;
	const uint8_t *text = (const uint8_t *)luaL_checklstring(L, 2, &textsz);
	if ((textsz & 7) || textsz == 0) {
		return luaL_error(L, "Invalid des crypt text length %d", (int)textsz);
	}
	uint8_t tmp[SMALL_CHUNK];
	uint8_t *buffer = tmp;
	if (textsz > SMALL_CHUNK) {
		buffer = lua_newuserdata(L, textsz);
	}
	for (i=0;i<textsz;i+=8) {
		des_crypt(SK, text+i, buffer+i);
	}
	int padding = 1;
	for (i=textsz-1;i>=textsz-8;i--) {
		if (buffer[i] == 0) {
			padding++;
		} else if (buffer[i] == 0x80) {
			break;
		} else {
			return luaL_error(L, "Invalid des crypt text");
		}
	}
	if (padding > 8) {
		return luaL_error(L, "Invalid des crypt text");
	}
	lua_pushlstring(L, (const char *)buffer, textsz - padding);
	return 1;
}

__attribute__((used)) static void
Hash(const char * str, int sz, uint8_t key[8]) {
	uint32_t djb_hash = 5381L;
	uint32_t js_hash = 1315423911L;

	int i;
	for (i=0;i<sz;i++) {
		uint8_t c = (uint8_t)str[i];
		djb_hash += (djb_hash << 5) + c;
		js_hash ^= ((js_hash << 5) + c + (js_hash >> 2));
	}

	key[0] = djb_hash & 0xff;
	key[1] = (djb_hash >> 8) & 0xff;
	key[2] = (djb_hash >> 16) & 0xff;
	key[3] = (djb_hash >> 24) & 0xff;

	key[4] = js_hash & 0xff;
	key[5] = (js_hash >> 8) & 0xff;
	key[6] = (js_hash >> 16) & 0xff;
	key[7] = (js_hash >> 24) & 0xff;
}

__attribute__((used)) static int
lhashkey(lua_State *L) {
	size_t sz = 0;
	const char * key = luaL_checklstring(L, 1, &sz);
	uint8_t realkey[8];
	Hash(key,(int)sz,realkey);
	lua_pushlstring(L, (const char *)realkey, 8);
	return 1;
}

__attribute__((used)) static int
ltohex(lua_State *L) {
	static char hex[] = "0123456789abcdef";
	size_t sz = 0;
	const uint8_t * text = (const uint8_t *)luaL_checklstring(L, 1, &sz);
	char tmp[SMALL_CHUNK];
	char *buffer = tmp;
	if (sz > SMALL_CHUNK/2) {
		buffer = lua_newuserdata(L, sz * 2);
	}
	int i;
	for (i=0;i<sz;i++) {
		buffer[i*2] = hex[text[i] >> 4];
		buffer[i*2+1] = hex[text[i] & 0xf];
	}
	lua_pushlstring(L, buffer, sz * 2);
	return 1;
}

__attribute__((used)) static int
lfromhex(lua_State *L) {
	size_t sz = 0;
	const char * text = luaL_checklstring(L, 1, &sz);
	if (sz & 1) {
		return luaL_error(L, "Invalid hex text size %d", (int)sz);
	}
	char tmp[SMALL_CHUNK];
	char *buffer = tmp;
	if (sz > SMALL_CHUNK*2) {
		buffer = lua_newuserdata(L, sz / 2);
	}
	int i;
	for (i=0;i<sz;i+=2) {
		uint8_t hi,low;
		HEX(hi, text[i]);
		HEX(low, text[i+1]);
		if (hi > 16 || low > 16) {
			return luaL_error(L, "Invalid hex text", text);
		}
		buffer[i/2] = hi<<4 | low;
	}
	lua_pushlstring(L, buffer, i/2);
	return 1;
}

__attribute__((used)) static void
digest_md5(uint32_t w[16], uint32_t result[4]) {
	uint32_t a, b, c, d, f, g, temp;
	int i;
 
	a = 0x67452301u;
	b = 0xefcdab89u;
	c = 0x98badcfeu;
	d = 0x10325476u;

	for(i = 0; i<64; i++) {
		if (i < 16) {
			f = (b & c) | ((~b) & d);
			g = i;
		} else if (i < 32) {
			f = (d & b) | ((~d) & c);
			g = (5*i + 1) % 16;
		} else if (i < 48) {
			f = b ^ c ^ d;
			g = (3*i + 5) % 16; 
		} else {
			f = c ^ (b | (~d));
			g = (7*i) % 16;
		}

		temp = d;
		d = c;
		c = b;
		b = b + LEFTROTATE((a + f + k[i] + w[g]), r[i]);
		a = temp;
	}

	result[0] = a;
	result[1] = b;
	result[2] = c;
	result[3] = d;
}

__attribute__((used)) static void
hmac(uint32_t x[2], uint32_t y[2], uint32_t result[2]) {
	uint32_t w[16];
	uint32_t r[4];
	int i;
	for (i=0;i<16;i+=4) {
		w[i] = x[1];
		w[i+1] = x[0];
		w[i+2] = y[1];
		w[i+3] = y[0];
	}

	digest_md5(w,r);

	result[0] = r[2]^r[3];
	result[1] = r[0]^r[1];
}

__attribute__((used)) static void
hmac_md5(uint32_t x[2], uint32_t y[2], uint32_t result[2]) {
	uint32_t w[16];
	uint32_t r[4];
	int i;
	for (i=0;i<12;i+=4) {
		w[i] = x[0];
		w[i+1] = x[1];
		w[i+2] = y[0];
		w[i+3] = y[1];
	}

	w[12] = 0x80;
	w[13] = 0;
	w[14] = 384;
	w[15] = 0;

	digest_md5(w,r);

	result[0] = (r[0] + 0x67452301u) ^ (r[2] + 0x98badcfeu);
	result[1] = (r[1] + 0xefcdab89u) ^ (r[3] + 0x10325476u);
}

__attribute__((used)) static void
read64(lua_State *L, uint32_t xx[2], uint32_t yy[2]) {
	size_t sz = 0;
	const uint8_t *x = (const uint8_t *)luaL_checklstring(L, 1, &sz);
	if (sz != 8) {
		luaL_error(L, "Invalid uint64 x");
	}
	const uint8_t *y = (const uint8_t *)luaL_checklstring(L, 2, &sz);
	if (sz != 8) {
		luaL_error(L, "Invalid uint64 y");
	}
	xx[0] = x[0] | x[1]<<8 | x[2]<<16 | x[3]<<24;
	xx[1] = x[4] | x[5]<<8 | x[6]<<16 | x[7]<<24;
	yy[0] = y[0] | y[1]<<8 | y[2]<<16 | y[3]<<24;
	yy[1] = y[4] | y[5]<<8 | y[6]<<16 | y[7]<<24;
}

__attribute__((used)) static int
pushqword(lua_State *L, uint32_t result[2]) {
	uint8_t tmp[8];
	tmp[0] = result[0] & 0xff;
	tmp[1] = (result[0] >> 8 )& 0xff;
	tmp[2] = (result[0] >> 16 )& 0xff;
	tmp[3] = (result[0] >> 24 )& 0xff;
	tmp[4] = result[1] & 0xff;
	tmp[5] = (result[1] >> 8 )& 0xff;
	tmp[6] = (result[1] >> 16 )& 0xff;
	tmp[7] = (result[1] >> 24 )& 0xff;

	lua_pushlstring(L, (const char *)tmp, 8);
	return 1;
}

__attribute__((used)) static int
lhmac64(lua_State *L) {
	uint32_t x[2], y[2];
	read64(L, x, y);
	uint32_t result[2];
	hmac(x,y,result);
	return pushqword(L, result);
}

__attribute__((used)) static int
lhmac64_md5(lua_State *L) {
	uint32_t x[2], y[2];
	read64(L, x, y);
	uint32_t result[2];
	hmac_md5(x,y,result);
	return pushqword(L, result);
}

__attribute__((used)) static int
lhmac_hash(lua_State *L) {
	uint32_t key[2];
	size_t sz = 0;
	const uint8_t *x = (const uint8_t *)luaL_checklstring(L, 1, &sz);
	if (sz != 8) {
		luaL_error(L, "Invalid uint64 key");
	}
	key[0] = x[0] | x[1]<<8 | x[2]<<16 | x[3]<<24;
	key[1] = x[4] | x[5]<<8 | x[6]<<16 | x[7]<<24;
	const char * text = luaL_checklstring(L, 2, &sz);
	uint8_t h[8];
	Hash(text,(int)sz,h);
	uint32_t htext[2];
	htext[0] = h[0] | h[1]<<8 | h[2]<<16 | h[3]<<24;
	htext[1] = h[4] | h[5]<<8 | h[6]<<16 | h[7]<<24;
	uint32_t result[2];
	hmac(htext,key,result);
	return pushqword(L, result);
}

__attribute__((used)) static inline uint64_t
mul_mod_p(uint64_t a, uint64_t b) {
	uint64_t m = 0;
	while(b) {
		if(b&1) {
			uint64_t t = P-a;
			if ( m >= t) {
				m -= t;
			} else {
				m += a;
			}
		}
		if (a >= P - a) {
			a = a * 2 - P;
		} else {
			a = a * 2;
		}
		b>>=1;
	}
	return m;
}

__attribute__((used)) static inline uint64_t
pow_mod_p(uint64_t a, uint64_t b) {
	if (b==1) {
		return a;
	}
	uint64_t t = pow_mod_p(a, b>>1);
	t = mul_mod_p(t,t);
	if (b % 2) {
		t = mul_mod_p(t, a);
	}
	return t;
}

__attribute__((used)) static uint64_t
powmodp(uint64_t a, uint64_t b) {
	if (a > P)
		a%=P;
	return pow_mod_p(a,b);
}

__attribute__((used)) static void
push64(lua_State *L, uint64_t r) {
	uint8_t tmp[8];
	tmp[0] = r & 0xff;
	tmp[1] = (r >> 8 )& 0xff;
	tmp[2] = (r >> 16 )& 0xff;
	tmp[3] = (r >> 24 )& 0xff;
	tmp[4] = (r >> 32 )& 0xff;
	tmp[5] = (r >> 40 )& 0xff;
	tmp[6] = (r >> 48 )& 0xff;
	tmp[7] = (r >> 56 )& 0xff;

	lua_pushlstring(L, (const char *)tmp, 8);
}

__attribute__((used)) static int
ldhsecret(lua_State *L) {
	uint32_t x[2], y[2];
	read64(L, x, y);
	uint64_t xx = (uint64_t)x[0] | (uint64_t)x[1]<<32;
	uint64_t yy = (uint64_t)y[0] | (uint64_t)y[1]<<32;
	if (xx == 0 || yy == 0)
		return luaL_error(L, "Can't be 0");
	uint64_t r = powmodp(xx, yy);

	push64(L, r);

	return 1;
}

__attribute__((used)) static int
ldhexchange(lua_State *L) {
	size_t sz = 0;
	const uint8_t *x = (const uint8_t *)luaL_checklstring(L, 1, &sz);
	if (sz != 8) {
		luaL_error(L, "Invalid dh uint64 key");
	}
	uint32_t xx[2];
	xx[0] = x[0] | x[1]<<8 | x[2]<<16 | x[3]<<24;
	xx[1] = x[4] | x[5]<<8 | x[6]<<16 | x[7]<<24;

	uint64_t x64 = (uint64_t)xx[0] | (uint64_t)xx[1]<<32;
	if (x64 == 0)
		return luaL_error(L, "Can't be 0");

	uint64_t r = powmodp(G,	x64);
	push64(L, r);
	return 1;
}

__attribute__((used)) static int
lb64encode(lua_State *L) {
	static const char* encoding = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
	size_t sz = 0;
	const uint8_t * text = (const uint8_t *)luaL_checklstring(L, 1, &sz);
	int encode_sz = (sz + 2)/3*4;
	char tmp[SMALL_CHUNK];
	char *buffer = tmp;
	if (encode_sz > SMALL_CHUNK) {
		buffer = lua_newuserdata(L, encode_sz);
	}
	int i,j;
	j=0;
	for (i=0;i<(int)sz-2;i+=3) {
		uint32_t v = text[i] << 16 | text[i+1] << 8 | text[i+2];
		buffer[j] = encoding[v >> 18];
		buffer[j+1] = encoding[(v >> 12) & 0x3f];
		buffer[j+2] = encoding[(v >> 6) & 0x3f];
		buffer[j+3] = encoding[(v) & 0x3f];
		j+=4;
	}
	int padding = sz-i;
	uint32_t v;
	switch(padding) {
	case 1 :
		v = text[i];
		buffer[j] = encoding[v >> 2];
		buffer[j+1] = encoding[(v & 3) << 4];
		buffer[j+2] = '=';
		buffer[j+3] = '=';
		break;
	case 2 :
		v = text[i] << 8 | text[i+1];
		buffer[j] = encoding[v >> 10];
		buffer[j+1] = encoding[(v >> 4) & 0x3f];
		buffer[j+2] = encoding[(v & 0xf) << 2];
		buffer[j+3] = '=';
		break;
	}
	lua_pushlstring(L, buffer, encode_sz);
	return 1;
}

__attribute__((used)) static inline int
b64index(uint8_t c) {
	static const int decoding[] = {62,-1,-1,-1,63,52,53,54,55,56,57,58,59,60,61,-1,-1,-1,-2,-1,-1,-1,0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,-1,-1,-1,-1,-1,-1,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51};
	int decoding_size = sizeof(decoding)/sizeof(decoding[0]);
	if (c<43) {
		return -1;
	}
	c -= 43;
	if (c>=decoding_size)
		return -1;
	return decoding[c];
}

__attribute__((used)) static int
lb64decode(lua_State *L) {
	size_t sz = 0;
	const uint8_t * text = (const uint8_t *)luaL_checklstring(L, 1, &sz);
	int decode_sz = (sz+3)/4*3;
	char tmp[SMALL_CHUNK];
	char *buffer = tmp;
	if (decode_sz > SMALL_CHUNK) {
		buffer = lua_newuserdata(L, decode_sz);
	}
	int i,j;
	int output = 0;
	for (i=0;i<sz;) {
		int padding = 0;
		int c[4];
		for (j=0;j<4;) {
			if (i>=sz) {
				return luaL_error(L, "Invalid base64 text");
			}
			c[j] = b64index(text[i]);
			if (c[j] == -1) {
				++i;
				continue;
			}
			if (c[j] == -2) {
				++padding;
			}
			++i;
			++j;
		}
		uint32_t v;
		switch (padding) {
		case 0:
			v = (unsigned)c[0] << 18 | c[1] << 12 | c[2] << 6 | c[3];
			buffer[output] = v >> 16;
			buffer[output+1] = (v >> 8) & 0xff;
			buffer[output+2] = v & 0xff;
			output += 3;
			break;
		case 1:
			if (c[3] != -2 || (c[2] & 3)!=0) {
				return luaL_error(L, "Invalid base64 text");
			}
			v = (unsigned)c[0] << 10 | c[1] << 4 | c[2] >> 2 ;
			buffer[output] = v >> 8;
			buffer[output+1] = v & 0xff;
			output += 2;
			break;
		case 2:
			if (c[3] != -2 || c[2] != -2 || (c[1] & 0xf) !=0)  {
				return luaL_error(L, "Invalid base64 text");
			}
			v = (unsigned)c[0] << 2 | c[1] >> 4;
			buffer[output] = v;
			++ output;
			break;
		default:
			return luaL_error(L, "Invalid base64 text");
		}
	}
	lua_pushlstring(L, buffer, output);
	return 1;
}

__attribute__((used)) static int
lxor_str(lua_State *L) {
	size_t len1,len2;
	const char *s1 = luaL_checklstring(L,1,&len1);
	const char *s2 = luaL_checklstring(L,2,&len2);
	if (len2 == 0) {
		return luaL_error(L, "Can't xor empty string");
	}
	luaL_Buffer b;
	char * buffer = luaL_buffinitsize(L, &b, len1);
	int i;
	for (i=0;i<len1;i++) {
		buffer[i] = s1[i] ^ s2[i % len2];
	}
	luaL_addsize(&b, len1);
	luaL_pushresult(&b);
	return 1;
}

