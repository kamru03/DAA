#include <stdio.h>

int main() {
    int n, capacity;
    printf("Enter number of items: ");
    scanf("%d", &n);

    int profit[n], weight[n];
    float ratio[n];

    for(int i=0; i<n; i++) {
        printf("Enter profit and weight: ");
        scanf("%d %d", &profit[i], &weight[i]);
        ratio[i] = (float)profit[i] / weight[i];
    }

    printf("Enter capacity: ");
    scanf("%d", &capacity);

    for(int i=0; i<n-1; i++) {
        for(int j=i+1; j<n; j++) {
            if(ratio[i] < ratio[j]) {
                float temp = ratio[i];
                ratio[i] = ratio[j];
                ratio[j] = temp;

                int t = profit[i];
                profit[i] = profit[j];
                profit[j] = t;

                t = weight[i];
                weight[i] = weight[j];
                weight[j] = t;
            }
        }
    }

    int totalProfit = 0;
    for(int i=0; i<n; i++) {
        if(weight[i] <= capacity) {
            totalProfit += profit[i];
            capacity -= weight[i];
        }
    }

    printf("Total Profit = %d", totalProfit);

    return 0;
}
