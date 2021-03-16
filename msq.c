#include <stdlib.h>
#include <stdio.h>
#include "msq.h"

struct msq_malloc_tracker* msq_malloc_tracker;

void v_reserve(struct vector *v,uint capacity)
{
	v->c = capacity;
	void ** old_arr = v->o;
	v->o = malloc(sizeof(v->o) * capacity);
	for (int i = 0; i < v->s && i < capacity; i++)
	{
		v->o[i] = old_arr[i];
	}
	free(old_arr);
}

void v_free(struct vector* v)
{
	for (int i = 0; i < v->s; i++)
		free(v->o[i]);
	free(v->o);
}

struct vector* v_create(uint capacity)
{
	struct vector* v = malloc(sizeof(*v));
	v_reserve(v, capacity);
	v->o = 0;
	return v;
}

struct vector* v_create_from_arr(void** a, uint s)
{
	struct vector* v = v_create(s);
	for (int i = 0; i < s; i++)
		v->o[i] = a[i];
	return v;
}

void v_append(struct vector* v, void * o)
{
	if(v->s + 1 > v->c)
		v_reserve(v, v->c + VECTOR_ADDED_CAPACITY);
	v->o[v->s] = o;
	v->s++;
}

void v_remove(struct vector* v, uint index)
{
	v->o[index] = NULL;
}

struct msq_malloc_tracker* get_malloc_tracker()
{
	if (msq_malloc_tracker == 0)
		init_msq_malloc_tracker();	
	return msq_malloc_tracker;
}

void init_msq_malloc_tracker()
{
	msq_malloc_tracker = malloc(sizeof(*msq_malloc_tracker));
}

void* msq_malloc(uint size, msq_malloc_index *index)
{
	void * a = malloc(size);

	if ((get_malloc_tracker()->flags & (1 << 0))!=0)
		printf("%s msq_malloc of address %8X of size %d \n", msq_info, a, size);
	v_append(&get_malloc_tracker()->v,a);
	if (index != 0)
		*index = get_malloc_tracker()->v.s-1;
	return a;
}

void* msq_malloc_at(msq_malloc_index index)
{
	return get_malloc_tracker()->v.o[index];
}

void msq_free(msq_malloc_index index)
{
	if ((get_malloc_tracker()->flags & (1 << 0))!=0)
		printf("%s msq_free of address %8X at index %d \n", msq_info, msq_malloc_at(index), index);
	free(msq_malloc_at(index));
	v_remove(&get_malloc_tracker()->v, index);
}

void msq_free_all()
{
	for(int i = 0; i < get_malloc_tracker()->v.s && get_malloc_tracker()->v.o[i] != NULL; i++)
		msq_free(i);
	v_free(&get_malloc_tracker()->v);
}