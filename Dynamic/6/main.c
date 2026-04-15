//Coin change

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int coinChange(int* coins, int coinsSize, int amount) {
    int* dp = (int*)malloc((amount + 1) * sizeof(int));

    // Initialize DP array
    for (int i = 0; i <= amount; i++) {
        dp[i] = amount + 1; // acts like infinity
    }

    dp[0] = 0;

    // Fill DP
    for (int i = 1; i <= amount; i++) {
        for (int j = 0; j < coinsSize; j++) {
            if (coins[j] <= i) {
                if (dp[i - coins[j]] + 1 < dp[i]) {
                    dp[i] = dp[i - coins[j]] + 1;
                }
            }
        }
    }

    int result = (dp[amount] > amount) ? -1 : dp[amount];
    free(dp);
    return result;
}

int main() {
    int coins1[] = {1, 2, 5};
    int amount1 = 11;

    int coins2[] = {2};
    int amount2 = 3;

    int coins3[] = {1};
    int amount3 = 0;

    printf("Output 1: %d\n", coinChange(coins1, 3, amount1)); // 3
    printf("Output 2: %d\n", coinChange(coins2, 1, amount2)); // -1
    printf("Output 3: %d\n", coinChange(coins3, 1, amount3)); // 0

    return 0;
}