//https://www.codechef.com/JULY20B/problems/CHEFSTR1

#include<iostream>

using namespace std;

int main()
{
    long long int t;
    cin>>t;
    while (t--)
    {
        long long int n,tmp;
        long long int sum = 0;
        long long int last;
        cin>>n>>last;
        for(long long int i = 1;i<n; i++)
        {
            cin>>tmp;
            sum += abs(tmp - last) - 1;
            last = tmp;
        }
        cout<<sum<<endl;
    }
    
    return 0;
}