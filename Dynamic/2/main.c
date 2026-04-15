// Trapping rain water 

#include <stdio.h>
#include <stdlib.h>

int min(int a, int b) {
    return (a < b) ? a : b;
}

int trap(int* height, int heightSize) {
    if (heightSize == 0) return 0;

    int* leftMax = (int*)malloc(sizeof(int) * heightSize);
    int* rightMax = (int*)malloc(sizeof(int) * heightSize);

    // Fill leftMax
    leftMax[0] = height[0];
    for (int i = 1; i < heightSize; i++) {
        leftMax[i] = (height[i] > leftMax[i - 1]) ? height[i] : leftMax[i - 1];
    }

    // Fill rightMax
    rightMax[heightSize - 1] = height[heightSize - 1];
    for (int i = heightSize - 2; i >= 0; i--) {
        rightMax[i] = (height[i] > rightMax[i + 1]) ? height[i] : rightMax[i + 1];
    }

    // Calculate trapped water
    int water = 0;
    for (int i = 0; i < heightSize; i++) {
        water += min(leftMax[i], rightMax[i]) - height[i];
    }

    free(leftMax);
    free(rightMax);

    return water;
}

int main() {
    int arr1[] = {0,1,0,2,1,0,1,3,2,1,2,1};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);

    int arr2[] = {4,2,0,3,2,5};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);

    printf("Output 1: %d\n", trap(arr1, n1)); // 6
    printf("Output 2: %d\n", trap(arr2, n2)); // 9

    return 0;
}