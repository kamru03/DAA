//Number of digit one

#include <stdio.h>
#include <string.h>

int dp[12][12][2]; // pos, count of 1s, tight
char num[12];

// Digit DP function
int dfs(int pos, int count, int tight, int len) {
    // If all digits processed → return count of 1s
    if (pos == len) return count;

    if (dp[pos][count][tight] != -1)
        return dp[pos][count][tight];

    int limit = tight ? (num[pos] - '0') : 9;
    int res = 0;

    for (int d = 0; d <= limit; d++) {
        int newTight = (tight && (d == limit));
        int newCount = count + (d == 1 ? 1 : 0);

        res += dfs(pos + 1, newCount, newTight, len);
    }

    return dp[pos][count][tight] = res;
}

// Main function
int countDigitOne(int n) {
    sprintf(num, "%d", n);  // convert number to string
    int len = strlen(num);

    memset(dp, -1, sizeof(dp));

    return dfs(0, 0, 1, len);
}

int main() {
    int n1 = 13;
    int n2 = 0;

    printf("Output 1: %d\n", countDigitOne(n1)); // 6
    printf("Output 2: %d\n", countDigitOne(n2)); // 0

    return 0;
}