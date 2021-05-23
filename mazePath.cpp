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
    path(cn, cm + 1, n, m, s + "h");
    path(cn + 1, cm, n, m, s + "v");
}

int main()
{
    int n, m;
    cin >> n >> m;
    path(0, 0, n, m, "");
    return 0;
}