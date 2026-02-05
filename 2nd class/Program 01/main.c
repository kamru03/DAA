// 	Binary Search

#include <stdio.h>

int binarysearch(int arr[], int low, int high, int target); //T(n)

int main(){

    int n, t;
    
    printf("Enter the length of the array:");
    scanf("%d", &n);
    int arr[n];

    printf("Enter the elements of the array:");
    
    for(int i=0; i<n; i++) scanf("%d", &arr[i]);

    printf("Enter the target:");
    scanf("%d", &t);

    int res = binarysearch(arr, 0, n, t);

    if(res == -1) printf("Element not found in array \n");
    else printf("Element found at pos: %d\n", res);

    return 0;

}

int binarysearch(int arr[], int low, int high, int target){ // T(n)

    if (high >= low){ //1

        int mid = low + ((high-low)/2); //1

        if(arr[mid] == target)/*1*/ return mid; //1

        if(arr[mid] > target)/*1*/ return binarysearch(arr, low, mid-1, target); 

        if(arr[mid] < target)/*1*/ return binarysearch(arr, mid+1, high, target); 

    }

    return -1;

}
