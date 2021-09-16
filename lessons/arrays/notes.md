# 1. About Array's

- [1. About Array's](#1-about-arrays)
- [2. Array's and Linked Lists](#2-arrays-and-linked-lists)
	- [2.1. Definition](#21-definition)
	- [2.2. What's so Special?](#22-whats-so-special)
	- [2.3. Multi-Dimensional Array](#23-multi-dimensional-array)
	- [2.4. Complexity for Common Operations](#24-complexity-for-common-operations)
	- [2.5. Summary](#25-summary)
- [3. Array's](#3-arrays)
	- [3.1. What is an array?](#31-what-is-an-array)
		- [3.1.1. What an array looks like:](#311-what-an-array-looks-like)
		- [3.1.2. How to define an array:](#312-how-to-define-an-array)
		- [3.1.3. How to assign values to an array:](#313-how-to-assign-values-to-an-array)
- [4. Dynamic Arrays and Amortized Analysis](#4-dynamic-arrays-and-amortized-analysis)
	- [4.1. Dynamic Arrays](#41-dynamic-arrays)
		- [4.1.1. Definition](#411-definition)
		- [4.1.2. Implementation](#412-implementation)
		- [4.1.3. Common Implementations](#413-common-implementations)
		- [4.1.4. Runtimes](#414-runtimes)
	- [4.2. Summary](#42-summary)

# 2. Array's and Linked Lists
https://www.coursera.org/lecture/data-structures/arrays-OsBSF

## 2.1. Definition
- An array is a contiguous area of memory. One chunk of memory - on the stack or the heap.
- Consists of equal-sized elements indexed by contiguous integers. 

## 2.2. What's so Special?
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
## 2.3. Multi-Dimensional Array
- elem_addr = array_addr + elem_size * ((row_index - 1)) * array_w + (col_index - 1))

## 2.4. Complexity for Common Operations
| 		      | Add			| Remove	|
| ----------- | ----------- | --------- |
| Beginning   | O(n)		| O(n)		|
| End		  | O(1)        | O(1)		|
| Middle	  | O(n)        | O(n)		|

## 2.5. Summary
- **Array:** Contiguous area of memory consisting of equal-size elements indexed by contiguous integers.
- Constant-time access to any element
- Constant time to add/remove at the end.
- Linear time to add/remove at an arbitrary location.

# 3. Array's
https://archive.org/details/ucberkeley_webcast_Wp8oiO_CZZE

## 3.1. What is an array?
* An object consisting of a numbered list of variables (Java). 
	* Each of those variables can be a primitive type, or a reference to an object.
### 3.1.1. What an array looks like:
| Array	| 0		| 	1	| 	2	|
| --- 	| ---	| ---	| ---	|
| C		| b		| l		| u		|

### 3.1.2. How to define an array:
```c
char c[13]; // reference to an array (any length of characters)   
```

### 3.1.3. How to assign values to an array:
```c
c[0] = 'b';
c[3] = 'e';
c[100] = 'a';
```

# 4. Dynamic Arrays and Amortized Analysis
https://www.coursera.org/lecture/data-structures/dynamic-arrays-EwbnV

## 4.1. Dynamic Arrays
- **Problem:** Stats arrays are static!
  - Size has to be determined at compile time.
  - `int my_array[100]`
- **Semi-solution:** dynamically-allocated arrays:
  - `int *my_array = new int[size];`
- **Problem with semi-solution:** We don't know what the max size should be! But according to the wisdom of computer scientists: 
	> All problems in computer science can be solved by another level of indirection.
- **Solution to the semi-solution's problem:** Dynamic arrays (aka resizable arrays)
- **Idea:** store a pointer to a dynamically allocated array, and replace it with a newly-allocated array as needed.
### 4.1.1. Definition
- **Dynamic Array:** Abstract data type with the following operations (at a minimum):
  - `get(i)` returns element at location i
  - `set(i, val)` sets element i to val
  - `PushBack(val)` adds val to the end
  - `remove(i)` removes element at location i
  - `size()` the number of elements

### 4.1.2. Implementation
- **Store Globally:**
  - `arr`: dynamically-allocated array
  - `capacity` size of the dynamically-allocated array
  - `size`: number of elements currently in the array
- **Dynamic Array Resizing**
  1. Starting with array of size 2.
  2. Add 2 elements to the array.
  3. If a 3rd elements is added, i.e. beyond the capacity of the array, a new array of size 4 is allocated.
  4. The elements from the first array are copied to the new array, along with the 3rd element.
  5. The first array is de-allocated.
- **get(i):**
	> ```c
	> if i < 0 or i >= size:
	>	ERROR: index out of range
	> return arr[i]
	> ```
- **set(i, val):**
	> ```c
	> if i < 0 or i >= size:
	>	ERROR: index out of range
	> arr[i] = val
	> ```
- **push(val):**
	> ```c
	> if size = capacity:
	>	allocate new_arr[2 * capacity]
	>	for i from 0 to size - 1:
	>		new_arr[i] = arr[i]
	>	free arr
	>	arr = new_arr 
	>	capacity = 2 * capacity 
	> arr[size] = val
	> size = size + 1 
	> ```
- **remove(i):**
	> ```c
	> if i < 0 or i >= size:
	>	ERROR: index out of range
	> for j from i to size - 2:
	>	arr[j] = arr[j + 1]
	> size = size - 1
	> ```
### 4.1.3. Common Implementations
- C++: `vector`
- Java: `ArrayList`
- Python: `list`

### 4.1.4. Runtimes
| Operation		| Runtime	
| ----------- 	| --------
| Get(i)		| O(1)
| Set(i, val)	| O(1)        
| Push(i)	  	| O(n)
| Remove(i)	  	| O(n)
| Size()	  	| O(1)

## 4.2. Summary
1. Unlike static arrays, dynamic arrays can be resized.
2. Appending a new element to a dynamic array is often constant time but can take O(n).
3. Some space is wasted.
