#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int *array;
    int pos;
    int size;
    int fill;

    // declare variables you need
} arrayList;

void init(arrayList *list)
{
    list->array = (int *)malloc(2 * sizeof(int));
    list->pos = -1;
    list->size = 2;
    list->fill = 0;
    // implement initialization
}

void free_list(arrayList *list)
{
    free(list->array);

    // implement destruction of list
}

void increase_capacity(arrayList *list)
{
    // list->array = realloc(list->array, list->size * 2 * sizeof(int));
    // list->size = 2 * list->size;
    int *newarray = list->array;
    list->array = (int *)malloc(list->size * 2 * sizeof(int));
    for (int i = 0; i < list->fill; i++)
    {
        list->array[i] = newarray[i];
    }
    free(newarray);
    printf("size increased from %d to %d\n", list->size, list->size * 2);
    list->size = list->size * 2;

    // implement capacity increase
}

void decrease_capacity(arrayList *list)
{

    // list->array = realloc(list->array,(list->size / 2) * sizeof(int));
    // list->size = list->size / 2;
    int *newarray = list->array;
    list->array = (int *)malloc(list->size * sizeof(int) / 2);
    for (int i = 0; i < list->fill; i++)
    {
        list->array[i] = newarray[i];
    }
    free(newarray);
    printf("size decreased from %d to %d \n", list->size, list->size / 2);
    list->size = list->size / 2;
    // implement capacity decrease
}

void print(arrayList *list)
{
    printf("[ ");
    for (int i = 0; i < list->fill; i++)
    {
        printf("%d ", list->array[i]);
        if (i == list->pos)
        {
            printf("| ");
        }
    }
    printf(" ]\n");

    // implement list printing
}

void insert(int item, arrayList *list)
{
    list->fill++;
    list->pos++;
    if ((list->fill) * 2 > list->size)
    {
        increase_capacity(list);
    }
    for (int i = list->fill; i > list->pos; i--)
    {
        list->array[i] = list->array[i - 1];
    }
    list->array[list->pos] = item;
    print(list);
    // implement insert function
}

int delete_cur(arrayList *list)
{

    list->fill--;
    int x = list->array[list->pos];
    for (int i = list->pos; i <= list->fill; i++)
    {
        list->array[i] = list->array[i + 1];
    }
    if (list->pos == list->fill)
    {
        list->pos--;
    }
    if (4 * (list->fill) < list->size && list->size > 2)
    {
        decrease_capacity(list);
    }
    print(list);

    return x;
    // implement deletion of current index function
}

void append(int item, arrayList *list)
{
    list->array[list->fill] = item;
    list->fill++;
    if ((list->fill) * 2 > list->size)
    {
        increase_capacity(list);
    }
    if (list->pos == -1)
    {
        list->pos++;
    }
    print(list);
    // implement append function
}

int size(arrayList *list)
{
    return list->fill;
    // implement size function
}

void prev(int n, arrayList *list)
{
    if (list->pos - n < 0)
    {
        list->pos = 0;
    }
    else
    {
        list->pos = list->pos - n;
    }
    print(list);
    // implement prev function
}

void next(int n, arrayList *list)
{
    if (list->pos + n > list->fill)
    {
        list->pos = list->fill - 1;
    }
    else
    {
        list->pos = list->pos + n;
    }
    print(list);
    // implement next function
}

int is_present(int n, arrayList *list)
{
    for (int i = 0; i < list->fill; i++)
    {
        if (list->array[i] == n)
        {
            return 1;
        }
    }
    return 0;
    // implement presence checking function
}

void clear(arrayList *list)
{
    free_list(list);
    init(list);
    print(list);
    // implement list clearing function
}

void delete_item(int item, arrayList *list)
{
    for (int i = 0; i < list->fill; i++)
    {
        if (list->array[i] == item)
        {
            for (int j = i; j < list->fill - 1; j++)
            {
                list->array[j] = list->array[j + 1];
            }

            list->fill--;
            if (list->pos > i)
            {
                list->pos--;
            }
            else if (list->pos == i && list->pos >= list->fill)
            {
                list->pos = list->fill;
            }
            if (4 * (list->fill + 1) <= list->size && list->size > 2)
            {
                decrease_capacity(list);
            }
            print(list);
            return;
        }
    }
    // implement item deletion function
}

void swap_ind(int ind1, int ind2, arrayList *list)
{
    int temp = list->array[ind1];
    list->array[ind1] = list->array[ind2];
    list->array[ind2] = temp;
    print(list);
}

// you can define helper functions you need