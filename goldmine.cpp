#include <bits/stdc++.h>

using namespace std;

int maxGold(vector<vector<int>> &a, vector<vector<int>> &dp, int i, int j, int n, int m)
{
    if (i >= n || j >= m || i < 0)
    {
        return 0;
    }

    if (dp[i][j] != 0)
        return dp[i][j];

    int u, md, d;
    u = maxGold(a, dp, i - 1, j + 1, n, m);
    md = maxGold(a, dp, i, j + 1, n, m);
    d = maxGold(a, dp, i + 1, j + 1, n, m);

    int ans = max({u, md, d});
    dp[i][j] = ans + a[i][j];
    return dp[i][j];
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m, 0));
    vector<vector<int>> dp(n, vector<int>(m, 0));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> a[i][j];
        }
    }

    int ans = 0;
    for (int i = 0; i < n; ++i)
    {
        ans = max(ans, maxGold(a, dp, i, 0, n, m));
    }
    cout << ans << endl;

    return 0;
}