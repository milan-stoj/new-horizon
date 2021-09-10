# Asymptotic Notation
https://www.youtube.com/watch?v=iOq5kSKqeR4

- We can't directly compare speeds of algorithms in minutes/seconds, as it is dependent on the inputs, hardware/software en of the algorithm.
    - Because of this, programmers came up with concepts of measuring the Asymptotic Complexity of a program, using a notation called Big(O) notation:
    
    - Its a way of analyzing how fast a program's run time increases asymptotically - or - as the size of the **inputs increases** towards infinity, how does the **runtime of the program** grow?

## Example
Imagine counting the number of characters in a string, the simpelest way:
- By walking through the whole string, letter by letter, and adding one to a counter for each character:

### O(n): Simple Counter
```c++ 
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
```
> This algorithm runs in linear time, in respect to the number of chars, n. Thus it runs in **O(n)** the runtime increases linearly with the input length.

What if O(n) isnt fast enough?

### O(1): Variable Call
```c++ 
#include <stdio.h>
#include <string.h>

int main() {
	char s[1000] = "hello, world";
	int c = 12; // defined with the string

	printf("Length of the string: %d\n", c);

	return 0;
}
```
> Accessing the value of a variable, like `c` is considered asymptotically constant time operation, or **O(1)**. The input length doesnt effect how fast the program runs. **DRAWBACK:** Memory storage for the variable, and time to store the variable.

### O(n^2): Exponential Time Growth
> As the number of elements, n, grows - O(n^2) algorithims will take longer than O(n) algorithms.

### O(log n): Binary Search
```c++
int binarySearch(int arr[], int l, int r, int x)
{
	if (r >= l) {
		int mid = l + (r - l) / 2;

		// if the element is present at the middle itself
		if (arr[mid] == x)
			return mid;

		// if the element is smaller than mid, then
		// it can only be present in left subarray
		if (arr[mid] > x)
			return binarySearch(arr, 1, mid -1, x);

		// else the element can only be present 
		// in right subarray
		return binarySearch(arr, mid + 1, r, x);
	}
	return -1;
}
```
> This algorithm cuts the size of the array, and repeats the process until the target is found. (Recursion) Size 8 -> 3 operations (log_2 8) vs Size 16 -> 4 operations (log_2 16)

## Best Case Ω vs Worst Case O vs θ
Algorithms are described in upper (worst case) and lower (best case) bounds.

In the best case for binary search, the element is in the middle.
> In the best case, it is Ω(1). In the worst, it is O(log n)

In the linear search
> Best case it is the first element of the array, Ω(1). In the worst case, it is the last element, O(n).

When the best case and worst case have equal time complexities, in the string length variable access example, it is said to run in θ(1).