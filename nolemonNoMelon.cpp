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

bool isPalindrome(string s)
{
    int st = 0, e = s.size() - 1;
    while(st < e){
        if(s[st] == s[e]){
            st++;
            e--;
        }
        else return false;
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;
    if(!isPalindrome(s)){
        cout<<s.size();
        return 0;
    }
    if (s.size() == 1)
        cout << 0;
    else if (s.size() == 2)
        cout << 0;
    else
    {
        for (int i = 1; i < s.size(); ++i)
        {
            if (s[i] != s[i - 1])
            {
                cout << s.size() - 1;
                return 0;
            }
        }
        cout << 0;
    }
    return 0;
}