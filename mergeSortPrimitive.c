#include <stdio.h>

int main()
{
    int a[100], b[100], c[100];
    int m, n, i, j;
    scanf("%d%d", &m, &n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < m; ++i)
    {
        scanf("%d", &b[i]);
    }
    int x = 0, y = 0, id = 0;
    while (x < n && y < m)
    {
        if (a[x] < b[y])
        {
            c[id++] = a[x++];
        }
        else
        {
            c[id++] = a[y++];
        }
    }
    while(x < n){
        c[id++] = a[x++];
    }
    while(y < m){
        c[id++] = b[y++];
    }

    for(i =0; i<m+n; ++i){
        printf("%d ", c[i]);
    }

    return 0;
}