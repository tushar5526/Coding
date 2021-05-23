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
        if ((p < k && a[p - 1] < x) || (p > k && a[p - 1] > x))
        {
            cout << -1 << endl;
            continue;
        }
        if (a[p - 1] == x)
        {
            cout << 0 << endl;
            continue;
        }
        auto it = find(a.begin(), a.end(), x);
        if (it != a.end())
        {
            pos = it - a.begin();
            if (pos < p - 1)
            {
                while (a[pos + 1] == x){
                    ++pos;
                }
            }
            // cout<<"pos "<<pos<<endl;
            cout << abs(pos - (p - 1)) << endl;
        }
        else
        {
            a[p - 1] = x;
            sort(a.begin(), a.end());
            pos = lower_bound(a.begin(), a.end(), x) - a.begin();
            // cout<<"pos "<<pos<<endl;
            cout << abs(pos - (p - 1)) + 1 << endl;
        }
        // rep(i,n) cout<<a[i]<<" ";cout<<endl;
    }
    return 0;
}