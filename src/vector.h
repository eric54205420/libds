#ifndef VECTOR_H
#define VECTOR_H

#include "iterator.h"
#include <stdbool.h>
#include <stdlib.h>

struct vector {
    void **items;
    size_t length;
    size_t capacity;
};

struct vector *vector_create(void);

void vector_destroy(struct vector *this);

struct vector *vector_clone(struct vector *this);

void *vector_get(struct vector *this, size_t index);

void *vector_set(struct vector *this, size_t index, void *item);

void *vector_remove(struct vector *this, size_t index);

struct vector *vector_slice(struct vector *this, size_t start, size_t end);

bool vector_insert(struct vector *this, size_t index, void *item);

struct iterator *vector_iterator(struct vector *this);

bool vector_concat(struct vector *this, struct vector *other);

void vector_clear(struct vector *this);

void *vector_shift(struct vector *this);

bool vector_unshift(struct vector *this, void *item);

bool vector_push(struct vector *this, void *item);

void *vector_pop(struct vector *this);

void vector_sort(struct vector *this,
                 int (*comparator)(const void *, const void *));

#endif
