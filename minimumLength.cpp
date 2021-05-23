//
#include <bits/stdc++.h>

#define mod 1000000007
#define lli long long int
#define endl '\n'
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
bool isInt(float k)
{
    return floor(k) == k;
}

int main()
{
    int n;
    cin >> n;
    int *a = new int[n];
    rep(i, n) cin >> a[i];
    if (n == 1)
    {
        cout << 0 << endl;
        return 0;
    }
    if (n == 2)
    {
        if (a[0] > a[1])
            cout << 1 << endl;
        else
            cout << 0 << endl;
        return 0;
    }

    int f = -1;
    int l = -1;

    for (int i = n - 1; i > 0; i--)
    {
        if (a[i] < a[i - 1])
        {
            l = i;
            break;
        }
    }
    for (int i = 0; i < n - 1; ++i)
    {
        if (a[i] > a[i + 1])
        {
            f = i;
            break;
        }
    }

    while (a[f] > a[l])
    {
        if (f > 0)
        {
            f--;
        }
        else if (l < n)
        {
            l++;
        }
    }
    if (f == -1 || l == -1)
        cout << 0;
    else
        cout << l - f - 1;
    return 0;
}