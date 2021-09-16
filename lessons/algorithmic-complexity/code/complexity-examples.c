#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const int arraySize = 50;

int msec;
int theArray[ arraySize ];
int itemsInArray = 0;


/* O(1) - time to complete is constant */
void addItemToArray(int newItem) {
	theArray[itemsInArray++] = newItem;
}


public void linearSearchForValue(int value) {
	bool valueInArray = false;
	char indexWithValue[]  = "";

	
	
}


// O(n) - time to complete is proportional to number of elements
void generateRandomArray() {
	for (int i = 0; i < arraySize; i++) {
		theArray[i] = rand() % 50;
	}

	itemsInArray = arraySize - 1;
}

void printArray() {
	for (int i = 0; i < arraySize; i++) {
		printf("%d, ", theArray[i]);
	}
}

int main () {

	
	int i, n;
	time_t t;
	srand((unsigned) time(&t));

	generateRandomArray();
	printArray();

}
