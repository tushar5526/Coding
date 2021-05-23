#include <stdio.h>

int power(int base, int a)
{
    if (a != 0)
        return (base * power(base, a - 1));
    else
        return 1;
}

void printTable(int a[100][100], int n, int choice)
{
    int i, j;
    if (choice == 1)
    {
        for (i = 0; i < power(2, n); ++i)
        {
            a[i][n] = a[i][0];
            for (j = 1; j < n; ++j)
            {
                a[i][n] &= a[i][j];
            }
        }
    }
    else if (choice == 2)
    {
        for (i = 0; i < power(2, n); ++i)
        {
            a[i][n] = a[i][0];
            for (j = 1; j < n; ++j)
            {
                a[i][n] |= a[i][j];
            }
        }
    }
    else
    {
        printf("A Q\n%d %d\n%d %d\n", 0, 1, 1, 0);
        return;
    }
    char o = 'A';
    for (i = 0; i < n; ++i)
    {
        printf("%c ", o);
        ++o;
    }
    printf("Q \n");
    for (i = 0; i < power(2, n); ++i)
    {
        for (j = 0; j <= n; ++j)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}

void print(int a[100][100], int n, int choice)
{
    int i, j;
    for (i = 0; i < power(2, n); ++i)
    {
        for (j = 0; j < n; ++j)
        {
            int tmp = i;
            a[i][j] = (tmp >> (j)) & 1;
        }
    }

    printTable(a, n, choice);
}

int main()
{
    int n, choice;
    printf("enter the value of n : ");
    scanf("%d", &n);
    printf("1 for AND, 2 for OR, 3 for AND\n");
    scanf("%d", &choice);
    int a[100][100];
    print(a, n, choice);
    return 0;
}