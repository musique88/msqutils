#pragma once

typedef struct{
	int x,y;
} v2i;

typedef struct {
	int x,y,z;
} v3i;

typedef struct {
	int x,y,z,w;
}v4i;

typedef struct{
	float x,y;
}v2f;

typedef struct {
	float x,y,z;
}v3f;

typedef struct {
	float x,y,z,w;
}v4f;

// v2i

float v2i_length(v2i v);
v2i v2i_add(v2i v1,  v2i v2);
v2i v2i_mult(v2i v, int k);
v2f v2i_to_v2f(v2i v);

// v2f

float v2f_length(v2f v);
v2f v2f_add(v2f v1, v2f v2);
v2f v2f_mult(v2f v, float k);
v2i v2f_to_v2i(v2f v);

// v3i

float v3i_length(v3i v);
v3i v3i_add(v3i v1, v3i v2);
v3i v3i_mult(v3i v, int k);
v3f v3i_to_v3f(v3i v);

// v3f

float v3f_length(v3f v);
v3f v3f_add(v3f v1, v3f v2);
v3f v3f_mult(v3f v, float k);
v3i v3f_to_v3i(v3f v);

// v4i

float v4i_length(v4i v);
v4i v4i_add(v4i v1, v4i v2);
v4i v4i_mult(v4i v, int k);
v4f v4i_to_v4f(v4i v);

// v4f

float v4f_length(v4f v);
v4f v4f_add(v4f v1,v4f v2);
v4f v4f_mult(v4f v, float k);
v4i v4f_to_v4i(v4f v);
