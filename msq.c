#include <stdlib.h>
#include <stdio.h>
#include "msq.h"

void v_reserve(struct vector *v,uint capacity)
{
	v->capacity = capacity;
	void ** old_arr = v->objects;
	v->objects = malloc(sizeof(v->objects) * capacity);
	for (int i = 0; i < v->size && i < capacity; i++)
	{
		v->objects[i] = old_arr[i];
	}
	free(old_arr);
}

void v_free(struct vector* v)
{
	free(v->objects);
}

struct vector v_create(uint capacity)
{
	struct vector v;
	v_reserve(&v, capacity);
	v.objects = (void*)0;
	return v;
}

struct vector v_create_from_arr(void** a, uint s)
{
	struct vector v = v_create(s);
	for (int i = 0; i < s; i++)
		v.objects = a[i];
	return v;
}

void v_append(struct vector* v, void * o)
{
	if(v->size + 1 > v->capacity)
		v_reserve(v, v->capacity + VECTOR_ADDED_CAPACITY);
	v->objects[v->size] = o;
	v->size++;
}

void v_remove(struct vector* v, uint index)
{
	v->objects[index] = NULL;
}

void * msq_malloc(struct msq_malloc_tracker *tracker, uint size, msq_malloc_index *index)
{
	void * a = malloc(size);

	if ((tracker->flags & (1 << 0))!=0)
		printf("%s msq_malloc of address %8X of size %d \n", msq_info, a, size);
	v_append(&tracker->v, a);
	*index = tracker->v.size-1;
	return a;
}

void * msq_malloc_at(struct msq_malloc_tracker *tracker, msq_malloc_index index)
{
	return tracker->v.objects[index];
}

void msq_free(struct msq_malloc_tracker *tracker, msq_malloc_index index)
{
	if ((tracker->flags & (1 << 0))!=0)
		printf("%s msq_free of address %8X at index %d \n", msq_info, msq_malloc_at(tracker,index), index);
	free(msq_malloc_at(tracker, index));
	v_remove(&tracker->v, index);
}

void msq_free_all(struct msq_malloc_tracker *tracker)
{
	for(int i = 0; i < tracker->v.size && tracker->v.objects[i] != NULL; i++)
		msq_free(tracker, i);
	v_free(&tracker->v);
}