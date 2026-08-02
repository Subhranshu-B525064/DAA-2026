#include <stdio.h>

int main() {
    int n, i, j;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d elements:\n", n);

    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int duplicate = 0;

    for(i = 0; i < n - 1; i++) {
        for(j = i + 1; j < n; j++) {
            if(arr[i] == arr[j]) {
                duplicate = 1;
                printf("\nDuplicate Element Found : %d\n", arr[i]);
                printf("Position : %d and %d\n", i, j);
                break;
            }
        }

        if(duplicate) {
            break;
        }
    }

    if(!duplicate) {
        printf("All elements are unique.\n");
    }

    return 0;
}