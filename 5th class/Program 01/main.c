#include<stdio.h>

void sort(int a[], int n)
{
    int i, j, temp;
    for(i=0; i<n-1; i++)
    {
        for(j=i+1; j<n; j++)
        {
            if(a[i] > a[j])
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}

int main()
{
    int n, i, cost = 0;

    printf("Enter the number of files: ");
    scanf("%d", &n);

    int a[n];

    printf("Enter file sizes:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);

    sort(a, n);

    printf("\nSorted file sizes:\n");
    for(i = 0; i < n; i++)
        printf("%d ", a[i]);

    printf("\n");

    while(n > 1)
    {
        int merge = a[0] + a[1];
        cost += merge;

        a[1] = merge;

        for(i = 0; i < n-1; i++)
            a[i] = a[i+1];

        n--;

        sort(a, n);  
    }

    printf("\nOptimal Merge Cost = %d\n", cost);

    return 0;
}