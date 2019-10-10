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

void *_list_get(struct _list_base *l, list_index_t idx)
{
    if(idx >= 0 && idx < l->size)
    {
        struct _list_node *node = l->head;
        while(idx--)
            node = node->next;
        return (void*)(node + 1);
    }
    else
        return NULL;
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
