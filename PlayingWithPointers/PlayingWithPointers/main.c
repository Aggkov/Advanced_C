#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

int main() {
        int array[23][42];
        printf("size of array:   %I64d\n", sizeof(array));
        printf("size of row:     %I64d\n", sizeof(*array));
        printf("size of element: %I64d\n", sizeof(**array));

	return 0;
}