//
#include<bits/stdc++.h>

#define mod 1000000007
#define lli long long int
#define endl '\n'
using namespace std;
#define rep(i,n) for (int i = 0; i < n; ++i)
bool isInt(float k){ return floor(k) == k;}
 
lli a[1000] = {0};

lli fib(int n){
    if(n == 0 || n == 1)
        return n;
    if(a[n] != 0)
        return a[n];

    lli sl = fib(n-2);
    lli l = fib(n-1);
    a[n] = l + sl;
    return l + sl;
}

int main()
{
    int n;cin>>n;
    cout<<fib(n); 
    return 0;
}