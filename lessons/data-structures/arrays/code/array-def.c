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

	/* jagged-array */
	int row_0[7] = { 1, 2, 3, 4, 5, 6, 7};
	int row_1[3] = { 100, 200, 300};

	int* jagged[2] = { row_0, row_1 };

	int Size[2] = {7, 3}, k = 0;

	for (int i = 0; i < 2; i++) {
		int* ptr = jagged[i];

		for (int j = 0; j < Size[k]; j++) {
			printf("%d", *ptr);

			ptr++;
		}

		printf("\n");
		k++;
		jagged[i]++;
	}
}