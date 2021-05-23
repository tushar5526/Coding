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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        int sum = 0;
        rep(i, n)
        {
            cin >> a[i];
            sum += a[i];
        }
        int min = 1e9;
        int ans;
        for (int b = 0; b < (1 << n) - 1; b++)
        {
            int subSum = 0;
            for (int i = 0; i < n; i++)
            {
                if (b & (1 << i))
                    subSum += a[i];
            }
            // cout << subSum << " " << abs(sum - 2 * subSum) << endl;
            if (abs(2 * subSum - sum) < min)
            {
                min = abs(2 * subSum - sum);
                ans = subSum;
            }
        }

        cout << max(ans, sum - ans) << endl;
    }

    return 0;
}