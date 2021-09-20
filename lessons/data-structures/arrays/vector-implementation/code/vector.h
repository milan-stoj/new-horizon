#include <stdlib.h>
#include <stdbool.h>

#define INIT_CAPACITY 16;

typedef struct vector {
	// struct members
	int *arr;
	int size;
	int capacity;

	// struct methods
	void (*init)(struct vector*);
	bool (*is_empty)(struct vector*);
	int (*at)(struct vector*, int index);
	void (*push)(struct vector*, int item);
	void (*insert)(struct vector*, int index, int item);
	void (*prepend)(struct vector*, int item);
	int (*pop)(struct vector*);
	void (*delete)(struct vector*, int index);
	// void (*remove)(struct vector*, int item);
	// int (*find)(struct vector*, int item);
	// void (*resize)(struct vector*, int new_capacity);
	void (*print)(struct vector*);
} vector ;

int at(vector *v, int index) {
	if (index < 0 || index > v->size) {
		return 0;
	} else {
		return v->arr[index];
	}
}

bool is_empty(vector *v) {
	return (v->size == 0) ? true : false;
}

void push(vector *v, int item) {
	v->arr[v->size] = item;
	v->size++;
	return;
}

void insert(vector *v, int index, int item) {
	for (int i = v->size + 1; i > index; i--) {
		v->arr[i] = v->arr[i - 1];
	}
	v->arr[index] = item;
	v->size++;
	return;
}

void prepend(vector *v, int item) {
	for (int i = v->size + 1; i > 0; i--) {
		v->arr[i] = v->arr[i - 1];
	}
	v->arr[0] = item;
	v->size++;
} 

void print(vector *v) {
	for (int i = 0; i < v->size; i++) {
		printf("%d ", v->arr[i]);
	}
	printf("\n");
}

int pop(vector *v) {
	int pop = v->arr[v->size - 1];
	v->arr[v->size - 1] = NULL;
	v->size--;
	return pop;
}

void delete(vector *v, int index) {
	for(int i = index; i < v->size; i++) {
		v->arr[i] = v->arr[i+1];
	}
	v->size--;
}

void init(vector *v) {
	v->capacity = INIT_CAPACITY;
	v->size = 0;
	v->arr = (int*)malloc(sizeof(int) * v->capacity);
	v->at = at;
	v->is_empty = is_empty;
	v->push = push;
	v->insert = insert;
	v->print = print;
	v->prepend = prepend;
	v->pop = pop;
	v->delete = delete;
	return;
}