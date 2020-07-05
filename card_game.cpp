//https://www.codechef.com/JULY20B/problems/CHEFSTR1

#include<iostream>

using namespace std;

int _p(long long int a)
{   
    int p = 0;
    while(a != 0)
    {
        p += a % 10;
        a /= 10;
    }

    return p;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        long long int a,b;
        int c = 0,m = 0;
        while(n--)
        {
            cin>>a>>b;
            int ap = 0,bp = 0;

            ap = _p(a);
            bp = _p(b);

            if(ap > bp)
                c += 1;
            else if(ap < bp)
                m += 1;
            else
            {
                c += 1;
                m += 1;
            }
        }

        if(c == m)
            cout<<"2 "<<c<<endl;
        else if(c > m)
            cout<<"0 "<<c<<endl;
        else
            cout<<"1 "<<m<<endl;         
    }  
      
    return 0;
}