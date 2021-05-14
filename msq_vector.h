typedef struct{
	int x,y;
} vector2i;

typedef struct {
	int x,y,z;
} vector3i;

typedef struct {
	int x,y,z,w;
}vector4i;

typedef struct{
	float x,y;
}vector2f;

typedef struct {
	float x,y,z;
}vector3f;

typedef struct {
	float x,y,z,w;
}vector4f;

// v2i

float v2i_length(vector2i v);
vector2i v2i_add(vector2i v1,  vector2i v2);
vector2i v2i_mult(vector2i v, int k);
vector2f v2i_to_v2f(vector2i v);

// v2f

float v2f_length(vector2f v);
vector2f v2f_add(vector2f v1, vector2f v2);
vector2f v2f_mult(vector2f v, float k);
vector2i v2f_to_v2i(vector2f v);

// v3i

float v3i_length(vector3i v);
vector3i v3i_add(vector3i v1, vector3i v2);
vector3i v3i_mult(vector3i v, int k);
vector3f v3i_to_v3f(vector3i v);

// v3f

float v3f_length(vector3f v);
vector3f v3f_add(vector3f v1, vector3f v2);
vector3f v3f_mult(vector3f v, float k);
vector3i v3f_to_v3i(vector3f v);

// v4i

float v4i_length(vector4i v);
vector4i v4i_add(vector4i v1, vector4i v2);
vector4i v4i_mult(vector4i v, int k);
vector4f v4i_to_v4f(vector4i v);

// v4f

float v4f_length(vector4f v);
vector4f v4f_add(vector4f v1,vector4f v2);
vector4f v4f_mult(vector4f v, float k);
vector4i v4f_to_v4i(vector4f v);