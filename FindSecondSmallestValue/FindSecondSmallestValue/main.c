#include <stdio.h>    
#include <stdbool.h>  
#include <limits.h>
#define _CRT_SECURE_NO_WARNINGS
#define SIZE1 10
#define SIZE2 5

int findSecondSmallest(int arr[], int size);
int secSmallest(int arr[], int size);
void get2ndSmallest(int arr[], int size);

int main()
{
    int arr1[SIZE1] = { 1, 1, 7, 3, 10, 11, 5, 5, 1, 10 };
    int arr2[SIZE2] = { 13,5,2,5,9 };
    printf("%d \n", findSecondSmallest(arr1, SIZE1));
    printf("%d \n", findSecondSmallest(arr2, SIZE2));
    get2ndSmallest(arr1, SIZE1);
    get2ndSmallest(arr2, SIZE2);
    
    return 0;
}

int findSecondSmallest(int arr[], int size) {
    int min1, min2;
    min1 = min2 = INT_MAX;
    
    for (int i = 1; i < size; i++) {
        if (arr[i] < min1) {
            // current min stays second
            min2 = min1;
            // new min (arr[i) becomes 1st min
            min1 = arr[i];
        }
        else if (arr[i] < min2 && arr[i] != min1) {
            min2 = arr[i];
        }
    }
    return min2;
}

void get2ndSmallest(int arr[], int size)
{
    int i, first, second;

    /* The array must have 2 or more items */
    if (size < 2)
    {
        printf(" Array has lesser than 2 items");
        return;
    }

    first = second = INT_MAX;
    for (i = 0; i < size; i++)
    {
        /* If the current array element is smaller than the first
        then update both first and second */
        if (arr[i] < first)
        {
            second = first;
            first = arr[i];
        }

        /* If arr[i] lies between first and second
        then update second */
        else if (arr[i] < second && arr[i] != first)
            second = arr[i];
    }
    if (second == INT_MAX)
        printf("We don't have 2nd smallest item in array\n");
    else
        printf("The 2nd smallest : %d\n", second);
}

int secSmallest(int arr[], int size)
{
    // assigning first element as smallest temporarily
    int smallest = arr[0];

    // we find the smallest element here
    for (int i = 0; i < size; i++) {
        if (arr[i] < smallest)
            smallest = arr[i];
    }

    // temporarily assinging largest max value
    int sec_smallest = INT_MAX;

    // finding second smallest here
    for (int i = 0; i < size; i++) {
        if (arr[i] != smallest && arr[i] < sec_smallest)
            sec_smallest = arr[i];
    }

    return sec_smallest;

}
