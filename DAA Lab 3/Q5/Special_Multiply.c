#include <stdio.h>

void specialMultiply(int n, int A[n][n], int B[n][n], int C[n][n]) {
    if (n == 1) {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }

    int half = n / 2;

    int X_plus_Y[half][half], U_plus_V[half][half];
    int X_minus_Y[half][half], U_minus_V[half][half];
    int M1[half][half], M2[half][half];

    for (int i = 0; i < half; i++) {
        for (int j = 0; j < half; j++) {
            X_plus_Y[i][j] = A[i][j] + A[i][j + half];
            U_plus_V[i][j] = B[i][j] + B[i][j + half];

            X_minus_Y[i][j] = A[i][j] - A[i][j + half];
            U_minus_V[i][j] = B[i][j] - B[i][j + half];
        }
    }

    specialMultiply(half, X_plus_Y, U_plus_V, M1);
    specialMultiply(half, X_minus_Y, U_minus_V, M2);

    for (int i = 0; i < half; i++) {
        for (int j = 0; j < half; j++) {
            int P = (M1[i][j] + M2[i][j]) / 2;
            int Q = (M1[i][j] - M2[i][j]) / 2;

            C[i][j] = P;
            C[i][j + half] = Q;
            C[i + half][j] = Q;
            C[i + half][j + half] = P;
        }
    }
}

int main() {
    int n;

    printf("Enter matrix size n x n: ");
    scanf("%d", &n);

    if (n < 1 || (n & (n - 1)) != 0) {
        printf("Matrix size must be a power of 2.\n");
        return 0;
    }

    int A[n][n], B[n][n], C[n][n];

    printf("Enter elements of Matrix A:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    printf("Enter elements of Matrix B:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &B[i][j]);
        }
    }

    specialMultiply(n, A, B, C);

    printf("\nResult Matrix C:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

    return 0;
}