#include <stdio.h>

int findTransitionPoint(int arr[], int n) {
    int low = 0;
    int high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == 0) {
            low = mid + 1;
        } 
        else {
            if (mid == 0 || arr[mid - 1] == 0) {
                return mid;
            }
            high = mid - 1;
        }
    }
    
    return -1; 
}

int main() {
    int n;

    printf("Enter the total number of elements in the array: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Error: Please enter a valid positive integer.\n");
        return 1;
    }

    int arr[n];

    printf("Enter the elements (a run of 0s followed by a run of 1s),separated by space:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int transition_index = findTransitionPoint(arr, n);

    if (transition_index != -1) {
        printf("The exact point of transition to 1 is at index: %d\n", transition_index);
    } else {
        printf("No transition to 1 was found.\n");
    }

    return 0;
}