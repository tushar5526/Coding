#include<iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int total = 0;
    while(n--)
    {
        int tmp;
        int sum = 0;
        cin>>tmp;
        sum += tmp;        
        cin>>tmp;
        sum += tmp;
        if(sum > 1)
        {
            total += 1;
            cin>>tmp;
            continue;            
        } 
        cin>>tmp;
        sum += tmp;
        if(sum > 1)
        {
            total += 1;
        }
    }
    cout<<total;
    return 0;
}