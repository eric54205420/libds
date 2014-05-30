#ifndef HASHMAP_H
#define HASHMAP_H

#include <stdlib.h>
#include <stdbool.h>
#include "iterator.h"

struct hkey {
    void *data;
    size_t length;
};

struct hentry {
    struct hentry *prev;
    struct hentry *next;
    struct hentry *chain;
    struct hkey *key;
    void *value;
};

struct hashmap {
    struct hentry **entries;
    struct hentry *head;
    struct hentry *tail;
    size_t capacity;
    size_t size;
};

struct hashmap *hashmap_create(void);

void hashmap_destroy(struct hashmap *this);

void hashmap_clear(struct hashmap *this);

#endif