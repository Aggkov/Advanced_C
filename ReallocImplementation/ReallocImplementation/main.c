#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MALLOCSIZEOLD 12  // 3 ints
#define MALLOCSIZENEW 20   // 5 ints

void* myRealloc(void* ptr, unsigned newSize);
void* mymalloc(size_t n);
// get size of array dynamically allocated
size_t getSize(void* p);
void printArr(int arr[], unsigned size);

int main() {
    // initial allocation of 3 integers
	int* arr = (int*)malloc(MALLOCSIZEOLD);
    if (arr == NULL) {
        return 1;
    }
    arr[0] = 1;
    arr[1] = 2;
    arr[2] = 3;
    printArr(arr, MALLOCSIZEOLD / 4);
    int *result = (int*)myRealloc(arr, MALLOCSIZENEW);
    if (result == NULL) {
        free(arr);
        return 1;
    }
    arr = result;
    printArr(arr, MALLOCSIZENEW / 4);
    free(arr);
	return 0;
}

void* myRealloc(void* ptr, unsigned newSize) {
    // new space
    void* newPtr = malloc(newSize);
    if (newPtr == NULL) {
        return NULL;
    }
    else {
        if (newSize < MALLOCSIZEOLD) {
            memcpy(newPtr, ptr, newSize);
            return newPtr;
        }
        else {
            memcpy(newPtr, ptr, MALLOCSIZEOLD);
            return newPtr;
        }
    }
}

void* mymalloc(size_t n) {
    printf("size t is %llu", sizeof(size_t));
    size_t* result = malloc(n + sizeof(size_t));
    if (result) { 
        *result = n; 
        ++result; 
        memset(result, 0, n); }
    return result;
}

size_t getSize(void* p) {
    size_t* in = p;
    if (in) { 
        --in; 
        return *in; 
    }
    return -1;
}

void printArr(int arr[], unsigned size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}