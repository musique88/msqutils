struct vector2i {
	int x,y;
};

struct vector3i {
	int x,y,z;
};

struct vector4i {
	int x,y,z,w;
};

struct vector2f{
	float x,y;
};

struct vector3f {
	float x,y,z;
};

struct vector4f {
	float x,y,z,w;
};

// v2i

float v2i_length(struct vector2i v);
struct vector2i v2i_add(struct vector2i v1, struct vector2i v2);
struct vector2i v2i_mult(struct vector2i v, int k);
struct vector2f v2i_to_v2f(struct vector2i v);

// v2f

float v2f_length(struct vector2f v);
struct vector2f v2f_add(struct vector2f v1, struct vector2f v2);
struct vector2f v2f_mult(struct vector2f v, float k);
struct vector2i v2f_to_v2i(struct vector2f v);

// v3i

float v3i_length(struct vector3i v);
struct vector3i v3i_add(struct vector3i v1, struct vector3i v2);
struct vector3i v3i_mult(struct vector3i v, int k);
struct vector3f v3i_to_v3f(struct vector3i v);

// v3f

float v3f_length(struct vector3f v);
struct vector3f v3f_add(struct vector3f v1, struct vector3f v2);
struct vector3f v3f_mult(struct vector3f v, float k);
struct vector3i v3f_to_v3i(struct vector3f v);

// v4i

float v4i_length(struct vector4i v);
struct vector4i v4i_add(struct vector4i v1, struct vector4i v2);
struct vector4i v4i_mult(struct vector4i v, int k);
struct vector4f v4i_to_v4f(struct vector4i v);

// v4f

float v4f_length(struct vector4f v);
struct vector4f v4f_add(struct vector4f v1, struct vector4f v2);
struct vector4f v4f_mult(struct vector4f v, float k);
struct vector4i v4f_to_v4i(struct vector4f v);