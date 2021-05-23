//
#include <bits/stdc++.h>

#define mod 1000000007
#define lli long long int
#define ll long long
#define endl '\n'
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
bool isInt(float k)
{
    return floor(k) == k;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        rep(i, n) cin >> a[i];
        int q;
        cin >> q;
        while (q--)
        {
            int r;
            cin >> r;
            ll sum = 0;
            int flag = 1;
            rep(i, r - 1)
            {
                if (flag == 1)
                {
                    if ((i + 1) % n == 0)
                    {
                        ll odd = a[i % n] % 2 == 0 ? a[i % n] - 1 : a[i % n];
                        sum = (sum + odd) % mod;
                    }
                    else if (a[i % n] == 1)
                    {
                        sum = (sum + 1) % mod;
                    }
                    else
                    {
                        ll eve = a[i % n] % 2 == 0 ? a[i % n] : a[i % n] - 1;
                        sum = (sum + eve) % mod;
                    }
                }
                // cout << "tsum and flag " << sum << " " << flag << endl;
                if (a[i % n] == 1)
                {
                    if (i % n != n - 1)
                    {
                        // cout << "flag changed\n";
                        flag = flag == 1 ? 0 : 1;
                    }
                }
            }
            // cout << sum << endl;

            if (flag == 1)
            {
                if (r % n == 0)
                    sum = (sum + a[n - 1]) % mod;
                else if (r > n)
                    sum = (sum + a[(r - 1) % n]) % mod;
                else if (r < n)
                    sum = (sum + a[(r - 1) % n]) % mod;
            }
            cout << sum % mod << endl;
        }
    }
    return 0;
}