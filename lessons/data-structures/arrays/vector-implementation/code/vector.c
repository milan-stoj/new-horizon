/*
	Dynamically allocated array implementation in C
	Milan Stojanovic
*/ 

#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

int main() {

	vector v = {50};
	v.init = init;
	v.init(&v);
	printf("%d", v.arr[40]);
	printf("%d", v.capacity);

	return 0;
}