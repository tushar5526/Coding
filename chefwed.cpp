//https://www.codechef.com/AUG20B/problems/CHEFWED
#include <bits/stdc++.h>

#define mod 1000000007
#define lli long long int
#define endl '\n'
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)

int f[1005] = {0}, dp[1005] = {0};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        f[1005] = {0};
        dp[1005] = {0};
        rep(i, n) cin >> f[i];
        dp[0] = k;
        for (int i = 1; i < n; ++i)
        {
            dp[i] = dp[i - 1] + k;
            map<int, int> m;
            int clash = 0;
            for (int j = i; j >= 0; --j)
            {
                ++m[f[j]];
                if(m[f[j]] == 2)
                    clash += 2;
                else if(m[f[j]] > 2)
                    clash += 1;
                dp[i] = min(dp[i], dp[j - 1] + k + clash);
            }
        }
        cout << dp[n - 1] << '\n';
    }
    return 0;
}