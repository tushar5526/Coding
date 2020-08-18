//
#include<bits/stdc++.h>

#define mod 1000000007
#define lli long long int
#define endl '\n'
using namespace std;
#define REP(i,n) for (int i = 0; i < n; i++)

 
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t;
	cin>>t;
	while(t--)
	{
		int n,m,x,y;
        cin>>n>>m>>x>>y;
        lli sum = 0;
        int g,s;
        if(n == 1 && m == 1)
        {
            cout<<x<<endl;
            continue;
        }

        if(y < x)
        {
            s = 0;
            g = y;
        }
        else if(2*x < y)
        {
            s = g = x;
        }
        else
        {
            g = max(y-x,x);
            s = y - g;
        }
        
        if(m*n % 2 == 0)
        {
            sum += g*(m*n/2) + s*(m*n/2);
        }
        else
        {
            sum += g*(m*n/2 + 1);
            sum += s*(m*n/2);
        }  

        cout<<sum<<endl;        
    }
    return 0;
}