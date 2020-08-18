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
		int pc,pr;
        cin>>pc>>pr;
        int a = pc/9;
        int b = pr/9;
        if(pc % 9 != 0) ++a;
        if(pr % 9 != 0) ++b;

        if(b <= a)
            cout<<"1 "<<b<<endl;
        else
            cout<<"0 "<<a<<endl;        
    }
    return 0;
}