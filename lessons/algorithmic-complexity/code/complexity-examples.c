#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const int arraySize = 50;

int theArray[ arraySize ];
int itemsInArray = 0;


/* order of 1 O(1) */
int addItemToArray(int newItem) {
	theArray[itemsInArray++] = newItem;
}


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

void main () {

	
	int i, n;
	user_time_t t;
	srand((unsigned) time(&t));

	generateRandomArray();
	printArray();

}
