// 	Quick Sort

#include <stdio.h>

#include <stdio.h>

int partition(int arr[], int low, int high) {      // T1(n)

    int pivot = arr[high];                         // 1
    int i = low - 1;                               // 1

    for (int j = low; j < high; j++) {             // n + 1

        if (arr[j] <= pivot) {                     // n
            i++;                                   // n

            int temp = arr[i];                     // n
            arr[i] = arr[j];                       // n
            arr[j] = temp;                         // n
        }
    }

    int temp = arr[i+1];                           // 1
    arr[i+1] = arr[high];                          // 1
    arr[high] = temp;                              // 1

    return i + 1;                                  // 1
}

void quickSort(int arr[], int low, int high) {     // T(n)

    if (low < high) {                              // 1

        int p = partition(arr, low, high);         // T1(n)

        quickSort(arr, low, p-1);                  // T(n/2)
        quickSort(arr, p+1, high);                 // T(n/2)
    }
}

int main() {
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    quickSort(arr, 0, n - 1);

    printf("Sorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}

