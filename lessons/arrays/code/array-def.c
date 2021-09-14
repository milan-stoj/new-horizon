#include <stdio.h>

int main() {
	/* single dim array */
	const int SIZE = 100; // size of array
	char c[SIZE] = "Hello, world";
	c[1] = 'A';

	/* printing just a char */
	printf("%c \n", c[1]);

	/* printing char array as string */
	printf("%s \n", c);

	/* size of array using sizeof */
	int size = sizeof c / sizeof c[0];
	int size_p = sizeof c / sizeof *c;
	printf("The size of array c is %d\n", size);
	printf("Using pointers, the size of array c is %d\n", size_p);


	/* multi-dim array */

}

void printPrimes() {

}