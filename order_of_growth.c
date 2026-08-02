#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef struct {
    const char* name;
    double value;
} FuncGrowth;

double f0_inv(double n) { return 1.0 / n; }
double f1_log(double n) { return log2(n); }
double f2_sqrt(double n) { return 12 * sqrt(n); }
double f3_sqrt_50(double n) { return 50 * pow(n, 0.5); }
double f4_frac_poly(double n) { return pow(n, 0.51); }
double f5_linear(double n) { return pow(2, 32) * n; }
double f6_nlogn(double n) { return n * log2(n); }
double f7_quad1(double n) { return pow(n, 2) - 324; }
double f8_quad2(double n) { return 100 * pow(n, 2) + 6 * n; }
double f9_cubic(double n) { return 2 * pow(n, 3); }
double f10_superpoly(double n) { return pow(n, log2(n)); }
double f11_exp(double n) { return pow(3, n); }

int compare(const void* a, const void* b) {
    FuncGrowth* funcA = (FuncGrowth*)a;
    FuncGrowth* funcB = (FuncGrowth*)b;
    if (funcA->value < funcB->value) return -1;
    if (funcA->value > funcB->value) return 1;
    return 0;
}

int main() {
    double n = 500.0; 
    
    FuncGrowth functions[12] = {
        {"1/n", f0_inv(n)},
        {"log2(n)", f1_log(n)},
        {"12 * sqrt(n)", f2_sqrt(n)},
        {"50 * n^0.5", f3_sqrt_50(n)},
        {"n^0.51", f4_frac_poly(n)},
        {"2^32 * n", f5_linear(n)},
        {"n * log2(n)", f6_nlogn(n)},
        {"n^2 - 324", f7_quad1(n)},
        {"100n^2 + 6n", f8_quad2(n)},
        {"2n^3", f9_cubic(n)},
        {"n^log2(n)", f10_superpoly(n)},
        {"3^n", f11_exp(n)}
    };

    qsort(functions, 12, sizeof(FuncGrowth), compare);

    printf("Function Order (Lowest to Highest for n = %.0f):\n", n);
    for (int i = 0; i < 12; i++) {
        printf("%d. %s\n", i + 1, functions[i].name);
    }

    printf("Evaluated Data for n = %.0f:\n", n);
    for (int i = 0; i < 12; i++) {
        printf("%-15s : %e\n", functions[i].name, functions[i].value);
    }
    
    return 0;
}