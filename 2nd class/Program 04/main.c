// Matrix Multiplication 1

#include <stdio.h>

int main(){
    int m1,n1, n2, m2;

    printf("Enter the number of row for first matrix:");
    scanf("%d", &m1);

    printf("Enter the number of columns for first matrix:");
    scanf("%d", &n1);

    printf("Enter the number of row for second matrix:");
    scanf("%d", &m2);

    printf("Enter the number of columns for second matrix:");
    scanf("%d", &n2);

    if(n1 != m2){
        printf("Multiplication is not possible");
        return 0;
    }

    int a1[m1][n1];
    int a2[m2][n2];

    printf("Enter the elements of the first matrix:\n");

    for(int i=0; i<m1; i++)
        for(int j=0; j<n1; j++) scanf("%d", &a1[i][j]);

    printf("Enter the elements of the second matrix:\n");
    
    for(int i=0; i<m2; i++)
        for(int j=0; j<n2; j++) scanf("%d", &a2[i][j]);

    int a3[m1][n2];

    for(int i=0;i<m1;i++){
        for(int j=0;j<n2;j++){
            a3[i][j] = 0;
            for(int k=0;k<n1;k++){
                a3[i][j] += a1[i][k] * a2[k][j];
            }
        }
    }
    printf("Resultant Matrix:\n");
    for(int i=0;i<m1;i++){
        for(int j=0;j<n2;j++)
            printf("%d ", a3[i][j]);
        printf("\n");
    }

    return 0;
}
