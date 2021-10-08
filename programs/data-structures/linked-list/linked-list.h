#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#define DISPLAY_LIST(list) display_list(&list);
#define INIT_LIST(list) init_list(&list);
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
    int data;
    struct node *next;
} node;

typedef struct linked_list 
{
    node *head; // head pointer holds the address of starting node
    node *tail; // tail pointer holds the address of last node
    int size;   // size of the linked list
} linked_list;

int list_size(linked_list *list)
{
    return list->size;
}

void init_list(linked_list *list)
{

    list->size = 0;
}

void push_front(linked_list *list, int value)
{
    node *new;
    new = (node*)malloc(sizeof(node));
    new->data = value;
    if (list->size == 0)
    {
        list->head = new;
        list->tail = new;
        list->size++;
    }
    else
    {
        new->next = list->head;
        list->head = new;
        list->size++;
    }
}

void push_back(linked_list *list, int value)
{
    node *new;
    new = (node*)malloc(sizeof(node));
    new->data = value;
    if (list->size == 0)
    {
        list->head = new;
        list->tail = new;
        list->size++;
    }
    else
    {
        list->tail->next = new;
        list->tail = new;
        list->size++;
    }
}

int pop_front(linked_list *list)
{
    if (list->size == 0) return 0;
    int result = list->head->data;
    free(list->head);
    list->head = NULL;
    list->size--;
    list->head = list->head->next;
    return result;
}

int pop_back(linked_list *list)
{
    if (list->size == 0) return 0;

    int result = list->tail->data;

    node *iter;
    iter = list->head;
    while(iter->next != list->tail) iter = iter->next;
    list->tail = iter;
    free(list->tail->next);
    list->tail->next = NULL;
    list->size--;
    return result;
}


int value_at(linked_list *list, int index) {
    if (list->size == 0) return 0;
    node *temp = list->head;
    for(int i = 0; i < index; i++)
    {
        node *temp = temp->next;
    };
    return temp->data;
};

void display_list(linked_list *list)
{
    if (list->head == NULL) return;
    
    for (node *iter = list->head; iter != NULL; iter = iter->next)
    {
        printf("-[%d]-", iter->data);
    }
    printf("\nPress enter to continue...");
    getchar();
}
// Test 
// Test Mobile

#endif