#include <stdio.h>    
#define _CRT_SECURE_NO_WARNINGS
#define SIZE 10

int main()
{
    int arr[] = { 5, 1, 7, 3, 10, 2, 5, 5, 1, 10 };

    int frequency[SIZE];
    // frequency array will store -1 in the index j, where we already counted an element
    int foundAlready = -1;

    for (int i = 0; i < SIZE - 1; i++) {
        if (frequency[i] == foundAlready) {
            continue;
        }
        int count = 1;
        for (int j = i + 1; j < SIZE; j++) {
            if (arr[i] == arr[j]) {
                count++;
                frequency[j] = foundAlready;
            }
        }
        frequency[i] = count;
    }
    for (int i = 0; i < SIZE; i++) {
        if (frequency[i] != foundAlready) {
            printf("Element %d Appears %d times\n", arr[i], frequency[i]);
        }
    }
    return 0;
}

