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
struct vec2 {float x; float y; } ;

/* Variables and functions */
 float ceilf (float) ; 
 float fabsf (float) ; 
 float floorf (float) ; 
 float sqrtf (int) ; 

__attribute__((used)) static inline float get_percentage(float start, float end, float mid)
{
	return (mid-start) / (end-start);
}

__attribute__((used)) static inline float get_percentagei(int start, int end, int mid)
{
	return (float)(mid-start) / (float)(end-start);
}

__attribute__((used)) static inline bool close_float(float f1, float f2, float precision)
{
	return fabsf(f1-f2) <= precision;
}

__attribute__((used)) static inline void vec2_zero(struct vec2 *dst)
{
	dst->x = 0.0f;
	dst->y = 0.0f;
}

__attribute__((used)) static inline void vec2_set(struct vec2 *dst, float x, float y)
{
	dst->x = x;
	dst->y = y;
}

__attribute__((used)) static inline void vec2_copy(struct vec2 *dst, const struct vec2 *v)
{
	dst->x = v->x;
	dst->y = v->y;
}

__attribute__((used)) static inline void vec2_add(struct vec2 *dst, const struct vec2 *v1,
		const struct vec2 *v2)
{
	vec2_set(dst, v1->x+v2->x, v1->y+v2->y);	
}

__attribute__((used)) static inline void vec2_sub(struct vec2 *dst, const struct vec2 *v1,
		const struct vec2 *v2)
{
	vec2_set(dst, v1->x-v2->x, v1->y-v2->y);	
}

__attribute__((used)) static inline void vec2_mul(struct vec2 *dst, const struct vec2 *v1,
		const struct vec2 *v2)
{
	vec2_set(dst, v1->x*v2->x, v1->y*v2->y);	
}

__attribute__((used)) static inline void vec2_div(struct vec2 *dst, const struct vec2 *v1,
		const struct vec2 *v2)
{
	vec2_set(dst, v1->x/v2->x, v1->y/v2->y);	
}

__attribute__((used)) static inline void vec2_addf(struct vec2 *dst, const struct vec2 *v,
		float f)
{
	vec2_set(dst, v->x+f, v->y+f);	
}

__attribute__((used)) static inline void vec2_subf(struct vec2 *dst, const struct vec2 *v,
		float f)
{
	vec2_set(dst, v->x-f, v->y-f);	
}

__attribute__((used)) static inline void vec2_mulf(struct vec2 *dst, const struct vec2 *v,
		float f)
{
	vec2_set(dst, v->x*f, v->y*f);	
}

__attribute__((used)) static inline void vec2_divf(struct vec2 *dst, const struct vec2 *v,
		float f)
{
	vec2_set(dst, v->x/f, v->y/f);	
}

__attribute__((used)) static inline void vec2_neg(struct vec2 *dst, const struct vec2 *v)
{
	vec2_set(dst, -v->x, -v->y);
}

__attribute__((used)) static inline float vec2_dot(const struct vec2 *v1, const struct vec2 *v2)
{
	return v1->x*v2->x + v1->y*v2->y;
}

__attribute__((used)) static inline float vec2_len(const struct vec2 *v)
{
	return sqrtf(v->x*v->x + v->y*v->y);
}

__attribute__((used)) static inline float vec2_dist(const struct vec2 *v1, const struct vec2 *v2)
{
	struct vec2 temp;
	vec2_sub(&temp, v1, v2);
	return vec2_len(&temp);
}

__attribute__((used)) static inline void vec2_minf(struct vec2 *dst, const struct vec2 *v,
		float val)
{
	if (v->x < val)
		dst->x = val;
	if (v->y < val)
		dst->y = val;
}

__attribute__((used)) static inline void vec2_min(struct vec2 *dst, const struct vec2 *v,
		const struct vec2 *min_v)
{
	if (v->x < min_v->x)
		dst->x = min_v->x;
	if (v->y < min_v->y)
		dst->y = min_v->y;
}

__attribute__((used)) static inline void vec2_maxf(struct vec2 *dst, const struct vec2 *v,
		float val)
{
	if (v->x > val)
		dst->x = val;
	if (v->y > val)
		dst->y = val;
}

__attribute__((used)) static inline void vec2_max(struct vec2 *dst, const struct vec2 *v,
		const struct vec2 *max_v)
{
	if (v->x > max_v->x)
		dst->x = max_v->x;
	if (v->y > max_v->y)
		dst->y = max_v->y;
}

void vec2_abs(struct vec2 *dst, const struct vec2 *v)
{
	vec2_set(dst, fabsf(v->x), fabsf(v->y));
}

void vec2_floor(struct vec2 *dst, const struct vec2 *v)
{
	vec2_set(dst, floorf(v->x), floorf(v->y));
}

void vec2_ceil(struct vec2 *dst, const struct vec2 *v)
{
	vec2_set(dst, ceilf(v->x), ceilf(v->y));
}

int vec2_close(const struct vec2 *v1, const struct vec2 *v2, float epsilon)
{
	return close_float(v1->x, v2->x, epsilon) &&
	       close_float(v1->y, v2->y, epsilon);
}

void vec2_norm(struct vec2 *dst, const struct vec2 *v)
{
	float len = vec2_len(v);

	if (len > 0.0f) {
		len = 1.0f / len;
		vec2_mulf(dst, v, len);
	}
}

