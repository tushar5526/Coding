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
        vector<int> p;
        int n,k;
        cin>>n>>k;
        REP(i,n){
            int tmp;
            cin>>tmp;
            p.push_back(tmp);
        }
        lli m = 1e11, min = 1e11;
        REP(i, n){
            if(p[i] > k) continue;
            int tmp = k - p[i];
            if((tmp) % p[i] == 0 && tmp/p[i] < m){
                m = tmp/p[i];
                min = p[i];
            }
        }

        if(min == 1e11) cout<<"-1\n";
        else cout<<min<<endl;
    }
    return 0;
}