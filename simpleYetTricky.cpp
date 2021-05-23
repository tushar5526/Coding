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
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int *b = new int[n];
        int *a = new int[n];
        rep(i, n) cin >> a[i];
        int p1 = n-1;
        for(int i=p1; i>=0; i--){
            b[i] = 0;
            for(int j=i; j>=0; --j){
                if(a[j] <= a[i]) ++b[i]; 
                else break;
            }
        }
        rep(i,n) cout<<b[i]<<" ";
        cout<<endl;
    }
    return 0;
}