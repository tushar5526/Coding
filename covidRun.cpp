//https://www.codechef.com/OCT20B?order=desc&sortBy=successful_submissions

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
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n, k, x, y;
        cin >> n >> k >> x >> y;
        vector<bool> visited(n, false);
        while (!visited[x])
        {
            visited[x] = true;
            x = (x + k) % n;
        }
        if (visited[y])
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}