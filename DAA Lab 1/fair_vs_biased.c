#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void simulate_coin_toss(int trials, double bias_probability) {
    int fair_heads = 0;
    int biased_heads = 0;

    for (int i = 0; i < trials; i++) {
        if (rand() % 2 == 1) {
            fair_heads++;
        }

        double random_val = (double)rand() / RAND_MAX;
        if (random_val < bias_probability) {
            biased_heads++;
        }
    }

    double fair_prob = (double)fair_heads / trials;
    double biased_prob = (double)biased_heads / trials;

    printf("Simulation Results for %d Trials\n", trials);
    
    printf("Fair Coin\n");
    printf("Heads count: %d\n", fair_heads);
    printf("Simulated Probability of Heads: %.4f (Expected: 0.5000)\n", fair_prob);

    printf("Biased Coin\n");
    printf("Heads count: %d\n", biased_heads);
    printf("Simulated Probability of Heads: %.4f (Expected: %.4f)\n", biased_prob, bias_probability);
}

int main() {
    int num_trials;
    double bias = 0.75; 

    srand(time(NULL));

    printf("Enter the number of trials for the coin toss simulation: ");
    if (scanf("%d", &num_trials) != 1 || num_trials <= 0) {
        printf("Invalid input. Please enter a positive integer.\n");
        return 1;
    }

    simulate_coin_toss(num_trials, bias);

    return 0;
}