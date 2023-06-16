#include <stdio.h>
#include <stdlib.h>

// [12,5,7,8,3,10,4,9]
// create two dynamic arrays. 1st Array will be with odd nums, second with even adn print them

#define SIZE 10

void printArr(int *arr, unsigned length);
void splitArray(int* sourceArray, int** evenArrPtr, int** oddArrPtr, unsigned sourceSize, unsigned* evenLength, unsigned* oddLength);
int* generateEvenArr(int* arr, unsigned length);
int* generateOddArr(int* arr, unsigned length);

int main() {
	int arr[SIZE] = { 12,5,7,8,3,10,4,9,2,1 };
	int* evenArr = NULL;
	int* oddArr = NULL;
	unsigned evenL = 0;
	unsigned oddL = 0;
	splitArray(arr,&evenArr,&oddArr,SIZE, &evenL, &oddL);
	printArr(evenArr, evenL);
	printArr(oddArr, oddL);
	free(evenArr);
	free(oddArr);

	return 0;
}

// creates 2 dynamically (adjustable reallocated arrays even,odd) based on numbers in sourceArray and changes the values of evenArr and oddArr in
// main function by using pointers (pass by reference). Create the 2 arrays inside function and make main variables point to them
void splitArray(int* sourceArray,int **evenArrPtr, int **oddArrPtr, unsigned sourceSize, unsigned *evenLength, unsigned *oddLength) {
	// *oddArrPtr --> will change tha value of oddArr in main function
	int evenArrlastIndex = 0;
	int oddArrlastIndex = 0;
	int evenSize = 2;
	int oddSize = 2;
	int* evenArr = NULL;
	int* oddArr = NULL;
	int* tempEven = NULL;
	int* tempOdd = NULL;
	for (int i = 0; i < sourceSize; i++) {
		if (sourceArray[i] % 2 == 0) {
			if (evenArr == NULL) {
				evenArr = (int*)malloc(sizeof(int) * evenSize);
				if (evenArr == NULL) return NULL;
			}
			else {
				if (evenArrlastIndex == evenSize) {
					evenSize *= 2;
					tempEven = (int*)realloc(evenArr, evenSize * sizeof(int));
					if (tempEven == NULL) return NULL;
					evenArr = tempEven;
				}
			}
			evenArr[evenArrlastIndex] = sourceArray[i];
			evenArrlastIndex++;
		}
		else {
			if (sourceArray[i] % 2 == 1) {
				if (oddArr == NULL) {
					oddArr = (int*)malloc(sizeof(int) * oddSize);
					if (oddArr == NULL) return NULL;
				}
				else {
					if (oddArrlastIndex == oddSize) {
						oddSize *= 2;
						tempOdd = (int*)realloc(oddArr, oddSize * sizeof(int));
						if (tempOdd == NULL) return NULL;
						oddArr = tempOdd;
					}
				}
				oddArr[oddArrlastIndex] = sourceArray[i];
				oddArrlastIndex++;
			}
		}
	}
	tempEven = (int*)realloc(evenArr, evenArrlastIndex * sizeof(int));
	if (!tempEven) return NULL;
	evenArr = tempEven;
	tempOdd = (int*)realloc(oddArr, oddArrlastIndex * sizeof(int));
	if (!tempOdd) return NULL;
	oddArr = tempOdd;
	*evenArrPtr = evenArr;
	*oddArrPtr = oddArr;
	*evenLength = evenArrlastIndex;
	*oddLength = oddArrlastIndex;
}

// only returns 1 array at a time
int* generateEvenArr(int* arr, unsigned length) {
	int evenArrlastIndex = 0;
	int evenSize = 2;
	int* tempEven = NULL;
	int* evenArr = NULL;
	for (int i = 0; i < length; i++) {
		if (arr[i] % 2 == 0) {
			if (evenArr == NULL) {
				evenArr = (int*)malloc(sizeof(int) * evenSize);
				if (evenArr == NULL) return NULL;
			}
			else {
				if (evenArrlastIndex == evenSize) {
					evenSize *= 2;
					tempEven = (int*)realloc(evenArr, evenSize * sizeof(int));
					if (tempEven == NULL) return NULL;
					evenArr = tempEven;
				}
			}
			evenArr[evenArrlastIndex] = arr[i];
			evenArrlastIndex++;
		}
	}
	tempEven = (int*)realloc(evenArr, evenArrlastIndex * sizeof(int));
	if (!tempEven) return NULL;
	evenArr = tempEven;
	return evenArr;
}

int* generateOddArr(int* arr, unsigned length) {

}

void printArr(int *arr, unsigned length) {
	for (int i = 0; i < length; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}