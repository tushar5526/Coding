//https://www.codechef.com/AUG20B/problems/CHEFWED
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
        int n, k;
        cin >> n >> k;
        map<int,int> a;
        int cost = 1;
        REP(i,n){
            int tmp;
            cin>>tmp;
            if(a.find(tmp) != a.end()){
                ++cost;
                a.clear();
                ++a[tmp];
            }
            else{
                ++a[tmp];
            }
        }
        cout<<cost<<endl;
    }
    return 0;
}