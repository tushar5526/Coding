#include <stdio.h>

void print(int *arr, int n)
{
    if(n == 0) printf("null");
    for (int i = 0; i < n; ++i)
        printf("%d ", arr[i]);
    printf("  => SIZE : %d", n);
    printf("\n");
}

int setDiff(int arr1[], int arr2[], int res[], int m, int n)
{
    int i, j, k = 0, flag = 1;
    for (int i = 0; i < m; ++i)
    {
        flag = 1;
        for (int j = 0; j < n; ++j)
        {
            if (arr1[i] == arr2[j])
            {
                flag = 0;
                break;
            }
        }
        if (flag)
        {
            res[k++] = arr1[i];
        }
    }
    return k;
}

int Union(int arr1[], int arr2[], int res[], int len1, int len2)
{

    int f, i, j, k = 0;

    for (i = 0; i < len1; i++)
    {
        res[k] = arr1[i];
        k++;
    }

    for (i = 0; i < len2; i++)
    {
        f = 0;
        for (j = 0; j < len1; j++)
        {
            if (arr2[i] == arr1[j])
            {
                f = 1;
                break;
            }
        }

        if (f == 0)
        {
            res[k] = arr2[i];
            k++;
        }
    }
    return k;
}

int Intersection(int arr1[], int arr2[], int res[], int len1, int len2)
{

    int i, j, k = 0;

    for (i = 0; i < len1; i++)
    {
        for (j = 0; j < len2; j++)
        {
            if (arr1[i] == arr2[j])
            {
                res[k] = arr1[i];
                k++;
                break;
            }
        }
    }
    return k;
}

int main()
{

    int arr1[100];
    int arr2[100];
    int arr3[100];
    int i, j, len1, len2, len3;

    printf("Enter size of 1st array:");
    scanf("%d", &len1);

    printf("Enter 1st array elements:");
    for (i = 0; i < len1; i++)
    {
        scanf("%d", &arr1[i]);
    }

    printf("Enter size of 2nd array:");
    scanf("%d", &len2);

    printf("Enter 2nd array elements:");
    for (i = 0; i < len2; i++)
    {
        scanf("%d", &arr2[i]);
    }

    printf("Enter size of 3nd array:");
    scanf("%d", &len3);

    printf("Enter 3rd array elements:");
    for (i = 0; i < len3; i++)
    {
        scanf("%d", &arr3[i]);
    }

    int aub[100], naub;
    printf("n(A U B U C) = n(A + B + C) - n(A in B) - n(B in C) - n(C in A) + n(A in B in C) \n\n");
    // printf("A U B is : ");
    naub = Union(arr1, arr2, aub, len1, len2);
    // print(aub, naub);
    
    int aubuc[100], naubuc;
    printf("A U B U C is : ");
    naubuc = Union(aub, arr3, aubuc, naub, len3);
    print(aubuc, naubuc);

    int ainb[100], nainb;
    printf("A in B is : ");
    nainb = Intersection(arr1, arr2, ainb, len1, len2);
    print(ainb, nainb);

    int binc[100], nbinc;
    printf("B in C is : ");
    nbinc = Intersection(arr2, arr3, binc, len2, len3);
    print(binc, nbinc);

    int cina[100], ncina;
    printf("C in A is : ");
    ncina = Intersection(arr3, arr1, cina, len3, len1);
    print(cina, ncina);

    int ainbinc[100], nainbinc;
    printf("A in B in C is : ");
    nainbinc = Intersection(ainb, arr3, ainbinc, nainb, len3);
    print(ainbinc, nainbinc);

    printf("LHS : \n");
    printf("n(A U B U C) = %d\n", naubuc);
    printf("RHS : \n");
    printf("n(A + B + C) - n(A in B) - n(B in C) - n(C in A) + n(A in B in C) = %d - %d - %d - %d + %d = %d\n",
    (len1 + len2 + len3), nainb, nbinc, ncina, nainbinc, (len1 + len2 + len3) - nainb - nbinc - ncina + nainbinc);
    printf("LHS = RHS");

    return 0;
}