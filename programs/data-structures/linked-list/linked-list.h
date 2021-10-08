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
    list->head = (node*)malloc(sizeof(node));
    list->tail = (node*)malloc(sizeof(node));
    list->size = 0;
}

void push_front(linked_list *list, int value)
{
    node *new;
    new = (node*)malloc(sizeof(node));
    new->data = value;
    if (list->size == 0)
    {
        list->head->next = new;
        list->tail->next = new;
        list->size++;
    }
    else
    {
        new->next = list->head->next;
        list->head->next = new;
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
        list->head->next = new;
        list->tail->next = new;
        list->size++;
    }
    else
    {
        list->tail->next->next = new;
        list->tail->next = new;
        list->size++;
    }
}

int pop_front(linked_list *list)
{
    if (list->size == 0) return 0;
    int result = list->head->next->data;
    list->head->next = list->head->next->next;
    free(list->head->next);
    list->size--;
    return result;
}

int pop_back(linked_list *list)
{
    if (list->size == 0) return 0;

    int result = list->tail->next->data;

    node *temp;
    temp = list->head;
    while(temp->next->next != list->tail->next) temp = temp->next;
    free(list->tail->next);
    list->tail->next = temp->next;
    list->tail->next->next = NULL;
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
    if (list->head->next == NULL) return;
    
    for (node *temp = list->head->next; temp != NULL; temp = temp->next)
    {
        printf("-[%d]-", temp->data);
    }
    printf("\nPress enter to continue...");
    getchar();
}
// Test 
// Test Mobile

#endif