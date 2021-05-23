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

void printArray(int arr[], int size)
{
    int i;
    printf("sorted array is : ");
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int binarySearch(int arr[], int s, int e, int x)
{
    if (e >= s)
    {
        int m = (e + s) / 2;
        if (arr[m] == x)
            return m;

        if (arr[m] > x)
            return binarySearch(arr, s, m - 1, x);

        return binarySearch(arr, m + 1, e, x);
    }
    return -1;
}

int main()
{
    int arr[100], n, x;
    printf("Enter the no.of elements : ");
    scanf("%d", &n);
    int i = 0;
    for (i = 0; i < n; ++i)
        scanf("%d", &arr[i]);
    bubbleSort(arr, n);
    printArray(arr, n);
    printf("Enter the element to be searched : ");
    scanf("%d", &x);
    printf("Element found at %d\n", binarySearch(arr, 0, n - 1, x));
    return 0;
}