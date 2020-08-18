//
#include <bits/stdc++.h>

#define mod 1000000007
#define lli long long int
#define endl '\n'
using namespace std;
#define REP(i, n) for (int i = 0; i < n; ++i)

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        if (n == 1)
        {
            lli a;
            cin >> a;
            cout << "first\n";
            continue;
        }
        else if (n == 2)
        {
            lli a, b;
            cin >> a >> b;
            if (a > b)
            {
                cout << "first\n";
                continue;
            }
            else if (a < b)
            {
                cout << "second\n";
                continue;
            }
            else
            {
                cout << "draw\n";
                continue;
            }
        }
        
        lli f= 0,s=0;
        lli tmp;
        vector<lli> a;
        while(n--){
            cin>>tmp;
            a.push_back(tmp);
        }
        sort(a.begin(),a.end());
        f += a[a.size() - 1];
        s += a[a.size() - 2];
        s += a[a.size() - 3];
        
        int flag = 0;
        for(int i = a.size() - 4; i>=0; --i){
            if(flag == 0){
                f += a[i];
                flag = 1;
            }else{
                s += a[i];
                flag = 0;
            }
        }

        if (f > s)
        {
            cout << "first\n";
        }
        else if (f < s)
        {
            cout << "second\n";
        }
        else
        {
            cout << "draw\n";
        }
    }
    return 0;
}