#include <stdio.h>

int main() {
	int a = 5;
	int* p1 = &a;
	int** p2 = &p1;
	*p1 = 10;
	**p2 = 7;
	printf("%d", a);
}