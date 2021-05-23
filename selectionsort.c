#include <stdio.h>

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void selectionSort(int arr[], int n)
{
    int i, j, id;

    for (i = 0; i < n - 1; i++)
    {
        id = i;
        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[id])
                id = j;

        swap(&arr[id], &arr[i]);
    }
}

void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
    int arr[100], n;
    printf("Enter the no.of elements : ");
    scanf("%d", &n);
    int i = 0;
    for (i = 0; i < n; ++i)
        scanf("%d", &arr[i]);
    selectionSort(arr, n);
    printf("Sorted array: \n");
    printArray(arr, n);
    return 0;
}