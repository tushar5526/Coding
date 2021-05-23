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
    string s;
    cin >> s;
    int ids = -1;
    int idg = -1;
    int last = stoi(s.substr(s.size() - 1, 1));
    rep(i, s.size())
    {
        int c = stoi(s.substr(i, 1));
        if (c % 2 == 0)
        {
            ids = i;
            if (last - c > 0)
            {
                idg = i;
                break;
            }
        }
    }

    if (ids == -1 && idg == -1)
    {
        cout << -1;
    }
    else
    {
        if (idg != -1)
        {
            char tmp = s[idg];
            s[idg] = s[s.size() - 1];
            s[s.size() - 1] = tmp;
            cout << s << endl;
        }
        else
        {
            char tmp = s[ids];
            s[ids] = s[s.size() - 1];
            s[s.size() - 1] = tmp;
            cout << s << endl;
        }
    }
    return 0;
}