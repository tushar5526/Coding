//https://codeforces.com/contest/1367/problem/B

#include<iostream>

using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,_or = 0,er = 0,ow = 0,ew = 0,flag = 0;
        cin>>n;
        int tmp;
        for(int i = 0; i < n; i++)
        {
            cin>>tmp;
            if(flag == 0)
            {
                if(tmp % 2 == 0)
                {
                    ++er;
                }
                else
                {
                    ++ow;
                }
                flag = 1;
            }
            else
            {
                if(tmp % 2 == 1)
                {
                    ++_or;
                }
                else
                {
                    ++ew;
                }

                flag = 0;
            }             
        }

        flag = n % 2;
        if (flag == 0)
        {    
            if(er + ew == _or + ow)
            {
                if(er == _or && er == n/2)
                    cout<<0<<"\n";
                else
                {
                    if(ew == ow)
                        cout<<ew<<endl;
                    else
                    {
                        cout<<-1<<endl;
                    }
                                           
                }
                
            }   
            else cout<<-1<<endl;                                     
        }
        else
        {
            if (er + ew == _or + ow  + 1 )
            {
                if(er + 1 == _or && _or == n/2)
                    cout<<0<<"\n";
                else
                {
                    if(ew == ow)
                        cout<<ew<<endl;
                    else
                    {
                        cout<<-1<<endl;
                    }
                }
                
            }
            else
            {
                cout<<-1<<endl;
            }
            
        }
        
    }
    return 0;
}