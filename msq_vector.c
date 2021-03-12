#include "msq_vector.h"
#include <math.h>

// v2i

float v2i_length(struct vector2i v)
{
	return sqrt(v.x*v.x+ v.y*v.y);
}

struct vector2i v2i_add(struct vector2i v1, struct vector2i v2)
{
	return (struct vector2i) {v1.x + v2.x, v1.y + v2.y};
}

struct vector2i v2i_mult(struct vector2i v, int k)
{
	return (struct vector2i){v.x * k,v.y * k};
}

struct vector2f v2i_to_v2f(struct vector2i v)
{
	return (struct vector2f){v.x,v.y};
}

struct vector2f v2i_normalised(struct vector2i v)
{
	float l = v2i_length(v);
	return (struct vector2f) {(float)v.x / l, (float)v.y / l};
}

// v2f

float v2f_length(struct vector2f v)
{
	return sqrt(v.x*v.x+ v.y*v.y);
}

struct vector2f v2f_add(struct vector2f v1, struct vector2f v2)
{
	return (struct vector2f) {v1.x + v2.x, v1.y + v2.y};
}

struct vector2f v2f_mult(struct vector2f v, float k)
{
	return (struct vector2f){v.x * k,v.y * k};
}

struct vector2f v2f_normalised(struct vector2f v)
{
	float l = v2f_length(v);
	return (struct vector2f) {v.x / l, v.y / l};
}


// v3i

float v3i_length(struct vector3i v)
{
	return sqrt( v.x*v.x + v.y*v.y + v.z*v.z);
}

struct vector3i v3i_add(struct vector3i v1, struct vector3i v2)
{
	return (struct vector3i) {v1.x + v2.x, v1.y + v2.y, v1.z + v2.z};
}

struct vector3i v3i_mult(struct vector3i v, int k)
{
	return (struct vector3i){v.x * k,v.y * k,v.z * k};
}

struct vector3f v3i_to_v3f(struct vector3i v)
{
	return (struct vector3f){v.x,v.y,v.z};
}

struct vector3f v3i_normalised(struct vector3i v)
{
	float l = v3i_length(v);
	return (struct vector3f) {(float)v.x / l, (float)v.y / l, (float)v.z / l};
}

// v3f

float v3f_length(struct vector3f v)
{
	return sqrt( v.x*v.x + v.y*v.y + v.z*v.z);
}
struct vector3f v3f_add(struct vector3f v1, struct vector3f v2)
{
	return (struct vector3f) {v1.x + v2.x, v1.y + v2.y, v1.z + v2.z};
}

struct vector3f v3f_mult(struct vector3f v, float k)
{
	return (struct vector3f){v.x * k,v.y * k,v.z * k};
}

struct vector3i v3f_to_v3i(struct vector3f v)
{
	return (struct vector3i){v.x,v.y,v.z};
}

struct vector3f v3f_normalised(struct vector3f v)
{
	float l = v3f_length(v);
	return (struct vector3f) {v.x / l, v.y / l, v.z / l};
}

// v4i

float v4i_length(struct vector4i v)
{
	return sqrt( v.x*v.x + v.y*v.y + v.z*v.z + v.w*v.w);
}

struct vector4i v4i_add(struct vector4i v1, struct vector4i v2)
{
	return (struct vector4i) {v1.x + v2.x, v1.y + v2.y, v1.z + v2.z, v1.w + v2.w};
}
struct vector4i v4i_mult(struct vector4i v, int k)
{
	return (struct vector4i){v.x * k,v.y * k,v.z * k,v.w * k};
}

struct vector4f v4i_to_v4f(struct vector4i v)
{
	return (struct vector4f){v.x,v.y,v.z,v.w};
}

struct vector4f v4i_normalised(struct vector4i v)
{
	float l = v4i_length(v);
	return (struct vector4f) {(float)v.x / l, (float)v.y / l, (float)v.z / l, (float)v.w / l};
}

// v4f

float v4f_length(struct vector4f v)
{
	return sqrt( v.x*v.x + v.y*v.y + v.z*v.z + v.w*v.w);
}

struct vector4f v4f_add(struct vector4f v1, struct vector4f v2)
{
	return (struct vector4f) {v1.x + v2.x, v1.y + v2.y, v1.z + v2.z, v1.w + v2.w};
}

struct vector4f v4f_mult(struct vector4f v, float k)
{
	return (struct vector4f){v.x * k,v.y * k,v.z * k,v.w * k};
}

struct vector4i v4f_to_v4i(struct vector4f v)
{
	return (struct vector4i){v.x,v.y,v.z,v.w};
}

struct vector4f v4f_normalised(struct vector4f v)
{
	float l = v4f_length(v);
	return (struct vector4f) {v.x / l, v.y / l, v.z / l, v.w / l};
}