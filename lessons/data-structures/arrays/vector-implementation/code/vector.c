/*
	Dynamically allocated array implementation in C
	Milan Stojanovic
*/ 

#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

int main() {
	vector v;
	v.init = init;
	v.init(&v);

	printf("The capacity of vector = %d\n", v.capacity);
	printf("Value at index 10 = %d\n", v.at(&v, 10)); 
	printf("Vector is empty? (Should be true) %d\n", v.is_empty(&v));

	v.push(&v, 2);
	v.push(&v, 5);
	v.push(&v, 12);
	v.push(&v, 15);
	v.push(&v, 2);
	v.push(&v, 8);
	v.push(&v, 1);
	v.push(&v, 24);

	v.print(&v);
	printf("\nVector is empty? (Should be false) %d\n", v.is_empty(&v));
	printf("Value at index 4 = %d\n", v.at(&v, 4)); 
	printf("The size of vector: %d\n", v.size);

	v.insert(&v, 4, 69);

	printf("Value at index 4 = %d\n", v.at(&v, 4)); 
	v.print(&v);

	v.prepend(&v, 69);
	v.print(&v);
	int popped = v.pop(&v);
	printf("%d\n", popped);
	v.print(&v);

	v.delete(&v, 5);
	v.print(&v);

	v.push(&v, 2);
	v.push(&v, 5);
	v.push(&v, 12);
	v.push(&v, 15);
	v.push(&v, 2);
	v.push(&v, 8);
	v.push(&v, 1);
	v.push(&v, 24);
	v.push(&v, 24);
	v.push(&v, 24);
	v.push(&v, 8);
	v.push(&v, 24);

	v.print(&v);

	printf("\n%d\n", v.at(&v, 18));

	v.remove_item(&v, 24);

	v.print(&v);

	return 0;
}