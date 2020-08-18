//https://www.codechef.com/LTIME86B/problems/CHEFSTEP
#include<bits/stdc++.h>

#define mod 1000000007
#define lli long long int
#define endl '\n'
using namespace std;
#define REP(i,n) for (int i = 0; i < n; i++)

 
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
        int n;
        lli k;
        scanf("%d %lld",&n,&k);
        string s;
        REP(i,n)
        {
            lli tmp;
            scanf("%lld",&tmp);
            if(tmp % k == 0)
                s.push_back('1');
            else
                s.push_back('0');            
        }
        cout<<s<<endl;
    }
    return 0;
}