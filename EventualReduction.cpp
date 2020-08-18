//https://www.codechef.com/problems/EVENTUAL

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
        cin>>n;
        string s;
        cin>>s;
        map<char,int> m;
        for(int i=0; i<n; ++i)
        {
            ++m[s[i]];
        }
        for(auto p: m)
        {
            if(p.second % 2 != 0)
            {
                cout<<"NO\n";
                n = 0;
                break;
            }
        }
        if(n != 0)
            cout<<"YES\n";
    }
    return 0;
}
