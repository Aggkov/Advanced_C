#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Implement insert functionality, insert value at index specified
// the function must be generic

#define SIZE 3
#define SIZE2 4

void* delete(void* srcArr, unsigned oldSize, int index, void* element, unsigned elementSize);
void printArr(int* arr, unsigned length);

int main() {
	int* sourceArrInt = (int*)malloc(sizeof(int) * SIZE);
	sourceArrInt[0] = 3;
	sourceArrInt[1] = 5;
	sourceArrInt[2] = 4;
	double sourceArrDouble[SIZE] = { 9.1,1.3,4.5 };
	int elem = 5;
	printArr(sourceArrInt, SIZE);
	int* resultRemove = (int*)delete(sourceArrInt, SIZE * sizeof(int), 2 * sizeof(int), &elem, sizeof(int));
	printArr(resultRemove, SIZE - 1);
	//free(resultAdd);
	//free(resultRemove);
	return 0;
}

void* delete(void* srcArr, unsigned oldSize, int index, void* element, unsigned elementSize) {
	void* newArr = malloc(oldSize - elementSize);
	if (newArr == NULL) return NULL;
	memcpy(newArr, srcArr, index);
	memcpy((char*)newArr + index + elementSize, (char*)srcArr + index, oldSize - index - elementSize);
	return newArr;
	//free(srcArr);

}

void printArr(int* arr, unsigned length) {
	for (int i = 0; i < length; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}