//

#include<bits/stdc++.h>

#define REP(i,n) for (int i = 0; i < n; i++)
#define mod 1000000007
#define lli long long int
#define endl '\n'
using namespace std;



int main()
{
	int t;
	cin>>t;
	while(t--)
	{
        int n,f = 0;
        lli m = 1e9;
        cin>>n;
        map<int, int> mapa, mapb;
        REP(i, n)
        {
            lli tmp;
            cin>>tmp;
            ++mapa[tmp];
            if(tmp < m)
                m = tmp;
        }
        
        REP(i, n)
        {
            lli tmp;
            cin>>tmp;
            ++mapb[tmp];
            if(tmp < m)
                m = tmp;
        }

        for(auto p : mapa)
        {
            lli ele = p.first;
            int count = p.second;

            if(mapb.find(ele) != mapb.end())
            {    
                int d = min(count, mapb[ele]);
                count += mapb[ele];
                mapa[ele] -= d;                
                mapb[ele] -= d;                
            }

            if(count % 2 != 0)
            {
                cout<<-1<<endl;
                f = 1;
                break;
            }
        }
        if(f == 1)
            continue;

        vector<lli> a, b;
        for(auto p : mapa)
        {
            lli ele = p.first;
            int count = p.second;
            REP(i, count/2)
            {
                a.push_back(ele);
            }
        }
        for(auto p : mapb)
        {
            lli ele = p.first;
            int count = p.second;
            REP(i, count/2)
            {
                b.push_back(ele);
            }
        }

        reverse(b.begin(), b.end());

        lli res = 0;

        REP(i, a.size())
        {   
            res += min(2*m, min(a[i], b[i]));
        }
        cout<<res<<endl;
    }
    return 0;
}