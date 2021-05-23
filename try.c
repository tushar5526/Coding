#include <stdio.h>

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void bubbleSort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
}

int main()
{
    int n, m, a[100], b[100], c[100], d[100], e[100], i, j;
    printf("Enter the size of two arrays \n");
    scanf("%d %d", &n, &m);

    printf("enter the %d elements of first set\n", n);
    for (i = 0; i < n; ++i)
    {
        scanf("%d", &d[i]);
    }

    printf("enter the %d elements of first set\n", m);
    for (i = 0; i < m; ++i)
    {
        scanf("%d", &e[i]);
    }

    int nn = 0;
    for (int i = 0; i < n - 1; ++i)
    {
        if (d[i] == d[i + 1])
            continue;
        else
        {
            a[nn++] = d[i];
        }
    }

    printf("\n");
    if(d[n-2] != d[n-1])
        a[nn++] = d[n-1];

    int mm = 0;
    for (int i = 0; i < m - 1; ++i)
    {
        if (e[i] == e[i + 1])
            continue;
        else{
            b[mm++] = e[i];
        }
    }

    if(e[m-2] != e[m-1])
        b[mm++] = e[m-1];
    
    int k = 0;
    for (i = 0; i < mm; ++i)
    {
        int flag = 0;
        for (j = 0; j < nn; ++j)
        {
            if (b[i] == a[j])
            {
                flag = 1;
                break;
            }
        }

        if (flag == 0)
            c[k++] = b[i];
    }
    for (i = 0; i < nn; ++i)
        c[k++] = a[i];

    bubbleSort(c, k);
    printf("Union is \n");
    for (i = 0; i < k; ++i)
        printf("%d ", c[i]);

    return 0;
}
