//https://www.codechef.com/JULY20B/problems/ADAKING

#include<iostream>

using namespace std;

int main()
{
    int t;
    cin>>t;
    cout<<"\n";
    while(--t)
    {
        int k;
        cin>>k;
        cout<<"k inp "<<k;
        int tmp = k-1;

        cout<<"O";
        for(int i=2; i<=64; i++)
        {            
            if(tmp != 0)
            {
                cout<<".";
                --tmp;
            }
            else
            {
                cout<<"X";
            }
            
            if(i%8==0)
                cout<<"\n";
            
        }
    }

    return 0;
}