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
    int al = -1, da = -1;
    sort(s.begin(), s.end());
    if (s[0] != '-' || (s[0] == '-' && s[s.size() - 1] == '-'))
    {
        cout << "NO\n";
        return 0;
    }
    for (char i : s)
    {
        if (i == '-')
            da++;
        else
            break;
    }
    cout << "YES\n"
         << s.substr(da + 1) << endl;
    return 0;
}