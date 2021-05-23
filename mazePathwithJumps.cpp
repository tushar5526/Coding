
#include <bits/stdc++.h>

using namespace std;

void path(int cn, int cm, int n, int m, string s)
{
    if (n == 0 || m == 0 || cn > n - 1 || cm > m - 1)
    {
        return;
    }
    if (cn == n - 1 && cm == m - 1)
    {
        cout << s << endl;
        return;
    }
    int id = 1;
    for (int i = cm + 1; i < m; ++i)
    {
        path(cn, i, n, m, s + "h" + to_string(id));
        ++id;
    }
    id = 1;
    for (int i = cn + 1; i < n; ++i)
    {
        path(i, cm, n, m, s + "v" + to_string(id));
        ++id;
    }

    id = 1;
    for (int i = cn + 1, j = cm + 1; i < n && j < m; ++i, ++j)
    {
        path(i, j, n, m, s + "d" + to_string(id));
        ++id;
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    path(0, 0, n, m, "");
    return 0;
}