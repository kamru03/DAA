#include <stdio.h>

// Function to count number of ways
int countWays(int coins[], int n, int amount) {
    int dp[amount + 1];

    // Initialize dp array
    for (int i = 0; i <= amount; i++)
        dp[i] = 0;

    dp[0] = 1; // Base case

    // Fill dp array
    for (int i = 0; i < n; i++) {
        for (int j = coins[i]; j <= amount; j++) {
            dp[j] += dp[j - coins[i]];
        }
    }

    return dp[amount];
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

    int result = countWays(coins, n, amount);

    printf("Number of ways to make change = %d\n", result);

    return 0;
}