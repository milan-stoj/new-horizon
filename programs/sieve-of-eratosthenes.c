#include <stdio.h>
#include <stdbool.h>

void printPrimes(int n) { 

	// define an bool element array (0,1) of size n
	bool prime[n + 1]; 

	// define a global iteration variable i
	int i;

	// iterate through prime array and set all values 
	// starting at 2 to true (Prime until proven Guilty) 
	for (i = 2; i <= n; i++) {

		// at prime index i, set bool element to true.
		prime[i] = true;
	}

	for (int divisor = 2; divisor * divisor <= n; divisor++) {

		// check if the prime at divisor index is true
		if (prime[divisor]) {

			// set global iterator to 2 * divisor, set 
			// prime at iterator to false, and then set 
			// iterator to current value + divisor
			for(i = 2 * divisor; i <= n; i = i + divisor) {
				prime[i] = false;
			}
		}
	}

	// iterate through prime array, and print 
	// iterator value at elements that are 'true'
	for(i = 2; i <= n; i++) {
		if(prime[i]) {
			printf("%d\n" , i);
		}
	}
}

// main method
int main() {

	// printPrimes call - input = 50
	printPrimes(29);
}
