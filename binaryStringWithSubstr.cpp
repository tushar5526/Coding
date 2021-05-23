//https://leetcode.com/problems/binary-string-with-substrings-representing-1-to-n/
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

string makeBin(int n){
    string b;
    while(n){
        b.push_back(n%2 == 1? '1' : '0');
        n /= 2;
    }
    reverse(b.begin(),b.end());
    return b;
}

bool queryString(string s, int n)
{
    for(int i=1; i<=n; ++i){
        string b = makeBin(i);
        cout<<b<<" "<<i<<endl;
        bool flag = true;
        for(int j=0; j<=s.length() - b.length(); ++j){
            if(b[0] == s[j])
                if(b == s.substr(j,b.length())){
                    // cout<<b<<endl;
                    flag = false;
                    break;
                }
        }
        if(flag)
            return false;
    }
    return true;
}
int main()
{
    string s;int n;
    cin>>s>>n;
    cout<<queryString(s,n);
    return 0;
}