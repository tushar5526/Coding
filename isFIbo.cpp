//
#include<bits/stdc++.h>

#define mod 1000000007
#define lli long long int
#define endl '\n'
using namespace std;
#define rep(i,n) for (int i = 0; i < n; ++i)
bool isInt(float k){ return floor(k) == k;}

string isFibo(lli n, lli last, lli secondLast){
    if(n == 0) return "IsFibo\n";
    if(n == last + secondLast) return "IsFibo\n";
    if(last + secondLast > n) return "IsNotFibo\n";

    return isFibo(n, last + secondLast, last);
}

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin>>t;
    while(t--){
        
        lli n;cin>>n;
        cout<<isFibo(n, 0, 1);
    }
    return 0;
}