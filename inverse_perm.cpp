//
#include <bits/stdc++.h>

#define mod 1000000007
#define lli long long int
#define endl '\n'
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, tn;
        cin >> n;
        tn = n;
        int a[1000];
        rep(i, n)
            cin >> a[i];        

        int li = 0, tmp = a[a[li] - 1];
        while (n--)
        {
            printf("tmp %d li %d\n",tmp,li);
            if (tmp == li + 1)
            {
                li = (li + 1) % tn;
                tmp = a[a[li] - 1];
                continue;
            }
            int t = a[a[li] - 1];
            a[a[li] - 1] = li + 1;
            li = tmp - 1 % tn;
            tmp = t;
            rep(i, tn)
                cout<< a[i] << " ";
            cout<<endl;
        }
        rep(i, tn)
            cout<< a[i] << " ";
    }
    return 0;
}