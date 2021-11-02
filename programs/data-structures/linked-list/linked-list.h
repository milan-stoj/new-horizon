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
    struct node* next;
} node;

typedef struct linked_list
{
    node* head; // head pointer holds the address of starting node
    node* tail; // tail pointer holds the address of last node
    int size;   // size of the linked list
} linked_list;

int list_size(linked_list* list)
{
    return list->size;
}

node* make_node(int value)
{
    node* new;
    new = (node*)malloc(sizeof(node));
    new->data = value;
    return new;
}

void init_list(linked_list* list)
{
    list->size = 0;
}

void push_front(linked_list* list, int value)
{
    node* new = make_node(value);
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

void push_back(linked_list* list, int value)
{
    node* new = make_node(value);
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

int pop_front(linked_list* list)
{
    if (list->size == 0) return 0;
    node* new_head = list->head->next;
    int result = list->head->data;
    free(list->head);
    list->head = NULL;
    list->size--;
    list->head = new_head;
    return result;
}

int pop_back(linked_list* list)
{
    if (list->size == 0) return 0;
    int result = list->tail->data;
    node* iter;
    iter = list->head;
    while (iter->next != list->tail) iter = iter->next;
    list->tail = iter;
    free(list->tail->next);
    list->tail->next = NULL;
    list->size--;
    return result;
}

int value_at(linked_list* list, int index) {
    if (list->size == 0 || index > list->size - 1) return 0;
    node* iter = list->head;
    for (int i = 0; i < index; i++)
    {
        iter = iter->next;
    };
    return iter->data;
};

int value_n_from_end(linked_list* list, int n) {
    if (list->size == 0) return 0;
    int iter = list->size - 1 - n;
    node* target = list->head;

    for (int i = 0; i < iter; i++)
    {
        target = target->next;
    }
    return target->data;
};

void insert(linked_list* list, int index, int value)
{
    if (list->size == 0 || index > list->size - 1) return;
    else if (index == 0)
    {
        push_front(list, value);
        return;
    }
    else if (index == list->size - 1)
    {
        push_back(list, value);
        return;
    }
    else
    {
        node* new = make_node(value);
        node* iter = list->head;
        for (int i = 0; i < index - 1; i++)
        {
            iter = iter->next;
        };
        new->next = iter->next;
        iter->next = new;
        list->size++;
        return;
    }
}

void display_list(linked_list* list)
{
    if (list->head == NULL) return;
    node* iter;
    iter = list->head;

    for (int i = 0; i < list->size; i++)
    {
        printf("-[%d]-", iter->data);
        iter = iter->next;
    }
    printf("\nPress enter to continue...");
    getchar();
}

void erase(linked_list* list, int index)
{
    if (list->size == 0) return 0;
    if (index > list->size) return 0;

    node* prev = list->head;
    node* target = list->head;
    node* next = target->next;

    if (index == 0) // removing head
    {
        free(list->head);
        list->head = NULL;
        list->size--;
        list->head = next;
        return;
    }

    if (index == list->size) // remove tail
    {
		node* iter;
		iter = list->head;
		while (target->next != list->tail) target = target->next;
		list->tail = target;
		free(list->tail->next);
		list->tail->next = NULL;
		list->size--;
    }

    for (int i = 0; i < index; i++)
    {
        prev = target;
        target = target->next;
        next = target->next;
    };
    prev->next = target->next;
    free(target);
    target = NULL;
    list->size--;
    return;
}



#endif