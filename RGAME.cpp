//https://www.codechef.com/problems/RGAME

#include<bits/stdc++.h>

#define mod 1000000007
#define lli long long int
#define endl '\n'
using namespace std;
#define REP(i,n) for (int i = 0; i < n; i++)

lli rupas(int f, int l, int ci, lli sum, vector<lli> a,int n)
{

    //printf("a[f] %lld f %d, a[l] %lld l %d, a[ci] %lld ci %d, sum %lld, n %d \n", a[f], f, a[l], l, a[ci], ci, sum, n);
    sum += a[f] * a[ci];
    sum += a[l] * a[ci];

    if(ci + 1 >= n)
    {
        return sum;
    }

    lli s1 = rupas(f,ci, ci+1, sum, a, n);
    s1 += rupas(ci, f, ci+1, sum, a, n);

    return s1;
}


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
        cin>>n;
        ++n;
        vector<lli> a;
        REP(i,n)
        {
            lli tmp;
            cin>>tmp;
            a.push_back(tmp);
        }


        lli sum = 0;
        
        sum = rupas(0, 0, 1, sum, a, n);
        cout<<sum<<endl;
    }
    return 0;
}