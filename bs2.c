#include <stdio.h>

int main()
{
    int n, i, l = 0, h, mid = (l + h) / 2;
    scanf("%d", &n);
    h = n;
    int a[100];
    for (i = 0; i < n; ++i)
    {
        int tmp;
        scanf("%d", &tmp);
        a[i] = tmp;
    }

    while (h >= l)
    {
        mid = (l + h) / 2;
        if (a[mid] > 0)
        {
            if (mid == 0)
            {
                printf("%d\n", mid);
                break;
            }
            else if (a[mid - 1] <= 0)
            {
                printf("%d\n", mid);
                break;
            }
            else{
                h = mid-1;
            }
        }
        else if (0 > a[mid])
        {
            l = mid + 1;
        }
        else if (0 < a[mid])
        {
            h = mid - 1;
        }
    }
    if (h < l)
        printf("-1");

    return 0;
}