//https://www.codechef.com/OCT20B?order=desc&sortBy=successful_submissions

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
    int t;
    cin >> t;
    while (t--)
    {
        int n, q;
        cin >> n >> q;
        lli s = 0;
        int ans = 0;
        int flag = 0;
        rep(i, n)
        {
            int tmp;
            cin >> tmp;
            s += (tmp - q);
            ++ans;
            // cout<<s<<" "<<ans<<" ";
            if (s < 0 && flag == 0)
            {
                cout << ans << endl;
                flag = 1;
            }
        }
        if (flag == 1)
            continue;
        if (s < 0)
            cout << ans << endl;
        else
        {
            cout << s / q + 1 + ans << endl;
        }
    }
    return 0;
}