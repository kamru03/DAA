#include <stdio.h>

struct Item {
    int weight;
    int profit;
    float ratio;
};

void sort(struct Item arr[], int n) {
    struct Item temp;
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if(arr[j].ratio < arr[j+1].ratio) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main() {
    int n, capacity;

    printf("Enter number of items: ");
    scanf("%d", &n);

    struct Item arr[n];

    for(int i = 0; i < n; i++) {
        printf("Enter weight and profit of item %d: ", i+1);
        scanf("%d %d", &arr[i].weight, &arr[i].profit);
        arr[i].ratio = (float)arr[i].profit / arr[i].weight;
    }

    printf("Enter capacity of knapsack: ");
    scanf("%d", &capacity);

    sort(arr, n);

    int totalProfit = 0;
    int remainingCapacity = capacity;

    for(int i = 0; i < n; i++) {
        if(arr[i].weight <= remainingCapacity) {
            totalProfit += arr[i].profit;
            remainingCapacity -= arr[i].weight;
        }
    }

    printf("\nTotal Profit (Greedy 0/1): %d\n", totalProfit);

    return 0;
}