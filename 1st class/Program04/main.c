//  Insert an element at nth position in an array.

#include <stdio.h>                 // 1 
 
int main() {                       // 1 
    int n, pos, x;                 // 1 
 
    printf("Enter number of elements: "); // 1 
    scanf("%d", &n);               // 1 
 
    int arr[100];                  // 1 
 
    printf("Enter elements:\n");   // 1 
    for (int i = 0; i < n; i++)    // n + 1 
        scanf("%d", &arr[i]);      // n 
 
    printf("Enter element to insert: "); // 1 
    scanf("%d", &x);               // 1 
 
    printf("Enter position (1 to %d): ", n + 1); // 1 
    scanf("%d", &pos);             // 1 
 
    for (int i = n; i >= pos; i--) { // n + 1 
        arr[i] = arr[i - 1];       // n 
    } 
 
    arr[pos - 1] = x;               // 1 
    n++;                             // 1 
 
    printf("Array after insertion:\n"); // 1 
    for (int i = 0; i < n; i++)     // n + 1 
        printf("%d ", arr[i]);      // n 
    printf("\n");                    // 1 
 
    return 0;                        // 1 
}