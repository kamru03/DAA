// Merge Sort

#include <stdio.h>

void merge(int arr[], int l, int m, int r) {   // T1(n)

    int n1 = m - l + 1;                        // 1
    int n2 = r - m;                            // 1

    int L[n1], R[n2];                          // 1

    for (int i = 0; i < n1; i++)               // n1 + 1
        L[i] = arr[l + i];                     // n1

    for (int j = 0; j < n2; j++)               // n2 + 1
        R[j] = arr[m + 1 + j];                 // n2

    int i = 0, j = 0, k = l;                   // 1

    while (i < n1 && j < n2) {                 // n + 1
        if (L[i] <= R[j])                      // n
            arr[k++] = L[i++];                 // n
        else
            arr[k++] = R[j++];                 // n
    }

    while (i < n1)                             // n1 + 1
        arr[k++] = L[i++];                     // n1

    while (j < n2)                             // n2 + 1
        arr[k++] = R[j++];                     // n2
}

void mergeSort(int arr[], int l, int r) {     // T(n)
    if (l < r) {
        int m = (l + r) / 2;
        mergeSort(arr, l, m);                 // T(n/2)
        mergeSort(arr, m + 1, r);             // T(n/2)
        merge(arr, l, m, r);                  // T1(n)
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

    mergeSort(arr, 0, n - 1);

    printf("Sorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
