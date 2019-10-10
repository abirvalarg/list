# list
type-safe, double-linked dynamic array for C

# Usage
At first you need to initialize list.
```c
list_int_t lst;
list_init(&lst);
```
Initialization just fills structure with zeros so in some cases you can skip initialization.

You can put values at the end of list useing `list_append`. This is the only way to put first value into the list.
```c
list_append(&lst, 42);
```

To get a value from the list use `list_get`. This function returns pointer to the value or NULL if index is invalid.
```c
int *ptr0 = list_get(&lst, 0);
```
These pointers can be used to change the value. Same is done with `list_set`
```c
list_set(&lst, 0, 43);
```
Negative indicies are also valid and can be used for indexing from the end of the list (-1 - last value; -2 - value before the last).
```c
int *ptr1 = list_get(&lst, -1);
```

You also can insert value before any other using `list_insert` or remove value using `list_remove`.
```c
// Here comments contains state of list

// 43
list_insert(&lst, 0, 55);
// 55 43
list_insert(&lst, -1, 4);
// 55 4 43
list_remove(&lst, -1);
// 43 4
```

To prevent memory leaks use `list_destroy` to remove all values from the list.
```c
list_destroy(&lst);
```

## Types
Each list has its own type to store. Usually list type looks like `list_TYPE_t`. Some predefined types are in the table below.

|list type|value type|usage|
|-|-|-|
|list_int_t|int||
|list_char_t|char||
|list_float_t|float||
|list_double_t|double||
|list_str_t|char*|string pointers|
|list_ptr_t|void*|any pointers|

You can also define your own type of list.
```c
struct YOUR_TYPE;
typedef list_t(struct YOUR_TYPE) YOUR_LIST_TYPE;
```

## Notes
1. To get size of list use variable `lst.base.size`. This is used internally so do not change it
2. `list_append` and `list_remove` returns new size of list
