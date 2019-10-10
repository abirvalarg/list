/*
MIT License

Copyright (c) 2019 abirvalarg
*/

#include "list.h"
#include <malloc.h>

size_t _list_append(struct _list_base *l, const void *data, size_t data_len)
{
    struct _list_node *new = malloc(sizeof(struct _list_node) + data_len);
    struct _list_node *last = l->tail;

    memcpy((char*)(new + 1), data, data_len);
    new->prev = last;
    new->next = NULL;

    if(last)
        last->next = new;
    else
        l->head = new;
    
    l->tail = new;
    
    return ++(l->size);
}

struct _list_node *__list_get_node(struct _list_base *l, list_index_t idx)
{
    if(idx >= 0 && idx < l->size)
    {
        struct _list_node *node = l->head;
        while(idx--)
            node = node->next;
        return node;
    }
    else if(idx < 0 && (-idx - 1) < l->size)
    {
        struct _list_node *node = l->tail;
        while(++idx)
            node = node->prev;
        return node;
    }
    else
        return NULL;
}

void *_list_get(struct _list_base *l, list_index_t idx)
{
    struct _list_node *node = __list_get_node(l, idx);
    return node ? (void*)(node + 1) : NULL;
}

void _list_insert(struct _list_base *l, list_index_t idx, const void *data, size_t data_len)
{
    struct _list_node *node = __list_get_node(l, idx);
    if(node)
    {
        struct _list_node *new = malloc(sizeof(struct _list_node) + data_len);
        new->prev = node->prev;
        new->next = node;

        if(node->prev)
            node->prev->next = new;
        node->prev = new;
        memcpy((char*)(new + 1), data, data_len);
        l->size++;
    }
}

size_t _list_remove(struct _list_base *l, list_index_t idx)
{
    struct _list_node *node = __list_get_node(l, idx);
    if(node)
    {
        struct _list_node *prev = node->prev;
        struct _list_node *next = node->next;

        if(prev)
            prev->next = next;
        else
            l->head = next;
        if(next)
            next->prev = prev;
        else
            l->tail = prev;
        
        free(node);
        l->size--;
    }
    return l->size;
}

void _list_destroy(struct _list_base *l)
{
    struct _list_node *node = l->head;
    while(node)
    {
        struct _list_node *next = node->next;
        free(node);
        node = next;
    }
}
