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

void dsum(string s)
{
    if (s.size() == 1)
    {
        cout << s;
        return;
    }
    lli sum = 0;
    for (int i = 0; i < s.size(); ++i)
    {
        sum += stoi(s.substr(i, 1));
    }
    dsum(to_string(sum));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;
    int k;
    cin >> k;
    lli sum = 0;
    for (int i = 0; i < s.size(); ++i)
    {
        sum += stoi(s.substr(i, 1));
    }
    sum *= k;
    dsum(to_string(sum));
    return 0;
}