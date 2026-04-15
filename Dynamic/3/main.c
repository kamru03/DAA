// Minimum Path Sum

#include <stdio.h>
#include <stdlib.h>

int min(int a, int b) {
    return (a < b) ? a : b;
}

int minPathSum(int** grid, int gridSize, int* gridColSize) {
    int m = gridSize;
    int n = gridColSize[0];

    // Create DP array
    int** dp = (int**)malloc(m * sizeof(int*));
    for (int i = 0; i < m; i++) {
        dp[i] = (int*)malloc(n * sizeof(int));
    }

    // Initialize first cell
    dp[0][0] = grid[0][0];

    // First row
    for (int j = 1; j < n; j++) {
        dp[0][j] = dp[0][j - 1] + grid[0][j];
    }

    // First column
    for (int i = 1; i < m; i++) {
        dp[i][0] = dp[i - 1][0] + grid[i][0];
    }

    // Fill rest
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            dp[i][j] = grid[i][j] + min(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    int result = dp[m - 1][n - 1];

    // Free memory
    for (int i = 0; i < m; i++) {
        free(dp[i]);
    }
    free(dp);

    return result;
}

int main() {
    int row1[] = {1,3,1};
    int row2[] = {1,5,1};
    int row3[] = {4,2,1};

    int* grid1[] = {row1, row2, row3};
    int colSize1[] = {3,3,3};

    int row4[] = {1,2,3};
    int row5[] = {4,5,6};

    int* grid2[] = {row4, row5};
    int colSize2[] = {3,3};

    printf("Output 1: %d\n", minPathSum(grid1, 3, colSize1)); // 7
    printf("Output 2: %d\n", minPathSum(grid2, 2, colSize2)); // 12

    return 0;
}