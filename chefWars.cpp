//
#include <bits/stdc++.h>

#define mod 1000000007
#define lli long long int
#define endl '\n'
using namespace std;
#define REP(i, n) for (int i = 0; i < n; i++)

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int h, p;
        cin >> h >> p;
        while (h > 0 && p > 0)
        {
            h -= p;
            p /= 2;
        }

        if (h <= 0)
            cout << 1 << endl;
        else
            cout << 0 << endl;
    }
    return 0;
}