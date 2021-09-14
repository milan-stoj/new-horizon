#include <stdio.h>

int main() {
	int x, my_array[1000], *array_p = &my_array[0];
	my_array[500] = 1234;

	x = my_array[500];
	printf("%d \n", x);

	x = *(array_p + 500);
	printf("%d \n", x);

	return 0;
}