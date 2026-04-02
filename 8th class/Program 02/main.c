//Wap in c to perform Activity Selection

#include <stdio.h>

struct Activity {
    int start, finish;
};

void sortActivities(struct Activity arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j].finish > arr[j+1].finish) {
                struct Activity temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void activitySelection(struct Activity arr[], int n) {
    sortActivities(arr, n);

    printf("Selected activities:\n");

    int i = 0;
    printf("(%d, %d)\n", arr[i].start, arr[i].finish);

    for (int j = 1; j < n; j++) {
        if (arr[j].start >= arr[i].finish) {
            printf("(%d, %d)\n", arr[j].start, arr[j].finish);
            i = j;
        }
    }
}

int main() {
    int n;
    printf("Enter number of activities: ");
    scanf("%d", &n);

    struct Activity arr[n];

    for (int i = 0; i < n; i++) {
        printf("Enter start and finish time for activity %d: ", i+1);
        scanf("%d %d", &arr[i].start, &arr[i].finish);
    }

    activitySelection(arr, n);

    return 0;
}