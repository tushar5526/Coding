//
#include<bits/stdc++.h>

#define mod 1000000007
#define lli long long int
#define endl '\n'
using namespace std;
#define rep(i,n) for (int i = 0; i < n; ++i)
bool isInt(float k){ return floor(k) == k;}

int count = 0;
int path(int n, int cn, int count){
    if(cn == n){
        return 1;
    }
    if(cn > n) return 0;

    int p1 = path(n, cn + 1, count);
    int p2 = path(n, cn + 2, count);
    count += p1 + p2;
    return count;
}

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;cin>>n;
    cout<<path(n, 0, 0);
    return 0;
}