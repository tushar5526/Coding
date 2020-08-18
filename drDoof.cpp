//https://www.codechef.com/problems/CLLCM

#include<bits/stdc++.h>

#define mod 1000000007
#define lli long long int
#define endl '\n'
using namespace std;
#define REP(i,n) for (int i = 0; i < n; i++)

 
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
        int tmp;
        int flag = 0;
        cin>>n;
        for(int i=0; i<n; ++i)
        {
            cin>>tmp;
            if(tmp %2 == 0)
                flag = 1;
        }	
        if(flag == 1)
            cout<<"NO\n";
        else
            cout<<"YES\n";
    }
    return 0;
}