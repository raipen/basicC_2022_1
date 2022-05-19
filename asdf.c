#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <math.h>

typedef struct iris {
    double s_l;
    double s_w;
    double p_l;
    double p_w;
    char kind[100];
} iris;
typedef enum{Setosa, Versicolor, Virginica} irisKind;

irisKind checkKind(char* name) {
    return strcmp(name, "setosa") ? strcmp(name, "versicolor") ? 2 : 1 : 0;
}

int main(){
    iris input, av[3] = { 0 };
    int n[3] = { 0 };

    int a;
    scanf("%d", &a);

    for (int i = 0; i < a; i++) {
        scanf("%lf %lf %lf %lf %s", &input.s_l, &input.s_w, &input.p_l, &input.p_w, input.kind);

        irisKind k = checkKind(input.kind);

        av[k].s_l += input.s_l;
        av[k].s_w += input.s_w;
        av[k].p_l += input.p_l;
        av[k].p_w += input.p_w;
        strcpy(av[k].kind, input.kind);
        n[k]++;
    }

    for (int i = 0; i < 3; i++) {
        av[i].s_l /= n[i];
        av[i].s_w /= n[i];
        av[i].p_l /= n[i];
        av[i].p_w /= n[i];
    }

    scanf("%lf %lf %lf %lf", &input.s_l, &input.s_w, &input.p_l, &input.p_w);
    double test[3] = { 0 };

    for (int i = 0; i < 3; i++) {
        test[i] += fabs(av[i].s_l - input.s_l);
        test[i] += fabs(av[i].s_w - input.s_w);
        test[i] += fabs(av[i].p_l - input.p_l);
        test[i] += fabs(av[i].p_w - input.p_w);
        printf("%lf\n", test[i]);
    }

    int min = test[0] < test[1] ? 0 : 1;
    min = test[min] < test[2] ? min : 2;

    printf("%s", av[min].kind);

}
