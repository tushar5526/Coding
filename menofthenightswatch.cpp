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
    int n, m;
    cin >> n >> m;
    vector<string> a;
    rep(i, n)
    {
        string s;
        cin >> s;
        a.push_back(s);
    }
    vector<bool> p(n, false);
    vector<int> mx(m, -1);
    rep(i, m)
    {
        for (string s : a)
        {
            if (s[i] > mx[i])
                mx[i] = s[i];
        }
    }
    rep(i, n)
    {
        for (int j = 0; j < m; ++j)
        {
            if (a[i][j] == mx[j])
            {
                p[i] = true;
                break;
            }
        }
    }
    int count = 0;
    for(bool t : p){
        if(t) ++count;
    }
    cout<<count<<endl;
    return 0;
}