#include <stdio.h>

int main() {
	int a = 5;
	int* p = NULL;
	// error, points to garbage not allowed to access. Init to NULL to solve
	printf("%p\n", p);
	//printf("%d", *p);

	/*int grades[3] = { 7,8,10 };
	printf("%p\n", grades);
	printf("%p\n", grades + 1);
	grades + 1;
	printf("%p\n", grades);

	char *str = 'abcd';
	printf("%p\n", str);
	printf("%p\n", str++);
	printf("%p\n", str);*/

	int *ptr;
	int d = 8;
	ptr = &d;
	printf("%d", sizeof(ptr));

}