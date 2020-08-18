//
#include<bits/stdc++.h>

#define mod 1000000007
#define lli long long int
#define endl '\n'
using namespace std;
#define REP(i,n) for (int i = 0; i < n; i++)


lli gcd(lli a,lli b)
{
    if(a == 0)
        return b;
    return gcd(b%a,a);
}

lli lcm(lli a, lli b)
{
    return (a * b)/ gcd (a,b);
}

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t;
	cin>>t;
	while(t--)
	{
		lli l,r;
        cin>>l>>r;

        int flag = 0;
        lli tmp = l;
        while(l < r)
        {
            l *= 2;
            if(l <= r)
            {
                flag = 1;
                break;
            }
        }

        if(flag == 1)
            cout<<tmp<<" "<<l<<endl;
        else
            cout<<"-1 -1\n";
    }
    
        return 0;
}