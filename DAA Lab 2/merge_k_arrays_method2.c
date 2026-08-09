#include <stdio.h>
#include <stdlib.h>

void merge(int a[], int n1, int b[], int n2, int result[]) {
    int i = 0, j = 0, k = 0;
    while (i < n1 && j < n2) {
        if (a[i] <= b[j])
            result[k++] = a[i++];
        else
            result[k++] = b[j++];
    }
    while (i < n1)
        result[k++] = a[i++];

    while (j < n2)
        result[k++] = b[j++];
}
int main() {
    int k, n;
    printf("Enter number of arrays: ");
    scanf("%d", &k);
    printf("Enter number of elements in each array: ");
    scanf("%d", &n);

    int **arrays = (int **)malloc(k * sizeof(int *));
    int *sizes = (int *)malloc(k * sizeof(int));
    for (int i = 0; i < k; i++) {
        arrays[i] = (int *)malloc(n * sizeof(int));
        sizes[i] = n;

        printf("Enter %d sorted elements of Array %d:\n", n, i + 1);
        for (int j = 0; j < n; j++)
            scanf("%d", &arrays[i][j]);
    }
    int current = k;
    while (current > 1) {
        int newCount = 0;

        for (int i = 0; i < current; i += 2) {
            if (i + 1 < current) {
                int newSize = sizes[i] + sizes[i + 1];
                int *temp = (int *)malloc(newSize * sizeof(int));
                merge(arrays[i], sizes[i], arrays[i + 1], sizes[i + 1], temp);

                free(arrays[i]);
                free(arrays[i + 1]);
                arrays[newCount] = temp;
                sizes[newCount] = newSize;
            }
            else {
                arrays[newCount] = arrays[i];
                sizes[newCount] = sizes[i];
            }
            newCount++;
        }
        current = newCount;
    }
    printf("Merged Array:\n");
    for (int i = 0; i < sizes[0]; i++)
        printf("%d ", arrays[0][i]);

    printf("\n");
    free(arrays[0]);
    free(arrays);
    free(sizes);

    return 0;
}