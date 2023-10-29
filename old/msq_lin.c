#include "msq_lin.h"

m2x2i m2x2i_init()
{
    return (m2x2i){{
        0,0,
        0,0
    }};
}
m2x2f m2x2f_init()
{
    return (m2x2f){{
        0.f,0.f,
        0.f,0.f
    }};
}
m3x3i m3x3i_init()
{
    return (m3x3i){{
        0,0,0,
        0,0,0,
        0,0,0
    }};
}
m3x3f m3x3f_init()
{
    return (m3x3f){{
        0.f,0.f,0.f,
        0.f,0.f,0.f,
        0.f,0.f,0.f
    }};
}
m4x4i m4x4i_init()
{
    return (m4x4i){{
        0,0,0,0,
        0,0,0,0,
        0,0,0,0,
        0,0,0,0
    }};
}
m4x4f m4x4f_init()
{
    return (m4x4f){{
        0.f,0.f,0.f,0.f,
        0.f,0.f,0.f,0.f,
        0.f,0.f,0.f,0.f,
        0.f,0.f,0.f,0.f
    }};
}

m2x2i m2x2i_id()
{
    return (m2x2i){{
        1,0,
        0,1
    }};
}
m2x2f m2x2f_id()
{
    return (m2x2f){{
        1.f,0.f,
        0.f,1.f
    }};
}
m3x3i m3x3i_id()
{
    return (m3x3i){{
        1,0,0,
        0,1,0,
        0,0,1
    }};
}
m3x3f m3x3f_id()
{
    return (m3x3f){{
        1.f,0.f,0.f,
        0.f,1.f,0.f,
        0.f,0.f,1.f
    }};
}
m4x4i m4x4i_id()
{
    return (m4x4i){{
        1,0,0,0,
        0,1,0,0,
        0,0,1,0,
        0,0,0,1
    }};
}
m4x4f m4x4f_id()
{
    return (m4x4f){{
        1.f,0.f,0.f,0.f,
        0.f,1.f,0.f,0.f,
        0.f,0.f,1.f,0.f,
        0.f,0.f,0.f,1.f
    }};
}


v2i m2x2i_get_row(m2x2i* m, uint p)
{
    v2i v;
    v.x = m->v[p*2];
    v.y = m->v[p*2+1];
    return v;
}
v2f m2x2f_get_row(m2x2f* m, uint p)
{
    v2f v;
    v.x = m->v[p*2];
    v.y = m->v[p*2+1];
    return v;
}

v3i m3x3i_get_row(m3x3i* m, uint p)
{
    v3i v;
    v.x = m->v[p*3];
    v.y = m->v[p*3+1];
    v.z = m->v[p*3+2];
    return v;
}

v3f m3x3f_get_row(m3x3f* m, uint p)
{
    v3f v;
    v.x = m->v[p*3];
    v.y = m->v[p*3+1];
    v.z = m->v[p*3+2];
    return v;
}

v4i m4x4i_get_row(m4x4i* m, uint p)
{
    v4i v;
    v.x = m->v[p*4];
    v.y = m->v[p*4+1];
    v.z = m->v[p*4+2];
    v.w = m->v[p*4+3];
    return v;
}

v4f m4x4f_get_row(m4x4f* m, uint p)
{
    v4f v;
    v.x = m->v[p*4];
    v.y = m->v[p*4+1];
    v.z = m->v[p*4+2];
    v.w = m->v[p*4+3];
    return v;
}

v2i m2x2i_get_col(m2x2i* m, uint p)
{
    v2i v;
    v.x = m->v[p];
    v.y = m->v[p+2];
    return v;
}
v2f m2x2f_get_col(m2x2f* m, uint p)
{
    v2f v;
    v.x = m->v[p];
    v.y = m->v[p+2];
    return v;
}

v3i m3x3i_get_col(m3x3i* m, uint p)
{
    v3i v;
    v.x = m->v[p];
    v.y = m->v[p+3];
    v.z = m->v[p+6];
    return v;
}

v3f m3x3f_get_col(m3x3f* m, uint p)
{
    v3f v;
    v.x = m->v[p];
    v.y = m->v[p+3];
    v.z = m->v[p+6];
    return v;
}

v4i m4x4i_get_col(m4x4i* m, uint p)
{
    v4i v;
    v.x = m->v[p];
    v.y = m->v[p+4];
    v.z = m->v[p+8];
    v.w = m->v[p+12];
    return v;
}

v4f m4x4f_get_col(m4x4f* m, uint p)
{
    v4f v;
    v.x = m->v[p];
    v.y = m->v[p+4];
    v.z = m->v[p+8];
    v.w = m->v[p+12];
    return v;
}


void m2x2i_mult(m2x2i* m, int k)
{
    for(int i = 0; i < 4; i++)
        m->v[i] = m->v[i] * k;
}
void m2x2f_mult(m2x2f* m, float k)
{
    for(int i = 0; i < 4; i++)
        m->v[i] = m->v[i] * k;
}

void m3x3i_mult(m3x3i* m, int k)
{
    for(int i = 0; i < 9; i++)
        m->v[i] = m->v[i] * k;
}

void m3x3f_mult(m3x3f* m, float k)
{
    for(int i = 0; i < 9; i++)
        m->v[i] = m->v[i] * k;
}

void m4x4i_mult(m4x4i* m, int k)
{
    for(int i = 0; i < 16; i++)
        m->v[i] = m->v[i] * k;
}

void m4x4f_mult(m4x4f* m, float k)
{
    for(int i = 0; i < 16; i++)
        m->v[i] = m->v[i] * k;
}

int m2x2i_get(m2x2i* m, v2i p)
{
    return m->v[p.x + p.y * 2];
}
float m2x2f_get(m2x2f* m, v2i p)
{
    return m->v[p.x + p.y * 2];
}

int m3x3i_get(m3x3i* m, v2i p)
{
    return m->v[p.x + p.y * 3];
}

float m3x3f_get(m3x3f* m, v2i p)
{
    return m->v[p.x + p.y * 3];
}

int m4x4i_get(m4x4i* m, v2i p)
{
    return m->v[p.x + p.y * 4];
}

float m4x4f_get(m4x4f* m, v2i p)
{
    return m->v[p.x + p.y * 4];
}

void m2x2i_set(m2x2i* m, v2i p, int v)
{
    m->v[p.x + p.y * 2] = v;
}
void m2x2f_set(m2x2f* m, v2i p, float v)
{
    m->v[p.x + p.y * 2] = v;
}

void m3x3i_set(m3x3i* m, v2i p, int v)
{
    m->v[p.x + p.y * 3] = v;
}

void m3x3f_set(m3x3f* m, v2i p, float v)
{
    m->v[p.x + p.y * 3] = v;
}

void m4x4i_set(m4x4i* m, v2i p, int v)
{
    m->v[p.x + p.y * 4] = v;
}

void m4x4f_set(m4x4f* m, v2i p, float v)
{
    m->v[p.x + p.y * 4] = v;
}


