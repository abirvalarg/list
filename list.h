#pragma once

#include <stddef.h>
#include <string.h>

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
void _list_destroy(struct _list_base *l);

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

#define list_set(L, idx, value) ( (*list_get((L), (idx))) = (value) )

#define list_destroy(L) _list_destroy(&(L)->base)


typedef list_t(int) list_int_t;
