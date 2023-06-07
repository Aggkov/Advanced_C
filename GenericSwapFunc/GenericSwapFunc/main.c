#include <stdio.h>
#include <stdlib.h>

void swap(void *p1, void *p2, unsigned int size);
void swapWithMemCpy(void* p1, void* p2, unsigned int size);

int main() {
	
	int a = 5;
	int b = 7;
	double c = 5.0;
	double d = 4.7;
	printf("%d %d\n", a, b);
	printf("%lf %lf\n", c, d);
	swapWithMemCpy(&a, &b, 4);
	swapWithMemCpy(&c, &d, 8);
	printf("%d %d\n", a, b);
	printf("%lf %lf\n", c, d);
}

void swap(void *p1, void *p2, unsigned int size) {
	if (size == sizeof(int)) {
		int tmp = 0;
		tmp = *(int*)p1;
		*(int*)p1 = *(int*)p2;
		*(int*)p2 = tmp;
	}
	if (size == sizeof(double)) {
		int tmp = 0;
		tmp = *(double*)p1;
		*(double*)p1 = *(double*)p2;
		*(double*)p2 = tmp;
	}
}

void swapWithMemCpy(void* p1, void* p2, unsigned int size) {
	// conditions and casting not required, size determines how many bytes will get copied from src to dest
	void* tmp = malloc(size);
	memcpy(tmp, p1, size);
	memcpy(p1, p2, size);
	memcpy(p2, tmp, size);
	free(tmp);
}