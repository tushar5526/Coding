//
#include<bits/stdc++.h>

#define mod 1000000007
#define lli long long int
#define endl '\n'
using namespace std;
#define rep(i,n) for (int i = 0; i < n; ++i)
bool isInt(float k){ return floor(k) == k;}

int count = 0;
int path(int x, int n, int cn){
    if(x == 0){
        return 1;
    }
    if(x < 0){
        return 0;
    }
    int count = 0;
    for(int i=cn; x - pow(i,n) >= 0; ++i){
        count += path(x - pow(i,n), n, i+1);
    }
    return count;
}

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int x;cin>>x;
    int n;cin>>n;
    cout<<path(x, n, 1);
    return 0;
}