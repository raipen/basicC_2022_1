#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void printReverse(int i) {
    if (i == 0) return;
    printf("%d", i % 10);
    printReverse(i / 10);
}

int main() {
    int x;
    scanf("%d", &x);
    printReverse(x);
    return 0;
}