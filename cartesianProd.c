#include <stdio.h>

int main()
{
    int n, m, i, j;
    printf("enter the size of set M and N \n");
    scanf("%d %d", &m, &n);
    int a[100], b[100];
    printf("enter the %d elements : ", m);
    for (i = 0; i < m; ++i)
    {
        scanf("%d", &a[i]);
    }
    printf("enter the %d elements : ", n);
    for (i = 0; i < n; ++i)
    {
        scanf("%d", &b[i]);
    }
    printf("{");
    for (i = 0; i < m; ++i)
    {
        for (j = 0; j < n; ++j)
        {
            printf("(%d,%d)", a[i], b[j]);
            if(i*j != (m - 1) * (n - 1))
                printf(", ");
        }
    }
    printf("}");
}