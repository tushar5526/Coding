#include <stdio.h>

void findCartesianProduct(int arr1[], int arr2[], int n, int n1)
{
    printf("\nSet C contains : ");
    printf("{");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n1; j++)
        {
            if (i == n - 1 && j == n1 - 1)
                continue;
            printf("{%d, %d}, ", arr1[i], arr2[j]);
        }
    printf("{%d, %d}}\n", arr1[n - 1], arr2[n1 - 1]);
}

int main()
{
    int A[100];
    int B[100];

    int n1;
    int n2;
    printf("Enter the size of set A: ");
    scanf("%d", &n1);

    printf("Enter the %d elements of A: ", n1);
    for (int i = 0; i < n1; ++i)
        scanf("%d", &A[i]);

    printf("Enter the size of set B: ");
    scanf("%d", &n2);

    printf("Enter the %d elements of B: ", n2);
    for (int i = 0; i < n2; ++i)
        scanf("%d", &B[i]);

    findCartesianProduct(A, B, n1, n2);
    return 0;
}
