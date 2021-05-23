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
   for (i = 0; i < n-1; i++)       
  
       // Last i elements are already in place    
       for (j = 0; j < n-i-1; j++)  
           if (arr[j] > arr[j+1]) 
              swap(&arr[j], &arr[j+1]); 
} 

void diff(int a[1000], int b[1000], int na, int nb)
{
    int k = 0;
    int c[1000];
    for (int i = 0; i < na; ++i)
    {
        int flag = 0;
        for (int j = 0; j < nb; ++j)
        {
            if (a[i] == b[j])
            {
                flag = 1;
                break;
            }
        }
        if (flag == 0)
            c[k++] = a[i];
    }

    printf("A-B is \n");
    for (int i = 0; i < k; ++i)
        printf("%d ", c[i]);
}

int symDiff(int a[1000], int b[1000], int na, int nb)
{
    int k = 0, l = 0, m = 0, i, j;
    int c[1000], d[1000], e[1000];

    //a - b
    for (i = 0; i < na; ++i)
    {
        int flag = 0;
        for (j = 0; j < nb; ++j)
        {
            if (a[i] == b[j])
            {
                flag = 1;
                break;
            }
        }
        if (flag == 0)
            c[k++] = a[i];
    }

    //b - a 
    for (i = 0; i < nb; ++i)
    {
        int flag = 0;
        for (j = 0; j < na; ++j)
        {
            if (a[j] == b[i])
            {
                flag = 1;
                break;
            }
        }
        if (flag == 0)
            d[l++] = a[i];
    }   
    //union
    for(i=0; i<l; ++i){
        int flag = 0;
        for(j=0; j<k; ++j){
            if(d[i] == c[j]){
                flag = 1;
                break;
            }
        }
        if(flag == 0)
            e[m++] = d[i];
    }
    for(i = 0; i<k; ++i){
        e[m++] = c[i];
    }

    bubbleSort(e,m);

    printf("\nSymm diff is \n");
    for(i = 0; i<m; ++i)
        printf("%d ", e[i]);
}

int main()
{
    int k = 0;
    int na, nb;
    int a[1000], b[1000];
    printf("Enter the size of sets a and b\n");
    scanf("%d%d", &na, &nb);
    printf("Enter the %d elements of set A\n", na);
    for (int i = 0; i < na; ++i)
        scanf("%d", &a[i]);
    printf("Enter the %d elements of set B\n", nb);
    for (int i = 0; i < nb; ++i)
        scanf("%d", &b[i]);

    diff(a, b, na, nb);
    symDiff(a, b, na, nb);
    return 0;
}