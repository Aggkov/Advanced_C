#include <stdio.h>    
#include <stdlib.h>    
#define _CRT_SECURE_NO_WARNINGS
#define SIZE 5
#define SIZE2 3

void swap(int* arr1, int* arr2); 
void swap2(void** arr1, void** arr2); // O(1)
void printArr(int arr[], int size);

int main()
{
    int arr1[SIZE] = { 1,3,6,8,10};
    int arr2[SIZE] = { 2,2,4,11,17};
    int *arr3, *arr4;
    arr3 = malloc(sizeof(int) * 3);
    if (arr3 == NULL) {
        return;
    }
    arr3[0] = 1;
    arr3[1] = 2;
    arr3[2] = 3;
    arr4 = malloc(sizeof(int) * 3);
    if (arr4 == NULL) {
        return;
    }
    arr4[0] = 4;
    arr4[1] = 5;
    arr4[2] = 6;
    printf("BEFORE SWAP\n");
    printf("arr3 = ");
    printArr(arr3, SIZE2);
    printf("arr4 = ");
    printArr(arr4, SIZE2);
    printf("%p\n", arr3);
    printf("%p\n", arr4);
    swap2(arr3, arr4);
    printf("AFTER SWAP\n");
    printf("arr3 = ");
    printArr(arr3, SIZE2);
    printf("arr4 = ");
    printArr(arr4, SIZE2);
    //int* arr3 = malloc(sizeof(int) * 2);
    //if (arr3 == NULL) {
    //    return;
    //}
    //arr3[0] = 2;
    //arr3[1] = 3;
    //printf("%d", *arr3); // 2
    /*printf("%p\n", arr1);
    printf("%p\n", arr2);*/
    /*for (int i = 0; i < SIZE; i++) {
        swap2(&arr1[i], &arr2[i]);
    }*/
    /*printf("%p\n", arr1);
    printf("%p\n", arr2);*/

    return 0;
}
// use void** instead of int** because we simply exchange Addresses. We do not care what is 
// at the 1st, 2nd etc Address (int, float, char etc..)
void swap2(void** arr1, void** arr2) {
    void* tmp;
    tmp = *arr1;
    *arr1 = *arr2;
    *arr2 = tmp;

}


void swap(int* arr1, int* arr2) {
    int tmp[SIZE];
    for (int i = 0; i < SIZE; i++) {
        tmp[i] = arr2[i];
    }
    for (int i = 0; i < SIZE; i++) {
        arr2[i] = arr1[i];
    }
    for (int i = 0; i < SIZE; i++) {
        arr1[i] = tmp[i];
    }
}

void printArr(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}