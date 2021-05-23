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

void print(vector<vector<int>> a)
{
    for (auto b : a)
    {
        for (int i : b)
        {
            cout << i << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void path(vector<vector<int>> &a, int n, int r, int c, int count)
{
    if (r < 0 || c < 0 || r >= n || c >= n || (a[r][c] != -1))
        return;

    if (count == n * n - 1)
    {
        a[r][c] = count + 1;
        print(a);
        a[r][c] = -1;
        return;
    }

    a[r][c] = count + 1;
    // print(a);
    // cout << "count " << count << endl;

    path(a, n, r - 2, c + 1, count + 1);
    path(a, n, r - 1, c + 2, count + 1);
    path(a, n, r + 1, c + 2, count + 1);
    path(a, n, r + 2, c + 1, count + 1);
    path(a, n, r + 2, c - 1, count + 1);
    path(a, n, r + 1, c - 2, count + 1);
    path(a, n, r - 1, c - 2, count + 1);
    path(a, n, r - 2, c - 1, count + 1);
    a[r][c] = -1;
}

int main()
{
    int n;
    cin >> n;
    int r, c;
    cin >> r >> c;
    vector<vector<int>> a(n, vector<int>(n, -1));
    path(a, n, r, c, 0);
    return 0;
}