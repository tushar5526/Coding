#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void maxf(vector<int> a, int size){
int maxtillhere = -1e9, max = 0;

    for (int i = 0; i < size; i++)
    {
        max  += a[i];
        if (maxtillhere < max)
            maxtillhere = max;

        if (max < 0)
            max = 0;
    }
    cout<<maxtillhere<<endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> a;
    for (int i = 0; i < n; ++i)
    {
        int tmp;
        cin >> tmp;
        a.push_back(tmp);
    }
    int c = 0;
    int b = n;
    int max = -1e9;
    while (b)
    {
        for (int i = 0; i <= n - b; ++i)
        {
            int s = 0;
            int tmp = b;
            while (tmp)
            {
                s += a[i + tmp - 1];
                // cout<<a[i + tmp -1]<<" ";
                --tmp;
            }
            // cout<<endl;
            if (s > max)
                max = s;
        }
        --b;
    }
    maxf(a,a.size());
    return 0;
}
