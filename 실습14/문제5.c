#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void printless(int n) {
	if (n <= 0)
		return;
	printless(n - 1);
	printf("%d" , n);
	printless(n - 1);
}

int main() {
	int n;
	scanf("%d", &n);
	printless(n);
	return 0;
}