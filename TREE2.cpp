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
        int n;cin>>n;
        map<int, int> m;
        rep(i,n){
            int tmp;cin>>tmp;
            ++m[tmp];
        }
        int b=0;
        for(auto i : m){
            if(i.first == 0)
                continue;
            ++b;
        }
        cout<<b<<endl;                
    }
    return 0;
}