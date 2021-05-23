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
    printf("Enter the size of arrays n and m\n");
    int n, m;
    int a[1000];
    scanf("%d%d", &n, &m);
    printf("Enter the n and m elements\n");
    for (int i = 0; i < (n + m); ++i)
        scanf("%d", &a[i]);
    bubbleSort(a, n + m);

    int b[1000],k = 0;
    for (int i = 0; i < (n + m) - 1; ++i)
    {
        if (a[i] == a[i + 1]){
            b[k++] = a[i];
            ++i;
        }
    }

    printf("Intersection of arrays is \n");
    for(int i=0; i<k; ++i)
        printf("%d ",b[i]);
    
    if(k == 0)
        printf("PHI\n");
    return 0;
}
