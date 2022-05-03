#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void printBin(int a) {
    if (a == 0) return;
    printBin(a / 2);
    printf("%d", a%2);
}

void printFloatBin(double a) {
    if (a == 0)
        printf("0");
    for (int i = 0; i < 10 && a != 0; i++, a = a * 2 - (int)(a * 2))
        printf("%d", (int)(a * 2));
}

int main() {
    double x;
    while (scanf("%lf", &x) && x) {
        printBin((int)x);
        printf(".");
        printFloatBin(x - (int)x);
        printf("\n");
    }
    return 0;
}