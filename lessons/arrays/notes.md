# About Array's

# Array's and Linked Lists
https://www.coursera.org/lecture/data-structures/arrays-OsBSF

## Definition
- An array is a contiguous area of memory. One chunk of memory - on the stack or the heap.
- Consists of equal-sized elements indexed by contiguous integers. 

## What's so Special?
- Constant-time O(1) or random access to the array:
	- we can do arithmetic to figure out the address of what array element we are on.
	- elem_addr = array_addr + elem_size * (i - first_index)

```c++
#include <stdio.h>

int main() {
	int x, my_array[1000], *array_p = &my_array[0];
	my_array[500] = 1234;

	/* using variable reference */
	x = my_array[500];
	printf("%d \n", x);

	/* using pointer reference */
	x = *(array_p + 500);
	printf("%d \n", x);

	return 0;
}
```
## Multi-Dimensional Array
- elem_addr = array_addr + elem_size * ((row_index - 1)) * array_w + (col_index - 1))

## Complexity for Common Operations
| 		      | Add			| Remove	|
| ----------- | ----------- | --------- |
| Beginning   | O(n)		| O(n)		|
| End		  | O(1)        | O(1)		|
| Middle	  | O(n)        | O(n)		|

## Summary
- **Array:** Contiguous area of memory consisting of equal-size elements indexed by contiguous integers.
- Constant-time access to any element
- Constant time to add/remove at the end.
- Linear time to add/remove at an arbitrary location.

# Array's
https://archive.org/details/ucberkeley_webcast_Wp8oiO_CZZE

## What is an array?
* An object consisting of a numbered list of variables (Java). 
	* Each of those variables can be a primitive type, or a reference to an object.
### What an array looks like:
| Array	| 0		| 	1	| 	2	|
| --- 	| ---	| ---	| ---	|
| C		| b		| l		| u		|

### How to define an array:
```c
char c[13]; // reference to an array (any length of characters)   
```

### How to assign values to an array:
```c
c[0] = 'b';
c[3] = 'e';
c[100] = 'a';
```

# Dynamic Arrays and Amortized Analysis
https://www.coursera.org/lecture/data-structures/dynamic-arrays-EwbnV

## Dynamic Arrays
- Problem: Stats arrays are static!
	- Size has to be determined at compile time.
	- `int my_array[100]`
- Semi-solution: dynamically-allocated arrays:
	- `int *my_array = new int[size];`

