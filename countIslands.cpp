#include <bits/stdc++.h>

using namespace std;

void countIsland(vector<vector<int>> &g, int r, int c, int i, int j)
{
    if (i < 0 || j < 0 || i >= r || j >= c || g[i][j] != 0)
        return;
    g[i][j] = 2;
    countIsland(g, r, c, i - 1, j);
    countIsland(g, r, c, i + 1, j);
    countIsland(g, r, c, i, j - 1);
    countIsland(g, r, c, i, j + 1);
}

int main()
{
    int r, c;
    cin >> r >> c;
    vector<vector<int>> g(r, vector<int>(c));
    for (int i = 0; i < r; ++i)
        for (int j = 0; j < c; ++j)
            cin >> g[i][j];
    int count = 0;
    for (int i = 0; i < r; ++i)
        for (int j = 0; j < c; ++j)
            if (g[i][j] == 0)
            {
                ++count;
                countIsland(g, r, c, i ,j);
            }

    cout << count;
    return 0;
}