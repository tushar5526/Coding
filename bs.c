#include <stdio.h>

int main()
{
    int n, m, i, l = 0, h, mid = (l + h) / 2;
    scanf("%d %d", &n, &m);
    h = n;
    int a[100];
    for (i = 0; i < n; ++i)
    {
        int tmp;
        scanf("%d",&tmp);
        a[i] = tmp;
    }

    while(h >= l){
        mid = (l + h)/2;
        if(a[mid] == m){
            printf("%d\n",mid);
            break;
        }
        else if(m > a[mid]){
            l = mid + 1;
        }
        else if(m < a[mid]){
            h = mid - 1;
        }
    }
    if(h < l)
        printf("-1");

    return 0;
}