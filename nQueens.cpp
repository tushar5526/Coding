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

bool isFree(vector<vector<int>> a, int row, int col, int n)
{
    for (int i = 0; i < row; ++i)
    {
        if (a[i][col] == 1)
            return false;
    }

    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j)
    {
        if (a[i][j] == 1)
            return false;
    }

    for (int i = row - 1, j = col + 1; i >= 0 && j < n; --i, ++j)
    {
        if (a[i][j] == 1)
            return false;
    }

    return true;
}

void queen(vector<vector<int>> a, int n, string ans, int row)
{
    if (row == n)
    {
        cout << ans + "." << endl;
        return;
    }

    for (int i = 0; i < n; ++i)
    {
        if (isFree(a, row, i, n))
        {
            a[row][i] = 1;
            queen(a, n, ans + to_string(row) + "-" + to_string(i) + ", ", row + 1);
            a[row][i] = 0;
        }
    }
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n, 0));
    queen(a, n, "", 0);
    return 0;
}