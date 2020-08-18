//
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
        lli n,x;
        cin>>n>>x;
        vector<lli> a;
        REP(i,n)
        {
            lli tmp;
            cin>>tmp;
            a.push_back(tmp);
        }
        sort(a.begin(), a.end());

        lli days = 0, tmp = 0;
        REP(i, n)
        {
            if(a[i] >= x/2 + 1 && a[i] < x)
            {
                tmp = i;
                x = a[i];
                break;
            }
            else if(a[i] < x/2 + 1)
            {
                ++days;
                ++tmp;
            }
        }

        while(tmp < n)
        {
            if(x >= a[tmp])
            {
                x = a[tmp];
                ++tmp;
            }
            ++days;
            x *= 2;
        }
        cout<<days<<endl;
        
    }
    return 0;
}