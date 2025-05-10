#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int element;
    struct node *next;
    struct node *prev;
} node;

typedef struct
{
    node *head;
    node *tail;
    node *cur;
    // declare head, tail, cur and other variables you need
} linkedList;

void init(linkedList *list)
{
    list->head = NULL;
    list->tail = NULL;
    list->cur = NULL;

    // implement initialization
}

void free_list(linkedList *list)
{
    node *temp = list->head;
    while (temp != NULL)
    {
        node *next = temp->next;
        free(temp);
        temp = next;
    }
    list->head = NULL;
    list->tail = NULL;
    list->cur = NULL;

    // implement destruction of list
}

void print(linkedList *list)
{
    node *temp = list->head;
    printf("[ ");
    while (temp != NULL)
    {
        printf("%d ", temp->element);
        if (temp == list->cur)
        {
            printf("| ");
        }

        temp = temp->next;
    }
    printf("]\n");

    // implement list printing
}

void insert(int item, linkedList *list)
{

    node *temp = (node *)malloc(sizeof(node));
    temp->next = NULL;
    temp->prev = NULL;
    temp->element = item;
    if (list->head == NULL)
    {
        list->head = temp;
        list->tail = temp;
        list->cur = temp;
    }
    else
    {

        temp->prev = list->cur;
        temp->next = list->cur->next;

        if (list->cur->next != NULL)
        {
            list->cur->next->prev = temp;
        }
        else
        {
            list->tail = temp;
        }
        list->cur->next = temp;
        list->cur = temp;
    }
    print(list);

    // implement insert function
}

int delete_cur(linkedList *list)
{

    node *temp = list->cur;
    if (temp == NULL)
    {
        return -1;
    }
    else
    {
        int x = list->cur->element;
        if (temp->prev == NULL)
        {
            list->head = temp->next;
            if (list->head != NULL)
            {
                list->head->prev = NULL;
            }
        }
        else
        {
            temp->prev->next = temp->next;
        }
        if (temp->next == NULL)
        {
            list->tail = temp->prev;
        }
        else
        {
            temp->next->prev = temp->prev;
        }
        if (temp->next == NULL)
        {
            list->cur = temp->prev;
        }
        else
        {
            list->cur = temp->next;
        }
        free(temp);
        print(list);
        return x;
    }

    // implement deletion of current index function
}

void append(int item, linkedList *list)
{
    node *temp = (node *)malloc(sizeof(node));

    temp->element = item;
    temp->next = NULL;
    temp->prev = NULL;
    if (list->head == NULL)
    {
        list->cur = list->head = list->tail = temp;
    }
    else
    {
        list->tail->next = temp;
        temp->prev = list->tail;
        list->tail = temp;
    }
    print(list);

    // implement append function
}

int size(linkedList *list)
{
    int count = 0;
    node *temp = list->head;

    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
    // implement size function
}

void prev(int n, linkedList *list)
{
    node *temp = list->cur;

    while (temp->prev != NULL && n--)
    {
        temp = temp->prev;
    }
    list->cur = temp;
    print(list); // implement prev function
}

void next(int n, linkedList *list)
{
    node *temp = list->cur;

    while (temp->next != NULL && n--)
    {
        temp = temp->next;
    }
    list->cur = temp;
    print(list);
    // implement next function
}

int is_present(int n, linkedList *list)
{
    node *temp = list->head;

    while (temp != NULL)
    {
        if (temp->element == n)
        {
            return 1;
        }
        temp = temp->next;
    }

    return 0;

    // implement presence checking function
}

void clear(linkedList *list)
{
    free_list(list);
    init(list);
    print(list);

    // implement list clearing function
}

void delete_item(int item, linkedList *list)
{
    node *temp = list->head;
    int flag=0;
    while (temp != NULL)
    {
        if (temp->element == item)
        {
            flag==1;
            
            if (list->cur == temp)
            {
                if (temp->next != NULL)
                {
                    list->cur = temp->next;
                }
                else
                {
                    list->cur = temp->prev;
                }
            }
            if (temp->prev == NULL)
            {
                list->head = temp->next;
                if (list->head != NULL)
                    list->head->prev = NULL;
            }
            else
            {
                temp->prev->next = temp->next;
            }
            if (temp->next == NULL)
            {
                list->tail = temp->prev;
            }
            else
            {
                temp->next->prev = temp->prev;
            }
            // if (temp->next == NULL)
            // {
            //     list->cur = temp->prev;
            // }
            // else
            // {
            //     list->cur = temp->next;
            // }
            free(temp);
            break;
        }
        temp = temp->next;
    }
    if(flag==1){

    print(list);
    }
    else{
        printf("%d not found\n",item);
    }

    // implement item deletion function
}

void swap_ind(int ind1, int ind2, linkedList *list)
{
    int count = 0;
    node *t1 = NULL;
    node *t2 = NULL;
    node *temp = list->head;

    while (temp != NULL)
    {
        if (count == ind1)
        {
            t1 = temp;
        }
        else if (count == ind2)
        {
            t2 = temp;
        }
        count++;
        temp = temp->next;
    }
    if (t1 != NULL && t2 != NULL)
    {
        int t = t1->element;
        t1->element = t2->element;
        t2->element = t;
    }
    else
    {
        printf("Swap indices out of range\n");
    }
    print(list);
    return;
}

// implement swap function

// you can define helper functions you need