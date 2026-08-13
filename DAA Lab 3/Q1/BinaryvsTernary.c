#include <stdio.h>
#include <stdlib.h>

long long binary_comp = 0, ternary_comp = 0;

int binarySearch(int a[], int n, int x) {
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        binary_comp++;
        if (a[mid] == x)
            return mid;

        binary_comp++;
        if (x < a[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }

    return -1;
}

int ternarySearch(int a[], int n, int x) {
    int low = 0, high = n - 1;

    while (low <= high) {
        int third = (high - low) / 3;
        int mid1 = low + third;
        int mid2 = high - third;

        ternary_comp++;
        if (a[mid1] == x)
            return mid1;

        ternary_comp++;
        if (a[mid2] == x)
            return mid2;

        ternary_comp++;
        if (x < a[mid1])
            high = mid1 - 1;
        else if (x > a[mid2])
            low = mid2 + 1;
        else {
            low = mid1 + 1;
            high = mid2 - 1;
        }
    }

    return -1;
}
int main() {
    int n, x, i, b, t;
    printf("Enter size of sorted array: ");
    scanf("%d", &n);

    int *a = malloc(n * sizeof(int));

    printf("Enter %d sorted elements:\n", n);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("Enter element to search: ");
    scanf("%d", &x);

    binary_comp = ternary_comp = 0;
    b = binarySearch(a, n, x);
    t = ternarySearch(a, n, x);

    printf("\nBinary Search:\n");
    if (b != -1)
        printf("Element found at index %d\n", b);
    else
        printf("Element not found\n");
    printf("Comparisons = %lld\n", binary_comp);

    printf("\nTernary Search:\n");
    if (t != -1)
        printf("Element found at index %d\n", t);
    else
        printf("Element not found\n");
    printf("Comparisons = %lld\n", ternary_comp);

    free(a);
    return 0;
}