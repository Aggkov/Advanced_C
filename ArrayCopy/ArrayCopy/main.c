#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Copy all elements from src array to a new one
// the function must be generic (void type)

#define SIZE 5
#define SIZE2 4

void arrayCopy(int* srcArr, int **newArrPtr, unsigned length);
void arrayCopyGeneric(void* srcArr, void** newArrPtr, unsigned length);
void printArr(int* arr, unsigned length);
// static arrays dont need 2double pointer to change value by ref. Dynamic arrays need 2double
void changeArrayValueByRef(int** arr);

int main() {
	int array[SIZE] = { 3,6,2,1,7 };
	int *newArray = NULL;
	arrayCopyGeneric(array, &newArray, SIZE);
	array[1] = 10;
	printArr(array, SIZE);
	printArr(newArray, SIZE);
	changeArrayValueByRef(&newArray);
	printArr(newArray, SIZE);
	free(newArray);
	return 0;
}

void arrayCopyGeneric(void* srcArr, void** newArrPtr, unsigned length) {
	int bytes = length * sizeof(int);
	*newArrPtr = malloc(SIZE * sizeof(int));
	if (!(*newArrPtr)) return NULL;
	for (int i = 0; i < bytes; i++) {
		((char*)(*newArrPtr))[i] = ((char*)srcArr)[i];
	}
}

void arrayCopy(int* srcArr, int** newArrPtr, unsigned length) {
	for (int i = 0; i < length; i++) {
		(*newArrPtr)[i] = srcArr[i];
	}
}

void changeArrayValueByRef(int** arr) {
	(*arr)[1] = 10;
}

void printArr(int* arr, unsigned length) {
	for (int i = 0; i < length; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}