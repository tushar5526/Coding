//
#include<bits/stdc++.h>

#define mod 1000000007
#define lli long long int
#define endl '\n'
using namespace std;
#define rep(i,n) for (int i = 0; i < n; ++i)
bool isInt(float k){ return floor(k) == k;}
 
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t;
	cin>>t;
	while(t--)
	{
		int n,k,l;cin>>n>>k>>l;
        if(k * l < n || (k == 1 && n > 1)){
            cout<<-1<<endl;
            continue;
        }	
        int b = 0;
        for(int i=1; i<=n; ++i){
            b = b % k;
            cout<<b + 1<<" ";
            ++b;
        }
        cout<<endl;
    }
    return 0;
}