#include <stdio.h> 
  
void merge(int arr[], int l, int m, int r) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 = r - m; 
  
    int la[100], ra[100]; 
  
    for (i = 0; i < n1; i++) 
        la[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        ra[j] = arr[m + 1 + j]; 
  
    i = 0; 
    j = 0; 
    k = l;
    while (i < n1 && j < n2) { 
        if (la[i] <= ra[j]) { 
            arr[k] = la[i]; 
            i++; 
        }
        else { 
            arr[k] = ra[j]; 
            j++; 
        } 
        k++; 
    } 
  
    while (i < n1) { 
        arr[k] = la[i]; 
        i++; 
        k++; 
    } 
  
    while (j < n2) { 
        arr[k] = ra[j]; 
        j++; 
        k++; 
    } 
} 
  
void mergeSort(int arr[], int l, int r) 
{ 
    if (l < r) { 
        int m = l + (r - l) / 2; 
  
        mergeSort(arr, l, m); 
        mergeSort(arr, m + 1, r); 
  
        merge(arr, l, m, r); 
    } 
} 

void printArray(int A[], int size) 
{ 
    int i; 
    for (i = 0; i < size; i++) 
        printf("%d ", A[i]); 
    printf("\n"); 
} 
  
int main() 
{ 
    int a[100];
    int n, i;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &a[i]);
    }
  
    mergeSort(a, 0, n - 1); 
  
    printf("Sorted array is \n"); 
    printArray(a, n); 
    return 0; 
} 