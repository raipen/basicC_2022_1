#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int checkTwins(int i) {
    if (i == 0||i/10==0) return 1;
    if (i % 10 != i / 10 % 10) return 0;
    return checkTwins(i / 100);
}

int main() {
    int x;
    while (scanf("%d", &x) && x)
        printf("%s\n", checkTwins(x)?"yes":"no");
    return 0;
}