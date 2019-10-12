// Just a test for the lib

#include <stdio.h>
#include "list.h"
#include "test_functions.h"

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
    list_insert(&lst, 1, 53);
    list_remove(&lst, -2);

    printf("*** Simple funstions ***\r\n");

    for(list_index_t i = 0; i < lst.base.size; i++)
        printf("%d\r\n", *list_get(&lst, i));
    printf("***\r\n");
    
    printf("%d\r\n", *list_get(&lst, -2));
    printf("***\r\n");

    list_remove(&lst, 0);
    list_remove(&lst, -1);
    for(list_index_t i = 0; i < lst.base.size; i++)
        printf("%d\r\n", *list_get(&lst, i));
    
    printf("*** Copying ***\r\n");

    list_int_t lst1;
    list_copy(&lst, &lst1);

    for(list_index_t i = 0; i < lst1.base.size; i++)
        printf("%d\r\n", *list_get(&lst1, i));

    list_destroy(&lst1);
    list_destroy(&lst);

    list_init(&lst);

    for(list_index_t i = 0; i < 10; i++)
        list_append(&lst, i);

    printf("*** Applying function ***\r\n");

    list_copy(&lst, &lst1);
    list_apply(&lst1, square_int_list);
    list_apply(&lst1, print_int_list);
    list_destroy(&lst1);
    
    list_destroy(&lst);
    return 0;
}
