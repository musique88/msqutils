#include <stdlib.h>
#include <stdio.h>
#include "msq.h"

void v_reserve(msq_vector *v, uint capacity)
{
	v->c = capacity;
	void ** old_arr = v->o;
	v->o = malloc(sizeof(*v->o) * capacity);
	if (old_arr != 0)
		for (uint i = 0; i < v->s && i < capacity; i++)
			v->o[i] = old_arr[i];
	free(old_arr);
}

void v_free(msq_vector* v)
{
	for (uint i = 0; i < v->s; i++)
		free(v->o[i]);
	free(v->o);
	free(v);
}

msq_vector* v_create(uint capacity)
{
	msq_vector* v = malloc(sizeof(*v));
	v->o = 0;
	v->s = 0;
	v_reserve(v, capacity);
	return v;
}

msq_vector* v_create_from_arr(void** a, uint s)
{
	msq_vector* v = v_create(s);
	for (uint i = 0; i < s; i++)
		v->o[i] = a[i];
	v->s = s;
	return v;
}

void v_insert(msq_vector* v, void * o, uint index)
{
	void ** arr = v->o;
	v->c = (v->s + 1 > v->c ? v->c + VECTOR_ADDED_CAPACITY: v->c);
	v->o = malloc(sizeof(*v->o) * v->c);
	for (uint i = 0; i < index; i++)
		v->o[i] = arr[i];
	v->o[index] = o;
	for (uint i = index + 1; i < v->s + 1; i++)
		v->o[i] = arr[i - 1];
	free(arr);
	v->s++;
}

void v_append(msq_vector* v, void * o)
{
	if(v->s + 1 > v->c)
		v_reserve(v, v->c + VECTOR_ADDED_CAPACITY);
	v->o[v->s] = o;
	v->s++;
}

void v_remove(msq_vector* v, uint index)
{
	for (uint i = index; i < v->s; i++)
		v->o[i] = v->o[i + 1];
	v->s--;
}

void v_fill(msq_vector* v, void * o, uint start_index, uint nb_of_times)
{
	for (uint i = start_index; i < start_index + nb_of_times; i++)
		v->o[i] = o;
}
