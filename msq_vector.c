#include "msq_vector.h"
#include <math.h>

// v2i

float v2i_length(vector2i v)
{
	return sqrt(v.x*v.x+ v.y*v.y);
}

vector2i v2i_add(vector2i v1, vector2i v2)
{
	return (vector2i) {v1.x + v2.x, v1.y + v2.y};
}

vector2i v2i_mult(vector2i v, int k)
{
	return (vector2i){v.x * k,v.y * k};
}

vector2f v2i_to_v2f(vector2i v)
{
	return (vector2f){v.x,v.y};
}

vector2f v2i_normalised(vector2i v)
{
	float l = v2i_length(v);
	return (vector2f) {(float)v.x / l, (float)v.y / l};
}

// v2f

float v2f_length(vector2f v)
{
	return sqrt(v.x*v.x+ v.y*v.y);
}

vector2f v2f_add(vector2f v1, vector2f v2)
{
	return (vector2f) {v1.x + v2.x, v1.y + v2.y};
}

vector2f v2f_mult(vector2f v, float k)
{
	return (vector2f){v.x * k,v.y * k};
}

vector2f v2f_normalised(vector2f v)
{
	float l = v2f_length(v);
	return (vector2f) {v.x / l, v.y / l};
}


// v3i

float v3i_length(vector3i v)
{
	return sqrt( v.x*v.x + v.y*v.y + v.z*v.z);
}

vector3i v3i_add(vector3i v1, vector3i v2)
{
	return (vector3i) {v1.x + v2.x, v1.y + v2.y, v1.z + v2.z};
}

vector3i v3i_mult(vector3i v, int k)
{
	return (vector3i){v.x * k,v.y * k,v.z * k};
}

vector3f v3i_to_v3f(vector3i v)
{
	return (vector3f){v.x,v.y,v.z};
}

vector3f v3i_normalised(vector3i v)
{
	float l = v3i_length(v);
	return (vector3f) {(float)v.x / l, (float)v.y / l, (float)v.z / l};
}

// v3f

float v3f_length(vector3f v)
{
	return sqrt( v.x*v.x + v.y*v.y + v.z*v.z);
}
vector3f v3f_add(vector3f v1, vector3f v2)
{
	return (vector3f) {v1.x + v2.x, v1.y + v2.y, v1.z + v2.z};
}

vector3f v3f_mult(vector3f v, float k)
{
	return (vector3f){v.x * k,v.y * k,v.z * k};
}

vector3i v3f_to_v3i(vector3f v)
{
	return (vector3i){v.x,v.y,v.z};
}

vector3f v3f_normalised(vector3f v)
{
	float l = v3f_length(v);
	return (vector3f) {v.x / l, v.y / l, v.z / l};
}

// v4i

float v4i_length(vector4i v)
{
	return sqrt( v.x*v.x + v.y*v.y + v.z*v.z + v.w*v.w);
}

vector4i v4i_add(vector4i v1, vector4i v2)
{
	return (vector4i) {v1.x + v2.x, v1.y + v2.y, v1.z + v2.z, v1.w + v2.w};
}
vector4i v4i_mult(vector4i v, int k)
{
	return (vector4i){v.x * k,v.y * k,v.z * k,v.w * k};
}

vector4f v4i_to_v4f(vector4i v)
{
	return (vector4f){v.x,v.y,v.z,v.w};
}

vector4f v4i_normalised(vector4i v)
{
	float l = v4i_length(v);
	return (vector4f) {(float)v.x / l, (float)v.y / l, (float)v.z / l, (float)v.w / l};
}

// v4f

float v4f_length(vector4f v)
{
	return sqrt( v.x*v.x + v.y*v.y + v.z*v.z + v.w*v.w);
}

vector4f v4f_add(vector4f v1, vector4f v2)
{
	return (vector4f) {v1.x + v2.x, v1.y + v2.y, v1.z + v2.z, v1.w + v2.w};
}

vector4f v4f_mult(vector4f v, float k)
{
	return (vector4f){v.x * k,v.y * k,v.z * k,v.w * k};
}

vector4i v4f_to_v4i(vector4f v)
{
	return (vector4i){v.x,v.y,v.z,v.w};
}

vector4f v4f_normalised(vector4f v)
{
	float l = v4f_length(v);
	return (vector4f) {v.x / l, v.y / l, v.z / l, v.w / l};
}