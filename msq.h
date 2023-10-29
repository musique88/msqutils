// Author: William Bouillon
//
// Guidelines:
// 1. Always return an int
// 2. Keep every object self contained
// 3. Separate objects and sections with a comment that looks like
// Section: <section>


#pragma once

#define msq_info "[INFO]"
#define msq_warn "\033[93m[WARNING]\033[0m"
#define msq_erro "\033[1;31m[ERROR]\033[0m"

#ifdef MSQ_IMPL
#include <stdlib.h>
#include <stdio.h>
#endif

typedef unsigned char uchar;
typedef unsigned int uint;

#define VECTOR_ADDED_CAPACITY 5

// Section: VECTORS OF VOID*
typedef struct{
	void ** objects;
	uint size;
	uint capacity;
} msq_vector;

int v_reserve(msq_vector *v, uint capacity);
int v_free(msq_vector *v);
int v_create(msq_vector* v, uint capacity);
int v_create_from_arr(msq_vector* v, void** a, uint s);
int v_insert(msq_vector* v, void * o, uint index);
int v_append(msq_vector* v, void * o);
int v_remove(msq_vector* v, uint index);
int v_fill(msq_vector* v, void * o, uint start_index, uint nb_of_times);

#ifdef MSQ_IMPL
int v_reserve(msq_vector *v, uint capacity)
{
	v->capacity = capacity;
	v->objects = realloc(v->objects, sizeof(*v->objects) * capacity);
    return 0;
}

int v_free(msq_vector* v)
{
	for (uint i = 0; i < v->size; i++)
		free(v->objects[i]);
	free(v->objects);
	free(v);
    return 0;
}

int v_create(msq_vector* v, uint capacity)
{
	v = malloc(sizeof(*v));
	v->objects = 0;
	v->size = 0;
	v_reserve(v, capacity);
	return 0;
}

int v_create_from_arr(msq_vector* v, void** a, uint s)
{
	v = v_create(s);
	for (uint i = 0; i < s; i++)
        v_append(a[i]);
	v->size = s;
	return 0;
}

int v_insert(msq_vector* v, void * o, uint index)
{
	if(v->size + 1 > v->capacity)
		v_reserve(v, v->capacity + VECTOR_ADDED_CAPACITY);
    memcpy(v->objects + index + 1, v->objects + index, v->size - index);
	v->size++;
    return 0;
}

int v_append(msq_vector* v, void * o)
{
	if(v->size + 1 > v->capacity)
		v_reserve(v, v->capacity + VECTOR_ADDED_CAPACITY);
	v->objects[v->size] = o;
	v->size++;
    return 0;
}

int v_remove(msq_vector* v, uint index)
{
	for (uint i = index; i < v->size; i++)
		v->objects[i] = v->objects[i + 1];
	v->size--;
    return 0;
}

int v_fill(msq_vector* v, void * o, uint start_index, uint nb_of_times)
{
	for (uint i = start_index; i < start_index + nb_of_times; i++)
		v->objects[i] = o;
    return 0;
}
#endif


// Section: STRINGS
typedef struct{
	char* characters;
	uint size;
	uint capacity;
} msq_string;

int str_reserve(msq_string *s, uint capacity);
int str_free(msq_string *s);
int str_create(msq_vector* s, uint capacity);
int str_create_from(msq_vector* s, char* c);
int str_insert(msq_string* s, char* o, uint index);
int str_append(msq_string* s, char* o);
int str_remove(msq_string* s, uint index_start, uint index_stop);
int str_fill(msq_string* s, char o, uint start_index, uint nb_of_times);

#ifdef MSQ_IMPL

int str_reserve(msq_string *s, uint capacity) {
	s->capacity = capacity;
	s->characters = realloc(s->characters, sizeof(*s->characters) * capacity);
    return 0;
}

int str_free(msq_string *s) {
	free(s->characters);
	free(s);
    return 0;
}

int str_create(msq_vector* s, uint capacity) {
	s = malloc(sizeof(*v));
	s->characters = 0;
	s->size = 0;
	str_reserve(s, capacity);
    return 0;
}

int str_create_from(msq_vector* s, char* c) {
    str_create(strlen(c));
    str_append(s, c);
}

int str_insert(msq_string* s, char* o, uint index) {
    unsigned int c_len = strlen(o;
	if(s->size + c_len > s->capacity)
		str_reserve(s, s->size + c_len + VECTOR_ADDED_CAPACITY);
    memcpy(s->characters + index + c_len, s->characters + index, s->size-index);
    memcpy(s->characters + index, o, c_len);
    return 0
}

int str_append(msq_string* s, char* o) {
    unsigned int c_len = strlen(o;
	if(s->size + c_len > s->capacity)
		str_reserve(s, s->size + c_len + VECTOR_ADDED_CAPACITY);
    memcpy(s->characters + s->size, o, c_len);
	s->size += c_len;
    return 0;
}

int str_remove(msq_string* s, uint index_start, uint index_stop) {
    unsigned int removed_size = index_stop - index_start;
    memcpy(s->characters + index_stop, 
            s->characters + index_start, 
            s->size - index_stop);
    s->size -= index_stop - index_start;
    return 0;
}

int str_fill(msq_string* s, char o, uint start_index, uint nb_of_times) {
    if(start_index + nb_of_times > s->capacity)
		str_reserve(s, s->size + nb_of_times + VECTOR_ADDED_CAPACITY);
    for(int i = 0; i < nb_of_times; i++) {
        s->characters[start_index + i] = o;
    }
    return 0;
}

#endif

