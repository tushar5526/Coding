//
#include <bits/stdc++.h>

#define mod 1000000007
#define lli long long int
#define endl '\n'
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
bool isInt(float k)
{
    return floor(k) == k;
}
vector<int> pr;
void SieveOfEratosthenes(int n) 
{ 
    bool prime[n+1]; 
    memset(prime, true, sizeof(prime)); 
  
    for (int p=2; p*p<=n; p++) 
    { 
        if (prime[p] == true) 
        { 
            for (int i=p*p; i<=n; i += p) 
                prime[i] = false; 
        } 
    } 
  
    for (int p=2; p<=n; p++) 
       if (prime[p]) pr.push_back(p); 
} 

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    SieveOfEratosthenes(4000000);
    while (t--)
    {
        int n, id = 0;
        cin >> n;
        vector<int> a(n);
        vector<int> b(n);
        rep(i, n) cin >> a[i];
        for(int i = n - 1; i >= 0; --i)
        {
            if (a[i] == i + 1)
            {
                b[i] = pr[id++];
            }
            else
            {
                b[i] = b[a[i] - 1];
            }
        }
        for(int i : b) cout<<i<<" ";
        cout<<endl;
    }
    return 0;
}
