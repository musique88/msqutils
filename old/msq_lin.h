#pragma once

#include "msq_vector.h"
#include "msq.h"

typedef struct {
    int v[4];
} m2x2i;

typedef struct {
    float v[4];
} m2x2f;

typedef struct {
    int v[9];
} m3x3i;

typedef struct {
    float v[9];
} m3x3f;

typedef struct {
    int v[16];
} m4x4i;

typedef struct {
    float v[16];
} m4x4f;

m2x2i m2x2i_init();
m2x2f m2x2f_init();
m3x3i m3x3i_init();
m3x3f m3x3f_init();
m4x4i m4x4i_init();
m4x4f m4x4f_init();

m2x2i m2x2i_id();
m2x2f m2x2f_id();
m3x3i m3x3i_id();
m3x3f m3x3f_id();
m4x4i m4x4i_id();
m4x4f m4x4f_id();

void m2x2i_id_f(m2x2i* m);
void m2x2f_id_f(m2x2f* m);
void m3x3i_id_f(m3x3i* m);
void m3x3f_id_f(m3x3f* m);
void m4x4i_id_f(m4x4i* m);
void m4x4f_id_f(m4x4f* m);

v2i m2x2i_get_row(m2x2i* m, uint p);
v2f m2x2f_get_row(m2x2f* m, uint p);
v3i m3x3i_get_row(m3x3i* m, uint p);
v3f m3x3f_get_row(m3x3f* m, uint p);
v4i m4x4i_get_row(m4x4i* m, uint p);
v4f m4x4f_get_row(m4x4f* m, uint p);

v2i m2x2i_get_col(m2x2i* m, uint p);
v2f m2x2f_get_col(m2x2f* m, uint p);
v3i m3x3i_get_col(m3x3i* m, uint p);
v3f m3x3f_get_col(m3x3f* m, uint p);
v4i m4x4i_get_col(m4x4i* m, uint p);
v4f m4x4f_get_col(m4x4f* m, uint p);

void m2x2i_mult(m2x2i* m, int k);
void m2x2f_mult(m2x2f* m, float k);
void m3x3i_mult(m3x3i* m, int k);
void m3x3f_mult(m3x3f* m, float k);
void m4x4i_mult(m4x4i* m, int k);
void m4x4f_mult(m4x4f* m, float k);

int m2x2i_get(m2x2i* m, v2i p);
float m2x2f_get(m2x2f* m, v2i p);
int m3x3i_get(m3x3i* m, v2i p);
float m3x3f_get(m3x3f* m, v2i p);
int m4x4i_get(m4x4i* m, v2i p);
float m4x4f_get(m4x4f* m, v2i p);

void m2x2i_set(m2x2i* m, v2i p, int v);
void m2x2f_set(m2x2f* m, v2i p, float v);
void m3x3i_set(m3x3i* m, v2i p, int v);
void m3x3f_set(m3x3f* m, v2i p, float v);
void m4x4i_set(m4x4i* m, v2i p, int v);
void m4x4f_set(m4x4f* m, v2i p, float v);


