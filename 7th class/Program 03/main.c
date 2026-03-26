#include <stdio.h>
#include <limits.h>

// Function to find minimum multiplications
int matrixChain(int p[], int n) {
    int dp[n][n];

    // cost is zero when multiplying one matrix
    for (int i = 1; i < n; i++) {
        dp[i][i] = 0;
    }

    // L is chain length
    for (int L = 2; L < n; L++) {
        for (int i = 1; i < n - L + 1; i++) {
            int j = i + L - 1;
            dp[i][j] = INT_MAX;

            for (int k = i; k < j; k++) {
                int cost = dp[i][k] + dp[k + 1][j] 
                           + p[i - 1] * p[k] * p[j];

                if (cost < dp[i][j]) {
                    dp[i][j] = cost;
                }
            }
        }
    }

    return dp[1][n - 1];
}

int main() {
    int n;

    // Input number of matrices
    printf("Enter number of matrices: ");
    scanf("%d", &n);

    int p[n + 1];

    // Input dimensions
    printf("Enter dimensions array (size %d):\n", n + 1);
    for (int i = 0; i <= n; i++) {
        scanf("%d", &p[i]);
    }

    int result = matrixChain(p, n + 1);

    printf("Minimum number of multiplications = %d\n", result);

    return 0;
}
