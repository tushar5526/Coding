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

class coor
{
public:
    int x, y;
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int w, h, n, m, maxY = -1e9;
    cin >> w >> h >> n >> m;
    int *a = new int[n];
    int *b = new int[m];
    rep(i, n) cin >> a[i];
    rep(i, m)
    {
        cin >> b[i];
        // ycheck[b[i]]++;
        if (b[i] > maxY)
            maxY = b[i];
    }
    vector<vector<coor>> tab;
    // make a table
    rep(i, n)
    {
        vector<coor> row;
        coor tmp;
        for (int j = 0; j < m; ++j)
        {
            tmp.x = a[i];
            tmp.y = b[j];
            row.push_back(tmp);
            // cout << a[i] << " " << b[j] << " | ";
        }
        // cout << endl;
        row.push_back(tmp);
        tab.push_back(row);
    }

    //calculate squares
    int max = -1e9;
    ++m;
    for (int t = 1; t < h && t <= 2 * maxY; ++t)
    {
        map<int, int> areaCheck;

        for (int s = 0; s < n; ++s)
        {
            tab[s][m-1].y = t;
        }
        rep(i, n)
        {
            for (int j = 0; j < m; ++j)
            {
                int x1 = tab[i][j].x;
                int y1 = tab[i][j].y;
                int x2, y2;
                // cout << "printing for " << tab[i][j].x << " " << tab[i][j].y << "\n";
                int flag = 1;
                for (int x = i + 1; x < n; ++x)
                {
                    for (int y = 0; y < j; ++y)
                    {
                        flag = 0;
                        x2 = tab[x][y].x;
                        y2 = tab[x][y].y;
                        // cout << tab[x][y].x << " " << tab[x][y].y << " | ";
                        if (abs(x2 - x1) == abs(y2 - y1))
                            areaCheck[abs(y2 - y1)]++;
                    }
                    if (flag == 1)
                        break;
                    // cout << endl;
                }
                flag = 1;
                for (int x = i + 1; x < n; ++x)
                {
                    for (int y = j + 1; y < m; ++y)
                    {
                        flag = 0;
                        if (abs(x2 - x1) == abs(y2 - y1))
                            areaCheck[abs(y2 - y1)]++;
                        // cout << tab[x][y].x << " " << tab[x][y].y << " | ";
                    }
                    if (flag == 1)
                        break;
                }
                // cout << "--------" << endl;
            }
        }
        int count = 0;
        if (areaCheck.find(0) != areaCheck.end())
        {
            count = areaCheck.size() - 1;
        }
        else
        {
            count = areaCheck.size();
        }
        if (count > max)
            max = count;
    }

    // for (auto z : areaCheck)
    // {
    //     cout << z.first << " ";
    // }

    cout << max << endl;

    /*
    for (int d = 1; d < h && d <= maxY * 2; ++a)
    {
        int tCount = 0;
        map<int, int> mpd;
        rep(i, n)
        {
            for (int j = 0; j < m; ++j)
            {
                int x1 = tab[i][j].x;
                int y1 = tab[i][j].y;
                int x2, y2 = d;
                // cout << "printing for " << tab[i][j].x << " " << tab[i][j].y << "\n";
                for (int x = i + 1; x < n; ++x)
                {
                    x2 = tab[i][0].x;
                    // cout << endl;
                    if ((abs(x2 - x1) == abs(y2 - y1)) && (x2 - x1 != 0))
                    {
                        if (areaCheck[abs(x2 - x1)] == 0)
                            mpd[abs(x2 - x1)]++;
                    }
                }
                for (int x = 0; x < i; ++x)
                {
                    x2 = tab[i][0].x;
                    // cout << endl;
                    if ((abs(x2 - x1) == abs(y2 - y1)) && (x2 - x1 != 0))
                    {
                        if (areaCheck[abs(x2 - x1)] == 0)
                            mpd[abs(x2 - x1)]++;
                    }
                }
                // cout << "--------" << endl;
            }
        }
    }
*/

    return 0;
}