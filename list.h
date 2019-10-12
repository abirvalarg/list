/*
MIT License

Copyright (c) 2019 abirvalarg
*/

#pragma once

#include <stddef.h>
#include <string.h>

#define LIST_VERION 010100.L
#define LIST_VERSION_STR "1.1.0"

typedef long long list_index_t;

struct _list_node
{
    struct _list_node *next;
    struct _list_node *prev;
    // char data[???];
};

struct _list_base
{
    size_t size;
    struct _list_node *head;
    struct _list_node *tail;
};

size_t _list_append(struct _list_base *l, const void *data, size_t data_len);
void *_list_get(struct _list_base *l, list_index_t idx);
size_t _list_insert(struct _list_base *l, list_index_t idx, const void *data, size_t data_len);
size_t _list_remove(struct _list_base *l, list_index_t idx);
void _list_destroy(struct _list_base *l);

void _list_copy(struct _list_base *src, struct _list_base *dest, size_t data_len);

#define list_t(T) struct { \
    struct _list_base base; \
    T *ptr; \
    T tmp; \
}

#define list_init(L) memset((L), 0, sizeof(*(L)))

#define list_append(L, data) \
    ( (L)->tmp = (data), \
        _list_append(&(L)->base, &(L)->tmp, sizeof((L)->tmp)) )

#define list_get(L, idx) ( (L)->ptr = _list_get(&(L)->base, (idx)) )

#define list_set(L, idx, value) ( list_get(L, idx) ? (*(L)->ptr = (value), 1) : 0)

#define list_insert(L, idx, value) \
    ( (L)->tmp = (value), \
    _list_insert(&(L)->base, (idx), &(L)->tmp, sizeof((L)->tmp)) )

#define list_remove(L, idx) _list_remove(&(L)->base, (idx))

#define list_destroy(L) _list_destroy(&(L)->base)

#define list_copy(from, to) \
    _Static_assert(sizeof((from)->tmp) == sizeof((to)->tmp), "Lists must have same value sizes"); \
    ( list_init(to), \
    _list_copy(&(from)->base, &(to)->base, sizeof((to)->tmp)) )

typedef list_t(int) list_int_t;
typedef list_t(char) list_char_t;
typedef list_t(void*) list_ptr_t;
typedef list_t(char*) list_str_t;
typedef list_t(double) list_double_t;
typedef list_t(float) list_float_t;
