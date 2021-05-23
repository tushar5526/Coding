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
        vector<ll> se(n + 1, 0);
        vector<ll> so(n + 1, 0);
        ll n1 = 0;
        se[0] = 0;
        int flag = 1;
        rep(i, n)
        {
            cin >> a[i];
            if (a[i] == 1)
            {

                if (flag)
                {
                    se[i + 1] = (se[i] + 1) % mod;
                    so[i + 1] = so[i];
                }
                else
                {
                    se[i + 1] = se[i];
                    so[i + 1] = (so[i] + 1) % mod;
                }
                if (i != n - 1)
                {
                    ++n1;
                    flag = flag == 1 ? 0 : 1;
                }
            }
            else
            {
                if (flag)
                {
                    int add = a[i] % 2 == 0 ? a[i] : a[i] - 1;
                    se[i + 1] = (se[i] + add) % mod;
                    so[i + 1] = so[i];
                }
                else
                {
                    se[i + 1] = se[i];
                    int add = a[i] % 2 == 0 ? a[i] : a[i] - 1;
                    so[i + 1] = (so[i] + add) % mod;
                }
            }
        }
        // rep(i, n + 1) cout << se[i] << " ";
        // cout << endl;
        // rep(i, n + 1) cout << so[i] << " ";
        // cout << endl;
        int q;
        cin >> q;
        while (q--)
        {
            ll r;
            cin >> r;
            ll tSum = 0;
            if (r % n == 0)
            {
                if (n1 % 2 == 1)
                {
                    ll ea = a[n - 1] % 2 == 0 ? a[n - 1] - 1 : a[n - 1];
                    tSum += (((se[n]) % mod) * ((r / n) / 2)) % mod;
                    tSum += ((so[n - 1] + ea) % mod) * ((r / n) / 2) % mod;
                    if ((r / n) % 2 == 1)
                    {
                        tSum = (tSum + se[n]) % mod;
                    }
                    else
                    {
                        int add = a[n - 1] % 2 == 0 ? 1 : 0;
                        tSum += add % mod;
                    }
                }
                else
                {
                    int add = a[n - 1] % 2 == 0 ? a[n - 1] - 1 : a[n - 1];
                    tSum += (((se[n - 1] + add) % mod) * (r / n)) % mod;
                    add = a[n - 1] % 2 == 0 ? 1 : 0;
                    tSum += add % mod;
                }
            }
            else if (r < n)
            {
                tSum += se[r - 1];
                if (se[r - 1] != se[r])
                {
                    tSum += a[r - 1];
                }
            }
            else if (r > n)
            {
                if (n1 % 2 == 1)
                {
                    ll ea = a[n - 1] % 2 == 0 ? a[n - 1] - 1 : a[n - 1];
                    tSum += (((se[n]) % mod) * ((r / n) / 2)) % mod;
                    tSum += ((so[n - 1] + ea) % mod) * ((r / n) / 2) % mod;
                    if ((r / n) % 2 == 1)
                    {
                        tSum = (tSum + se[n]) % mod;
                    }
                    else
                    {
                        int add = a[n - 1] % 2 == 0 ? 1 : 0;
                        tSum += add % mod;
                    }
                }
                else
                {
                    int add = a[n - 1] % 2 == 0 ? a[n - 1] - 1 : a[n - 1];
                    tSum += (((se[n - 1] + add) % mod) * (r / n)) % mod;
                    add = a[n - 1] % 2 == 0 ? 1 : 0;
                    tSum += add % mod;
                }
                // cout<<"ts half "<<tSum<<endl;
                int id = r % n;
                if (n1 % 2 == 0)
                {
                    tSum += se[id];
                }
                else
                {
                    if ((r / n) % 2 == 0)
                    {
                        tSum += se[id];
                    }
                    else
                    {
                        tSum += so[id];
                    }
                }
            }
            cout << tSum << endl;
        }
    }
    return 0;
}