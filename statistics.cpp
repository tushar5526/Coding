//https://leetcode.com/problems/statistics-from-a-large-sample/
#include<bits/stdc++.h>

#define mod 1000000007
#define lli long long int
#define endl '\n'
using namespace std;
#define REP(i,n) for (int i = 0; i < n; i++)

 
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

        vector<int>a;
        float max = -1.0,min = 300.0,sum = 0, mode = 0;
        int mCount = 0;
        REP(i,256)
        {
            int tmp;
            cin>>tmp;

            if(tmp != 0)
            {
                if(i > max)
                    max = i;
                if(i < min)
                    min = i;
            
                if(tmp > mCount)
                {
                    mCount = tmp;
                    mode = i;
                }
            }

            REP(j,tmp){
                a.push_back(i);
                sum += i;
            }
        }

        float size = a.size();
        sum /= size;

        float median = 0;
        if((int)size % 2 == 0)
        {
            median = a[(int)size/2] + a[(int)size/2 - 1];

            median /= 2.0;
        }
        else
        {
            median = a[(int)size/2]/2.0;
        }
        
        printf("%0.5f %0.5f %0.5f %0.5f %0.5f \n",min,max,sum,median,mode);
    return 0;
}