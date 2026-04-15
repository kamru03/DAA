//Predict the winner

#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int predictTheWinner(int* nums, int numsSize) {
    int dp[21][21] = {0};

    // Base case: single element
    for (int i = 0; i < numsSize; i++) {
        dp[i][i] = nums[i];
    }

    // Fill DP table
    for (int len = 2; len <= numsSize; len++) {
        for (int i = 0; i <= numsSize - len; i++) {
            int j = i + len - 1;

            int pickLeft = nums[i] - dp[i + 1][j];
            int pickRight = nums[j] - dp[i][j - 1];

            dp[i][j] = max(pickLeft, pickRight);
        }
    }

    return dp[0][numsSize - 1] >= 0;
}

int main() {
    int nums1[] = {1,5,2};
    int nums2[] = {1,5,233,7};

    printf("Output 1: %d\n", predictTheWinner(nums1, 3)); // 0 (false)
    printf("Output 2: %d\n", predictTheWinner(nums2, 4)); // 1 (true)

    return 0;
}