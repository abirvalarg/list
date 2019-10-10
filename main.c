#include <stdio.h>
#include "list.h"

int main()
{
    list_int_t lst;
    list_init(&lst);

    list_append(&lst, 42);
    list_append(&lst, -4);
    list_append(&lst, 2);
    list_append(&lst, 0);
    list_append(&lst, 4000);
    list_append(&lst, 4000000000);
    list_set(&lst, -1, 80);

    for(list_index_t i = 0; i < lst.base.size; i++)
        printf("%d\r\n", *list_get(&lst, i));
    
    printf("%d\r\n", *list_get(&lst, -2));

    list_destroy(&lst);
    return 0;
}
