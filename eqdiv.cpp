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
long long int power(lli n, lli k){
    lli p = 1;
    rep(i,k)
        p = (p * n) % mod;
    return p;
}
int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    int k;
    cin >> k;
    int t;
    cin >> t;
    while (t--)
    {
        long long int a[1000000];
        int n;
        cin >> n;
        if (n == 1)
        {
            cout << "1 \n1\n";
            continue;
        }
        else if (n == 2)
        {
            cout << abs(1 - pow(2, k)) << "\n01\n";
            continue;
        }
        for(int i=0; i<n; ++i)
            a[i] = power(i + 1, k);
        int z = n - 1; //1
        int y = n - 2; //0
        int c = n - 3;
        string s = "10";
        int min = 1e9;
        long long int sz = a[n - 1];
        long long int sy = a[n - 2];
        // cout<<sz<<" "<<sy<<endl;
        // printf("sz %lld sy %lld c %d ", sz, sy, c);
        // cout << "s " << s << endl;
        while (c >= 0)
        {
            if (abs(sz + a[c] - sy) < abs(sy + a[c] - sz))
            {
                min = abs(sz + a[c] - sy);
                sz += a[c];
                s += '1';
            }
            else
            {
                min = abs(sy + a[c] - sz);
                sy += a[c];
                s += '0';
            }
            // printf("sz %lld sy %lld c %d ", sz, sy, c);
            // cout << "s " << s << endl;
            c--;
        }
        // cout<<sz<<" "<<sy<<endl;
        reverse(s.begin(), s.end());
        cout << min << endl
             << s << endl;

    }
    return 0;
}