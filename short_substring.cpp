//https://codeforces.com/contest/1367/problem/A

#include<iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    string s;
    while(n--)
    {
        cin>>s;
        int len = s.length();
        for(int i = 0; i<len; i+=2)
        {
            cout<<s[i];
        }
        cout<<s[len-1]<<"\n";

    }
    return 0;
}