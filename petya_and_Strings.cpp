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

    string a,b;
    cin>>a>>b;
    transform(a.begin(), a.end(), a.begin(), ::tolower);
    transform(b.begin(), b.end(), b.begin(), ::tolower);

    if(a == b)
        cout<<"0\n";
    else
    {    
        REP(i,a.length())
        {
            if(a[i] < b[i])
            {
                cout<<"-1\n";
                break;
            }
            else if(b[i] < a[i])
            {
                cout<<"1\n";
                break;
            }            
        }
    }
    return 0;
}