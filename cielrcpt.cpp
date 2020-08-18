//https://www.codechef.com/problems/CIELRCPT
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
		int p;
        cin>>p;
        int count = 0;
        do
        {
            ++count;
            p = p - pow(2,int(log2(p)) > 11 ? 11 : int(log2(p)));
        }while(p != 0);

        cout<<count<<endl;
    }
    return 0;
}