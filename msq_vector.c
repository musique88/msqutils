#include "msq_vector.h"
#include <math.h>

// v2i

float v2i_length(v2i v)
{
	return sqrt(v.x*v.x+ v.y*v.y);
}

v2i v2i_add(v2i v1, v2i v2)
{
	return (v2i) {v1.x + v2.x, v1.y + v2.y};
}

v2i v2i_mult(v2i v, int k)
{
	return (v2i){v.x * k,v.y * k};
}

v2f v2i_to_v2f(v2i v)
{
	return (v2f){v.x,v.y};
}

v2f v2i_normalised(v2i v)
{
	float l = v2i_length(v);
	return (v2f) {(float)v.x / l, (float)v.y / l};
}

// v2f

float v2f_length(v2f v)
{
	return sqrt(v.x*v.x+ v.y*v.y);
}

v2f v2f_add(v2f v1, v2f v2)
{
	return (v2f) {v1.x + v2.x, v1.y + v2.y};
}

v2f v2f_mult(v2f v, float k)
{
	return (v2f){v.x * k,v.y * k};
}

v2f v2f_normalised(v2f v)
{
	float l = v2f_length(v);
	return (v2f) {v.x / l, v.y / l};
}


// v3i

float v3i_length(v3i v)
{
	return sqrt( v.x*v.x + v.y*v.y + v.z*v.z);
}

v3i v3i_add(v3i v1, v3i v2)
{
	return (v3i) {v1.x + v2.x, v1.y + v2.y, v1.z + v2.z};
}

v3i v3i_mult(v3i v, int k)
{
	return (v3i){v.x * k,v.y * k,v.z * k};
}

v3f v3i_to_v3f(v3i v)
{
	return (v3f){v.x,v.y,v.z};
}

v3f v3i_normalised(v3i v)
{
	float l = v3i_length(v);
	return (v3f) {(float)v.x / l, (float)v.y / l, (float)v.z / l};
}

// v3f

float v3f_length(v3f v)
{
	return sqrt( v.x*v.x + v.y*v.y + v.z*v.z);
}
v3f v3f_add(v3f v1, v3f v2)
{
	return (v3f) {v1.x + v2.x, v1.y + v2.y, v1.z + v2.z};
}

v3f v3f_mult(v3f v, float k)
{
	return (v3f){v.x * k,v.y * k,v.z * k};
}

v3i v3f_to_v3i(v3f v)
{
	return (v3i){v.x,v.y,v.z};
}

v3f v3f_normalised(v3f v)
{
	float l = v3f_length(v);
	return (v3f) {v.x / l, v.y / l, v.z / l};
}

// v4i

float v4i_length(v4i v)
{
	return sqrt( v.x*v.x + v.y*v.y + v.z*v.z + v.w*v.w);
}

v4i v4i_add(v4i v1, v4i v2)
{
	return (v4i) {v1.x + v2.x, v1.y + v2.y, v1.z + v2.z, v1.w + v2.w};
}
v4i v4i_mult(v4i v, int k)
{
	return (v4i){v.x * k,v.y * k,v.z * k,v.w * k};
}

v4f v4i_to_v4f(v4i v)
{
	return (v4f){v.x,v.y,v.z,v.w};
}

v4f v4i_normalised(v4i v)
{
	float l = v4i_length(v);
	return (v4f) {(float)v.x / l, (float)v.y / l, (float)v.z / l, (float)v.w / l};
}

// v4f

float v4f_length(v4f v)
{
	return sqrt( v.x*v.x + v.y*v.y + v.z*v.z + v.w*v.w);
}

v4f v4f_add(v4f v1, v4f v2)
{
	return (v4f) {v1.x + v2.x, v1.y + v2.y, v1.z + v2.z, v1.w + v2.w};
}

v4f v4f_mult(v4f v, float k)
{
	return (v4f){v.x * k,v.y * k,v.z * k,v.w * k};
}

v4i v4f_to_v4i(v4f v)
{
	return (v4i){v.x,v.y,v.z,v.w};
}

v4f v4f_normalised(v4f v)
{
	float l = v4f_length(v);
	return (v4f) {v.x / l, v.y / l, v.z / l, v.w / l};
}
