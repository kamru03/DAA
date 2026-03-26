#include <stdio.h>
#include <limits.h>

// Function to find minimum coins
int minCoins(int coins[], int n, int amount) {
    int dp[amount + 1];

    // Initialize dp array
    dp[0] = 0;
    for (int i = 1; i <= amount; i++) {
        dp[i] = INT_MAX;
    }

    // Compute minimum coins
    for (int i = 1; i <= amount; i++) {
        for (int j = 0; j < n; j++) {
            if (coins[j] <= i && dp[i - coins[j]] != INT_MAX) {
                if (dp[i] > dp[i - coins[j]] + 1) {
                    dp[i] = dp[i - coins[j]] + 1;
                }
            }
        }
    }

    return dp[amount] == INT_MAX ? -1 : dp[amount];
}

int main() {
    int n, amount;

    // Input number of coins
    printf("Enter number of coin types: ");
    scanf("%d", &n);

    int coins[n];

    // Input coin values
    printf("Enter coin values:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &coins[i]);
    }

    // Input amount
    printf("Enter amount: ");
    scanf("%d", &amount);

    int result = minCoins(coins, n, amount);

    if (result == -1)
        printf("Change cannot be formed\n");
    else
        printf("Minimum number of coins = %d\n", result);

    return 0;
}