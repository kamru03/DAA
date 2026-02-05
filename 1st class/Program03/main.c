// Delete the nth element in an array of m no.s. 

#include <stdio.h>          
int main() {    
int m, pos;                 // 1 
                            // 1 
                            //1 
printf("Enter number of elements: "); // 1 
scanf("%d", &m);       
int arr[100];                     // 1  1 
printf("Enter elements:\n");      // 1 
for (int i = 0; i < m; i++)    // n + 1 
scanf("%d", &arr[i]);         // n 
printf("Enter position to delete (1 to %d): ", m); // 1 
scanf("%d", &pos);     //1 
for (int i = pos - 1; i < m - 1; i++) // n - 1 + 1 
arr[i] = arr[i + 1];   // n - 1 
m--;                        // 1 
printf("Array after deletion:\n"); // 1 
for (int i = 0; i < m; i++) // n 
printf("%d ", arr[i]);  // n 
printf("\n");               // 1 
return 0;                   // 1 
}