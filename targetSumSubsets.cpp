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

void path(int a[], int t, int s, string ans, int i, int n)
{
    if (i == n)
    {
        if (s == t)
        {
            cout << ans + "." << endl;
        }
        return;
    }

    path(a, t, s + a[i], ans + to_string(a[i]) + ", ", i + 1, n);
    path(a, t, s, ans, i + 1, n);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    int *a = new int[n];
    rep(i, n) cin >> a[i];
    int t;
    cin >> t;
    path(a, t, 0, "", 0, n);

    return 0;
}