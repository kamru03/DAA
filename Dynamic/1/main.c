//Longest Valid Parentheses

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int longestValidParentheses(char* s) {
    int n = strlen(s);
    if (n == 0) return 0;

    int* dp = (int*)calloc(n, sizeof(int));
    int maxLen = 0;

    for (int i = 1; i < n; i++) {
        if (s[i] == ')') {
            
            // Case 1: "()"
            if (s[i - 1] == '(') {
                dp[i] = (i >= 2 ? dp[i - 2] : 0) + 2;
            }
            // Case 2: "))"
            else {
                int prevLen = dp[i - 1];
                int j = i - prevLen - 1;

                if (j >= 0 && s[j] == '(') {
                    dp[i] = prevLen + 2 + (j >= 1 ? dp[j - 1] : 0);
                }
            }

            maxLen = max(maxLen, dp[i]);
        }
    }

    free(dp);
    return maxLen;
}

int main() {
    char s1[] = "(()";
    char s2[] = ")()())";
    char s3[] = "";

    printf("Output 1: %d\n", longestValidParentheses(s1)); // 2
    printf("Output 2: %d\n", longestValidParentheses(s2)); // 4
    printf("Output 3: %d\n", longestValidParentheses(s3)); // 0

    return 0;
}