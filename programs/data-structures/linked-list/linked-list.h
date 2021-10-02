#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#define LIST_INIT(list) linked_list list;
#define LIST_SIZE(list) list_size(&list)
#define EMPTY(list) list_size(&list)
#define VALUE_AT(list, index) value_at(&list, index)
#define PUSH_FRONT(list, value) push_front(&list, value)
#define POP_FRONT(list) pop_front(&list)
#define PUSH_BACK(list, value) push_back(&list, value)
#define POP_BACK(list) pop_back(&list)
#define FRONT(list) front(&list)
#define BACK(list) back(&list)
#define INSERT(list, index, value) insert(&list, index, value)
#define ERASE(list, index) erase(&list, index)
#define VALUE_N_FROM_END(list, n) value_n_from_end(&list, n)
#define REVERSE(list) reverse(&list)
#define REMOVE_VALUE(list, value) remove_value(&list, value)

typedef struct node 
{
    void **data;
    node *next;
};

typedef struct linked_list 
{
    node *head; // head pointer holds the address of starting node
    node *tail; // tail pointer holds the address of last node
    int size;   // size of the linked list
};

void *value_at(linked_list *list, int index) {
    if (list->size == 0) return;
    node *temp = list->head;
    for(int i = 0; i < index; i++)
    {
        node *temp = temp->next;
    };
    return temp->data;
};

// Test 
// Test Mobile

#endif