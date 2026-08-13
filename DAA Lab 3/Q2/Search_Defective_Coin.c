#include <stdio.h>

int getWeight(int coins[], int low, int high) {
    int sum = 0;
    for (int i = low; i <= high; i++) {
        sum += coins[i];
    }
    return sum;
}
int findDefectiveCoin(int coins[], int low, int high) {
    int n = high - low + 1;

    if (n == 1) {
        return low;
    }
    if (n == 2) {
        if (coins[low] < coins[high])
            return low;

        if (coins[high] < coins[low])
            return high;

        return -1;
    }
    int mid = low + (n / 2) - 1;
    int weight1, weight2;

    if (n % 2 == 0) {
        weight1 = getWeight(coins, low, mid);
        weight2 = getWeight(coins, mid + 1, high);

        if (weight1 < weight2) {
            return findDefectiveCoin(coins, low, mid);
        } else if (weight2 < weight1) {
            return findDefectiveCoin(coins, mid + 1, high);
        } else {
            return -1;
        }
    } else {
        weight1 = getWeight(coins, low, mid);
        weight2 = getWeight(coins, mid + 1, high - 1);

        if (weight1 < weight2) {
            return findDefectiveCoin(coins, low, mid);
        } else if (weight2 < weight1) {
            return findDefectiveCoin(coins, mid + 1, high - 1);
        } else {
            if (coins[high] < coins[low])
                return high;
            else
                return -1;
        }
    }
}
int main() {
    int n;
    printf("Enter the number of coins: ");
    scanf("%d", &n);

    if (n <= 1) {
        printf("Please enter at least 2 coins to perform a comparison.\n");
        return 0;
    }
    int coins[n];
    printf("Enter the weights of the %d coins:\n", n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &coins[i]);
    }
    int defective_index = findDefectiveCoin(coins, 0, n - 1);
    printf("\nResults:\n");

    if (defective_index != -1) {
        printf("The defective (lighter) coin is at position: %d\n",
               defective_index + 1);
        printf("Weight of the defective coin: %d\n",
               coins[defective_index]);
    } else {
        printf("No defective coin found. All coins are of equal weight.\n");
    }
    return 0;
}