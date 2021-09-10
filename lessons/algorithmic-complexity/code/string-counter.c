#include <stdio.h>
#include <string.h>

int main() {
	char s[1000] = "hello, world";
	int c = 0;

	while (s[c] != '\0')
		c++;

	printf("Length of the string: %d\n", c);

	return 0;
}