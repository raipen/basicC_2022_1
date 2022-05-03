#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int gcd(int u, int v) {
    return v==0? u: gcd(v, u % v);
}

int main() {
    int x, y;
    while (scanf("%d %d", &x, &y)&&x&&y)
        printf("%d\n", gcd(x, y));
    return 0;
}