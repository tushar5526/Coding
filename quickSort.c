#include<stdio.h>

void swap(int arr[100], int i, int j){
    int t = arr[i];
    arr[i] = arr[j];
    arr[j] = t;
}

int partition(int a[100], int pivot, int lo, int hi){
    int i = lo, j = lo;
    while(i <= hi){
        if(a[i] <= pivot){
            swap(a, i, j);
            ++i;
            ++j;
        }
        else{
            ++i;
        }
    }
    for(i = lo; i <= hi; ++i) printf("%d ",a[i]);
    printf("\n");
    return (j-1);
}

void quickSort(int a[100], int lo, int hi){
    if(lo > hi) return;
    int pivot = a[hi];
    int pi = partition(a, pivot, lo, hi);
    quickSort(a, lo, pi-1);
    quickSort(a, pi+1, hi);
}


int main(){
    int n, i;
    int a[100];
    scanf("%d", &n);
    for(i = 0; i < n; ++i) scanf("%d", &a[i]);
    quickSort(a, 0, n - 1);
    for(i = 0; i < n; ++i) printf("%d ", a[i]);
}