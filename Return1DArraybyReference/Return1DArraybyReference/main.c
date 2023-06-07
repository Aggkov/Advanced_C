#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>    
#include <stdlib.h>    

#define SIZE 5

void createArrayByRef(int** ptr);
void createArrayByRefV2(int** ptr);
void printArr(int arr[], int size);

int main() {
	int* array = NULL;
	createArrayByRefV2(&array);
	printArr(array, SIZE);
	free(array);
	return 0;
}

void createArrayByRefV2(int** ptr) {
	*ptr = malloc(sizeof(int) * SIZE);
	if (ptr == NULL) {
		ptr = NULL;
	};
	for (int i = 0; i < SIZE; i++) {
		(*ptr)[i] = i + 2;
	}
}

void createArrayByRef(int** ptr) {
	*ptr = malloc(sizeof(int) * SIZE);
	if (ptr == NULL) {
		ptr = NULL;
	};
	for (int i = 0; i < SIZE; i++) {
		(*ptr)[i] = i + 2;
	}
}


void printArr(int arr[], int size) {
	for (int i = 0; i < size; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}