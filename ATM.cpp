//
#include<bits/stdc++.h>

#define mod 1000000007
#define lli long long int
#define endl '\n'
using namespace std;
#define REP(i,n) for (int i = 0; i < n; i++)

 
int main()
{

		int am;
        float balance;
        cin>>am>>balance;

        if(am % 5 == 0 && balance >= am + 0.5)
        {
            balance -= am + 0.5;
        }

        printf("%0.2f ", balance);

    return 0;
}