#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int optimizedBubbleSort(int arr[], int n) {
    int comparisons = 0;
    int swapped;
    for (int i = 0; i < n - 1; i++) {
        swapped = 0;
        for (int j = 0; j < n - i - 1; j++) {
            comparisons++;
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1;
            }
        }
        if (swapped == 0) {
            break;
        }
    }
    return comparisons;
}

int normalBubbleSort(int arr[], int n) {
    int comparisons = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            comparisons++;
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    return comparisons;
}

void fillRandomArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 1000; 
    }
}

void copyArray(int source[], int dest[], int n) {
    for (int i = 0; i < n; i++) {
        dest[i] = source[i];
    }
}

int main() {
    int sizes[] = {10, 20, 30, 40, 50};
    int num_sizes = sizeof(sizes) / sizeof(sizes[0]);

    srand(time(0)); 

    printf("Array Size(n) | Normal Comparisons | Optimized Comparisons\n");
    for (int i = 0; i < num_sizes; i++) {
        int n = sizes[i];
        int* arr1 = (int*)malloc(n * sizeof(int));
        int* arr2 = (int*)malloc(n * sizeof(int));

        fillRandomArray(arr1, n);
        copyArray(arr1, arr2, n); 

        int normal_comps = normalBubbleSort(arr1, n);
        int opt_comps = optimizedBubbleSort(arr2, n);

        printf("%-13d | %-18d | %-21d\n", n, normal_comps, opt_comps);

        free(arr1);
        free(arr2);
    }

    return 0;
}