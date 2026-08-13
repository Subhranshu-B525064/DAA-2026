#include <stdio.h>

int comparisons = 0;

struct Pair {
    int min;
    int max;
};
struct Pair getMinMax(int arr[], int low, int high) {
    struct Pair minmax, minmax_left, minmax_right;
    int mid;

    if (low == high) {
        minmax.max = arr[low];
        minmax.min = arr[low];
        return minmax;
    }
    if (high == low + 1) {
        comparisons++;

        if (arr[low] > arr[high]) {
            minmax.max = arr[low];
            minmax.min = arr[high];
        } else {
            minmax.max = arr[high];
            minmax.min = arr[low];
        }
        return minmax;
    }
    mid = (low + high) / 2;

    minmax_left = getMinMax(arr, low, mid);
    minmax_right = getMinMax(arr, mid + 1, high);
    comparisons++;
    if (minmax_left.min < minmax_right.min)
        minmax.min = minmax_left.min;
    else
        minmax.min = minmax_right.min;

    comparisons++;
    if (minmax_left.max > minmax_right.max)
        minmax.max = minmax_left.max;
    else
        minmax.max = minmax_right.max;

    return minmax;
}
int main() {
    int n;

    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int arr[n];

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    comparisons = 0;

    struct Pair result = getMinMax(arr, 0, n - 1);

    printf("\nResults\n");
    printf("Minimum element: %d\n", result.min);
    printf("Maximum element: %d\n", result.max);

    double theoretical_bound = 1.5 * n;

    printf("\nValidation\n");
    printf("Actual Comparisons made: %d\n", comparisons);
    printf("Theoretical Upper Bound (3n/2): %.1f\n", theoretical_bound);

    if (comparisons <= theoretical_bound) {
        printf("Validation Successful: %d <= %.1f. The comparisons are bounded by 3n/2.\n",
               comparisons, theoretical_bound);
    } else {
        printf("Validation Failed.\n");
    }
    return 0;
}