//Split array largest sum

#include <stdio.h>

// Helper function: check if we can split into <= k subarrays
int canSplit(int* nums, int n, int k, int maxSum) {
    int count = 1;
    int currentSum = 0;

    for (int i = 0; i < n; i++) {
        if (currentSum + nums[i] <= maxSum) {
            currentSum += nums[i];
        } else {
            count++;
            currentSum = nums[i];
        }
    }

    return count <= k;
}

int splitArray(int* nums, int numsSize, int k) {
    int left = 0, right = 0;

    // Initialize bounds
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] > left) left = nums[i]; // max element
        right += nums[i]; // total sum
    }

    int result = right;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (canSplit(nums, numsSize, k, mid)) {
            result = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return result;
}

int main() {
    int nums1[] = {7,2,5,10,8};
    int k1 = 2;

    int nums2[] = {1,2,3,4,5};
    int k2 = 2;

    printf("Output 1: %d\n", splitArray(nums1, 5, k1)); // 18
    printf("Output 2: %d\n", splitArray(nums2, 5, k2)); // 9

    return 0;
}