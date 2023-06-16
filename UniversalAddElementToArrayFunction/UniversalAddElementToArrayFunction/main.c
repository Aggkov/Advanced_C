#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Implement insert functionality, insert value at index specified
// the function must be generic

#define SIZE 3
#define SIZE2 4

void* add(void* srcArr, unsigned oldSize, int index, void* element, unsigned elementSize, unsigned* newArraySize);
void* delete(void* srcArr, unsigned oldSize, int index, void* element, unsigned elementSize, unsigned* newArraySize);
void printArr(int* arr, unsigned length);

int main() {
	int* sourceArrInt = malloc(sizeof(int) * SIZE);
	sourceArrInt[0] = 3;
	sourceArrInt[1] = 5;
	sourceArrInt[2] = 4;
	int size = 3;
	double sourceArrDouble[SIZE] = { 9.1,1.3,4.5 };
	int elem = 5;
	sourceArrInt = (int*)add(sourceArrInt, SIZE * sizeof(int), 2 * sizeof(int), &elem, sizeof(int), &size);
	printArr(sourceArrInt, size);
	sourceArrInt = (int*)delete(sourceArrInt, SIZE2 * sizeof(int), 2 * sizeof(int), &elem, sizeof(int), &size);
	printArr(sourceArrInt, size);
	//free(resultAdd);
	//free(resultRemove);
	return 0;
}

void* delete(void* srcArr, unsigned oldSize, int index, void* element, unsigned elementSize, unsigned* newArraySize) {
	void* newArr = malloc(oldSize - elementSize);
	if (newArr == NULL) return NULL;
	memcpy(newArr, srcArr, index);
	memcpy((char*)newArr + index, (char*)srcArr + index + elementSize, oldSize - index - elementSize);
	*newArraySize = (oldSize - elementSize) / elementSize;
	free(srcArr);
	return newArr;
	

}

// index = starting index of the 1st byte of the element to be added
void* add(void* srcArr, unsigned oldSize, int index, void* element, unsigned elementSize, unsigned* newArraySize) {
	void* newArr = malloc(oldSize + elementSize);
	if (newArr == NULL) return NULL;
	memcpy(newArr, srcArr, index);
	memcpy((char*)newArr + index, element, elementSize);
	memcpy((char*)newArr + oldSize, (char*)srcArr + index, oldSize - index);
	*newArraySize = (oldSize + elementSize) / elementSize;
	free(srcArr);
	return newArr;
}

void printArr(int* arr, unsigned length) {
	for (int i = 0; i < length; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}