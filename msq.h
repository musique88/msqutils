#pragma once

#define msq_info "[INFO]"
#define msq_warn "\033[93m[WARNING]\033[0m"
#define msq_erro "\033[1;31m[ERROR]\033[0m"

typedef unsigned char uchar;
typedef unsigned int uint;

#define VECTOR_ADDED_CAPACITY 5

typedef struct{
	void ** o;
	uint s;
	uint c;
} msq_vector;

void v_reserve(msq_vector *v, uint capacity);
void v_free(msq_vector *v);
msq_vector* v_create(uint capacity);
msq_vector* v_create_from_arr(void** a, uint s);
void v_insert(msq_vector* v, void * o, uint index);
void v_append(msq_vector* v, void * o);
void v_remove(msq_vector* v, uint index);
void v_fill(msq_vector* v, void * o, uint start_index, uint nb_of_times);

