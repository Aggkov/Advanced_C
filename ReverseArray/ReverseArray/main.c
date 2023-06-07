#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS
#define SIZE 4

//[4,3,6,8,10]
//[10,8,6,3,4]
// "abcd"
// "dcba"

void reverseArray(int* arr, int size);
void reverseArrayVersion2(int* arr, int size);
void reverseString(char* str);
void print(int arr[], int size);

int main() {
    int arr[SIZE] = { 4, 3, 6, 8 };
    print(arr, SIZE);
    reverseArrayVersion2(arr, SIZE);
    print(arr, SIZE);
    char string[50] = "abcd";
    printf("%s\n", string);
    reverseString(string);
    printf("%s\n", string);
    return 0;
}

void reverseArray(int* arr, int size) {
    int *ptr = arr;
    int i = 0;
    while (i < size) {
        int tmp = *ptr;
        *(arr + i) = *(arr + (size - 1));
        *(arr + (size - 1)) = tmp;
        i++;
        ptr++;
        size--;
    }
}

//[4,3,6,8,10,2]
//[2,10,8,6,3,4]


void reverseArrayVersion2(int* arr, int size) {
    int* ptr = arr;
    int i = 0;
    while (i < size) {
        int tmp = *ptr;
        arr[i] = arr[size - 1];
        arr[size - 1] = tmp;
        i++;
        ptr++;
        size--;
    }
}

// "abcd"
// "dcba"
void reverseString(char *str) {
    int size = strlen(str);
    char* ptr = str;
    int i = 0;
    while (i < size) {
        char tmp = *ptr;
        str[i] = str[size - 1];
        str[size - 1] = tmp;
        i++;
        ptr++;
        size--;
    }
}

void print(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}