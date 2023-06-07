#include <stdio.h>    
#include <stdbool.h>    
#define _CRT_SECURE_NO_WARNINGS
#define SIZE 7

bool findPairWhoseSumEqualsValue(int arr[], int value, int size, int *indx1, int *indx2);
bool findPairWhoseSumEqualsValueOptimized(int arr[], int value, int size, int* indx1, int* indx2);

int main()
{
    int arr[] = { 1,3,4,7,9,10,12};
    int index1;
    int index2;
    printf("%d \n", findPairWhoseSumEqualsValueOptimized(arr, 20, SIZE, &index1, &index2));
    printf("%d %d\n", index1, index2);
}

bool findPairWhoseSumEqualsValueOptimized(int arr[], int value, int size, int* indx1, int* indx2) {
    int i, j;
    i = 0;
    j = size - 1;
    for (i = 0; i < j;) {
        int sum = 0;
        if ((sum = arr[i] + arr[j]) == value) {
            *indx1 = i;
            *indx2 = j;
            return true;
        }
        else if (sum < value) {
            i++;
        }
        else if (sum > value) {
            j--;
        }
    }
    return false;
}


bool findPairWhoseSumEqualsValue(int arr[], int value, int size, int* indx1, int* indx2) {
    int i, j;
    for (i = 0; i < size - 1; i++) {
        for (j = i + 1; j < size; j++) {
            if (arr[i] + arr[j] == value) {
                *indx1 = i;
                *indx2 = j;
                return true;
            }
        }
    }
    return false;
}

