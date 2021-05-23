#include <bits/stdc++.h>
using namespace std;

void path(int a[10][10], int cn, int cm, int n, int m, string s, int b[10][10])
{
    if (cn < 0 || cm < 0 || cn > n - 1 || cm > m - 1 || a[cn][cm] == 1 || b[cn][cm] == 1)
    {
        return;
    }
    if (cn == n - 1 && cm == m - 1)
    {
        cout << s << endl;
        return;
    }

    b[cn][cm] = 1;
    path(a, cn - 1, cm, n, m, s + "t", b);
    path(a, cn, cm - 1, n, m, s + "l", b);
    path(a, cn + 1, cm, n, m, s + "d", b);
    path(a, cn, cm + 1, n, m, s + "r", b);
    b[cn][cm] = 0;
}

int main()
{
    int n, m, a[10][10];
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
            cin >> a[i][j];
    }
    int b[10][10] = {0};
    path(a, 0, 0, n, m, "", b);
    return 0;
}