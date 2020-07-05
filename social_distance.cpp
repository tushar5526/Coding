//https://codeforces.com/contest/1367/problem/C

#include<iostream>

using namespace std;

int main()
{
    int t,n,k;
    string s;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        cin>>s;
        int li = 0,count = 0;
        //cout<<s<<" "<<k<<endl;
        for(int i = 0; i < n; i++)
        {
            int flag1 = 0,flag2 = 0;
            if(s[i] == '0')
            {
                for(int j = i;j >= i - k; j--)
                {
                    if(s[j] == '1')
                    {
                        flag1 = 1;
                        break;
                    }
                }
                for(int j = i+1; j <= i+k; j++)
                {
                    if(s[j] == '1')
                    {
                        flag2 = 1;
                        break;
                    }
                }
                //cout<<"flag1 "<<flag1<<"flag2 "<<flag2<<"s[i] "<<s[i];
                if(flag1 != 1 && flag2 != 1)
                {
                    ++count;
                    s[i] = '1';
                }
            }
        }
        //cout<<"answer "<<count<<" "<<s<<endl;
        cout<<count<<endl;
    }
    return 0;
}