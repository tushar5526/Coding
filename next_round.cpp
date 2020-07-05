//https://codeforces.com/problemset/problem/158/A

#include<iostream>

using namespace std;

int main()
{
    int a[100],n,k;
    cin>>n>>k;
    for(int i = 0; i<n;++i)
    {
        int tmp;
        cin>>tmp;
        if(tmp == 0)
        {
            cout<<i;
            exit(0);
        }
        else
        {
           a[i] = tmp; 
        }        
    }

    if(a[k-1] == 0)
    {
        cout<<k-1;
    }
    else
    {
        int count = 0;
        int cmp = a[k];
        for(int i = k; i<n;++i)
        {
            if(a[i] == cmp)
            {
                ++count;
            }
            else
            {
                break;
            }            
        }

        cout<<count + k;
    }
    
} 