#include <stdio.h>

int power(int a, int b)
{
    int i;
    int ans = 1;
    for (i = 0; i < b; ++i)
    {
        ans *= a;
    }
    return ans;
}

void PowerSet(int a[100], int n)
{
    int pwSetSize = power(2, n);
    int val, j;
    for (val = 0; val < pwSetSize; val++)
    {
        int flag = 0;
        for (j = 0; j < n; j++)
        {
            if (val & (1 << j)){
                flag = 1;
                printf("%d", a[j]);
            }
        }
        if(flag == 0)
            printf("phi");
        printf("\n");
    }
}

int main()
{
    int n, a[100], i, j;
    printf("enter the value of n : ");
    scanf("%d", &n);
    printf("enter the n elements : ");
    for (i = 0; i < n; ++i)
    {
        scanf("%d", &a[i]);
    }
    PowerSet(a, n);
    return 0;
}