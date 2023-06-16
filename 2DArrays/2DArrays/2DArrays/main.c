#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

#define SIZE 5
#define SIZE2 6

void init2DArray(int arr[SIZE][SIZE2], unsigned sizeRow, unsigned sizeColumn);
void print2DArray(int arr[SIZE][SIZE2], unsigned sizeRow, unsigned sizeColumn);
int** allocate2DDynamicArray(unsigned sizeRow, unsigned sizeColumn);
void init2DDynamicArray(int** arr, unsigned sizeRow, unsigned sizeColumn);
void print2DDynamicArray(int** arr, unsigned sizeRow, unsigned sizeColumn);
void changeValuesOfMatrix(int** arrPtr, unsigned sizeRow, unsigned sizeColumn);
void freeMemory(void* ptr);

int main() {
	int* array[SIZE];
	for (int i = 0; i < SIZE; i++) {
		array[i] = calloc(SIZE, sizeof(int));
		if (!array[i]) return NULL;
	}
	int(*arr)[SIZE2] = calloc(SIZE, sizeof *arr);
	printf("%I64u\n", sizeof *arr);
	// 
	/*int (*array2)[SIZE2] = calloc(SIZE, SIZE2 * sizeof(int));
	if (!array2) return NULL;*/
	printf("2D with array of pointers\n");
	init2DArray(array, SIZE, SIZE2);
	print2DArray(array, SIZE, SIZE2);
	printf("2D with array of pointers fully dynamic\n");
	int** myMatrix = allocate2DDynamicArray(SIZE, SIZE2);
	if (!myMatrix) return 1;
	//srand(time(NULL));
	//for (int i = 0; i < SIZE; i++) {
	//	for (int j = 0; j < SIZE2; j++) {
	//		//*(*(arr + i) + j) = rand() % 10;
	//		myMatrix[i][j] = rand() % 10;
	//	}
	//}
	init2DDynamicArray(myMatrix, SIZE, SIZE2);
	print2DDynamicArray(myMatrix, SIZE, SIZE2);
	printf("2ND INIT\n");
	changeValuesOfMatrix(myMatrix, SIZE, SIZE2);
	print2DDynamicArray(myMatrix, SIZE, SIZE2);
	for (int i = 0; i < SIZE; i++) {
		freeMemory(array[i]);
	}
	return 0;
}

int** allocate2DDynamicArray(unsigned sizeRow, unsigned sizeColumn) {
	int** dynamicArray = (int*)calloc(sizeRow, sizeof(int*));
	if (!dynamicArray) return NULL;
	for (int i = 0; i < sizeRow; i++) {
		dynamicArray[i] = (int*)calloc(sizeColumn, sizeof(int));
		if (!dynamicArray[i]) {
			// TODO free matrix
			return NULL;
		}
	}
	//for (int i = 0; i < sizeRow; i++) {
	//	for (int j = 0; j < sizeColumn; j++) {
	//		//*(*(arr + i) + j) = rand() % 10;
	//		dynamicArray[i][j] = rand() % 10;
	//	}
	//}
	return dynamicArray;
}

void freeMemory(void* ptr) {
	free(ptr);
}

void init2DArray(int arr[SIZE][SIZE2], unsigned sizeRow, unsigned sizeColumn) {
	// init
	srand(time(NULL));
	for (int i = 0; i < sizeRow; i++) {
		for (int j = 0; j < sizeColumn; j++) {
			//*(*(arr + i) + j) = rand() % 10;
			arr[i][j] = rand() % 10;
		}
	}
}

void print2DArray(int arr[SIZE][SIZE2], unsigned sizeRow, unsigned sizeColumn) {
	// print
	for (int i = 0; i < sizeRow; i++) {
		for (int j = 0; j < sizeColumn; j++) {
			//printf("%d ", *(*(arr + i) + j));
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void init2DDynamicArray(int** arr, unsigned sizeRow, unsigned sizeColumn) {
	// init
	srand(time(NULL));
	for (int i = 0; i < sizeRow; i++) {
		for (int j = 0; j < sizeColumn; j++) {
			//*(*(arr + i) + j) = rand() % 10;
			arr[i][j] = rand() % 10;
		}
	}
}

void changeValuesOfMatrix(int** arrPtr, unsigned sizeRow, unsigned sizeColumn) {
	srand(time(NULL));
	for (int i = 0; i < sizeRow; i++) {
		for (int j = 0; j < sizeColumn; j++) {
			//*(*(arr + i) + j) = rand() % 10;
			arrPtr[i][j] = 6;
		}
	}
}

void print2DDynamicArray(int** arr, unsigned sizeRow, unsigned sizeColumn) {
	// print
	for (int i = 0; i < sizeRow; i++) {
		for (int j = 0; j < sizeColumn; j++) {
			//printf("%d ", *(*(arr + i) + j));
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

