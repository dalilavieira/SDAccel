#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
typedef  float vec_t ;
typedef  float* const vec3_t ;
struct TYPE_6__ {float* origin; float* direction; } ;
typedef  TYPE_1__ ray_t ;
typedef  scalar_t__ qboolean ;
typedef  int /*<<< orphan*/  m4x4_t ;

/* Variables and functions */
 int /*<<< orphan*/  CrossProduct (float*,float*,float*) ; 
 float DotProduct (float* const,float*) ; 
 float EPSILON ; 
 int /*<<< orphan*/  VEC_MAX ; 
 int /*<<< orphan*/  VectorCopy (float* const,float*) ; 
 float VectorLength (float* const) ; 
 int /*<<< orphan*/  VectorMA (float* const,float,float*,float* const) ; 
 int /*<<< orphan*/  VectorSubtract (float* const,float* const,float* const) ; 
 int /*<<< orphan*/  m4x4_transform_normal (int /*<<< orphan*/  const,float*) ; 
 int /*<<< orphan*/  m4x4_transform_point (int /*<<< orphan*/  const,float*) ; 
 scalar_t__ qtrue ; 

void ray_construct_for_vec3( ray_t *ray, const vec3_t origin, const vec3_t direction ){
	VectorCopy( origin, ray->origin );
	VectorCopy( direction, ray->direction );
}

void ray_transform( ray_t *ray, const m4x4_t matrix ){
	m4x4_transform_point( matrix, ray->origin );
	m4x4_transform_normal( matrix, ray->direction );
}

vec_t ray_intersect_point( const ray_t *ray, const vec3_t point, vec_t epsilon, vec_t divergence ){
	vec3_t displacement;
	vec_t depth;

	// calc displacement of test point from ray origin
	VectorSubtract( point, ray->origin, displacement );
	// calc length of displacement vector along ray direction
	depth = DotProduct( displacement, ray->direction );
	if ( depth < 0.0f ) {
		return (vec_t)VEC_MAX;
	}
	// calc position of closest point on ray to test point
	VectorMA( ray->origin, depth, ray->direction, displacement );
	// calc displacement of test point from closest point
	VectorSubtract( point, displacement, displacement );
	// calc length of displacement, subtract depth-dependant epsilon
	if ( VectorLength( displacement ) - ( epsilon + ( depth * divergence ) ) > 0.0f ) {
		return (vec_t)VEC_MAX;
	}
	return depth;
}

vec_t ray_intersect_triangle( const ray_t *ray, qboolean bCullBack, const vec3_t vert0, const vec3_t vert1, const vec3_t vert2 ){
	float edge1[3], edge2[3], tvec[3], pvec[3], qvec[3];
	float det,inv_det;
	float u, v;
	vec_t depth = (vec_t)VEC_MAX;

	/* find vectors for two edges sharing vert0 */
	VectorSubtract( vert1, vert0, edge1 );
	VectorSubtract( vert2, vert0, edge2 );

	/* begin calculating determinant - also used to calculate U parameter */
	CrossProduct( ray->direction, edge2, pvec );

	/* if determinant is near zero, ray lies in plane of triangle */
	det = DotProduct( edge1, pvec );

	if ( bCullBack == qtrue ) {
		if ( det < EPSILON ) {
			return depth;
		}

		// calculate distance from vert0 to ray origin
		VectorSubtract( ray->origin, vert0, tvec );

		// calculate U parameter and test bounds
		u = DotProduct( tvec, pvec );
		if ( u < 0.0 || u > det ) {
			return depth;
		}

		// prepare to test V parameter
		CrossProduct( tvec, edge1, qvec );

		// calculate V parameter and test bounds
		v = DotProduct( ray->direction, qvec );
		if ( v < 0.0 || u + v > det ) {
			return depth;
		}

		// calculate t, scale parameters, ray intersects triangle
		depth = DotProduct( edge2, qvec );
		inv_det = 1.0f / det;
		depth *= inv_det;
		//u *= inv_det;
		//v *= inv_det;
	}
	else
	{
		/* the non-culling branch */
		if ( det > -EPSILON && det < EPSILON ) {
			return depth;
		}
		inv_det = 1.0f / det;

		/* calculate distance from vert0 to ray origin */
		VectorSubtract( ray->origin, vert0, tvec );

		/* calculate U parameter and test bounds */
		u = DotProduct( tvec, pvec ) * inv_det;
		if ( u < 0.0 || u > 1.0 ) {
			return depth;
		}

		/* prepare to test V parameter */
		CrossProduct( tvec, edge1, qvec );

		/* calculate V parameter and test bounds */
		v = DotProduct( ray->direction, qvec ) * inv_det;
		if ( v < 0.0 || u + v > 1.0 ) {
			return depth;
		}

		/* calculate t, ray intersects triangle */
		depth = DotProduct( edge2, qvec ) * inv_det;
	}
	return depth;
}

