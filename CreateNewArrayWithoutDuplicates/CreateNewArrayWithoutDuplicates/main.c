#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 7


void printArr(int* arr, int size);
int* removeDuplicates(int arr[], int* arrSize);
bool contains(int arr[], int elem, size_t size);

int main()
{	
	int size = 2;
	int array[SIZE] = { 3,3,3,5,6,7,7 };
	printArr(array, SIZE);
	int* myArr = removeDuplicates(array, &size);
	printArr(myArr, size);
	free(myArr);
}

void printArr(int* arr, int size)
{
	int i;
	for (i = 0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

int* removeDuplicates(int arr[], int* arrSize) {
	int size = 2;
	int* uniqueArray = (int*)malloc(size * sizeof(int));
	if (uniqueArray == NULL) return NULL;
	int* result = NULL;
	int lastindex = 0;
	for (int i = 0; i < SIZE; i++) {
		if (!contains(uniqueArray, arr[i], SIZE)) {
			if (lastindex == size) {
				size *= 2;
				result = (int*)realloc(uniqueArray, size * sizeof(int));
				if (result == NULL) return NULL;
				uniqueArray = result;
			}
			uniqueArray[lastindex] = arr[i];
			lastindex++;
		}
	}

	result = (int*)realloc(uniqueArray, lastindex * sizeof(int));
	if (!result) return NULL;
	uniqueArray = result;
	*arrSize = lastindex;
	return uniqueArray;
}

bool contains(int arr[], int elem, size_t size) {
	for (int i = 0; i < size; i++) {
		if (arr[i] == elem) {
			return true;
		}
	}
	return false;
}