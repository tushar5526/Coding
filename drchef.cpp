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
        vector<lli> a;
        lli n, x;
        cin>>n>>x;
        REP(i, n)
        {
            lli tmp;
            cin>>tmp;
            a.push_back(tmp);
        }
        sort(a.begin(), a.end());

        lli days = 0, tmp = n;
        REP(i, n)
        {
            if(a[i] >= x)
            {
                tmp = i;
                break;
            }
            else
            {
                ++days;
            }
            

           //cout<<"\ndays "<<days<<" "<<a[i];

        }
        //cout<<"days "<<days;
        //cout<<"\nvalue of tmp "<<tmp<<endl;
            
        while(tmp < n)
        {
            if(x  >= a[tmp])
            {
                x = a[tmp];
                ++tmp;
            }
            ++days;
            //cout<<" x "<<x<<endl;
            x *= 2;
        }
        cout<<days<<endl;
    }
    return 0;
}