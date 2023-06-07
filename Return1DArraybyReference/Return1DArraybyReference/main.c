#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>    
#include <stdlib.h>    

#define SIZE 5

void createArray(int** ptr);
void printArr(int arr[], int size);

int main() {
	int* array = NULL;
	createArray(&array);
	array[0] = 1;
	array[1] = 2;
	array[2] = 3;
	array[3] = 4;
	array[4] = 5;
	printArr(array, SIZE);
	free(array);
	return 0;
}

void createArray(int** ptr) {
	int* arr = malloc(sizeof(int) * SIZE);
	if (arr == NULL) return NULL;
	return *ptr = arr;
}


void printArr(int arr[], int size) {
	for (int i = 0; i < size; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}