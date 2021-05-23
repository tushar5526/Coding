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
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        lli x, n, k, p;
        cin >> n >> x >> p >> k;
        vector<int> a;
        int pos = -1;
        rep(i, n)
        {
            int tmp;
            cin >> tmp;
            a.push_back(tmp);
        }
        sort(a.begin(), a.end());
        // if(k == p){
        //     cout<<1<<endl;
        //     continue;
        // }
        if (a[p - 1] == x)
        {
            cout << 0 << endl;
            continue;
        }
        int last = a[k - 1], count = 0, flag = 0;
        do
        {
            a[k - 1] = x;
            last = a[k - 1];
            sort(a.begin(), a.end());
            ++count;
        } while (last != a[k - 1] && a[p - 1] != x);
        if (a[p - 1] == x)
        {
            cout << count << endl;
        }
        else
        {
            cout << -1 << endl;
        }
        // rep(i, n) cout << a[i] << " ";
        // cout << endl;
    }
    return 0;
}