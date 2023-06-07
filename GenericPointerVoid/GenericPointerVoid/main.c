#include <stdio.h>

int main() {
	int a = 5;
	void* ptr = &a;
	// cast ptr to int and print ptr variable
	printf("%p", (int *)ptr);
	// cast ptr to int and derefence ptr
	printf("%d", *(int *)ptr);
}