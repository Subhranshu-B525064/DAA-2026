#include <stdio.h>

long long total_moves = 0;

void towerOfHanoi(int n, char source, char auxiliary, char destination) {
    if (n == 1) {
        total_moves++;
        return;
    }
    
    towerOfHanoi(n - 1, source, destination, auxiliary);
    total_moves++;
    towerOfHanoi(n - 1, auxiliary, source, destination);
}

int main() {
    int n;
    
    printf("Enter the maximum number of discs (n): ");
    if (scanf("%d", &n) != 1 || n < 1) {
        printf("Invalid input. Please enter a positive integer.\n");
        return 1;
    }
    
    printf("N-Discs | Total Moves\n");
    
    for (int i = 1; i <= n; i++) {
        total_moves = 0; 
        towerOfHanoi(i, 'A', 'B', 'C');
        printf("   %2d   | %lld\n", i, total_moves);
    }
    
    return 0;
}