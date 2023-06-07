#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>    
#include <stdlib.h>    
#include <string.h>    



int *createArray(int* size);
void printArr(int arr[], int size);

int main() {
	int size;
	int *array = (int *)createArray(&size);
	printArr(array, size);
	free(array);
	return 0;
}

int* createArray(int *arrSize) {
	int size = 1;
	int *array = (int *)malloc(size * sizeof(int));
	if (array == NULL) {
		return NULL;
	}
	int element = 0;
	int lastIndex = 0;
	printf("Enter value: ");
	scanf_s("%d", &element);
	while (element != -1) {
		size*=2;
		int* result = (int *)realloc(array, size * sizeof(int));
		if (result == NULL) {
			free(array);
			exit(1);
		}
		array = result;
		array[lastIndex] = element;
		lastIndex++;
		printf("Enter value: ");
		scanf_s("%d", &element);
	} 
	int* result = (int*)realloc(array, lastIndex * sizeof(int));
	if (result == NULL) {
		free(array);
		exit(1);
	}
	array = result;
	*arrSize = lastIndex;

	return array;
}

void printArr(int arr[], int size) {
	for (int i = 0; i < size; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}