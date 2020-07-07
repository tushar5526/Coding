//https://www.codechef.com/JULY20B/problems/PTMSSNG

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
bool sortcol( const vector<long long int>& v1, 
               const vector<long long int>& v2 ) { 
 return v1[0] < v2[0]; 
} 
bool sortcol_( const vector<long long int>& v1, 
               const vector<long long int>& v2 ) { 
 return v1[1] < v2[1]; 
}

void print_vec(vector<vector<long long int>> xy,int n)
{
    cout<<"\n=========================";
    for(int i = 0; i<n; i++)
    {
        cout<<"\n"<<xy[i][0]<<" "<<xy[i][1];
    }
    cout<<"\n";
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long int n;
        cin>>n;
        
        vector<vector<long long int>> xy;

        for(long long int i=0; i<4*n-1; ++i)
        {            
            long long int x,y;
            cin>>x>>y;
            vector<long long int> v;
            v.push_back(x);
            v.push_back(y);
            xy.push_back(v);
        }
        sort(xy.begin(), xy.end(),sortcol); 
        
        long long int count = 0;
        long long int last = xy[0][0];
        int flag = 0;
        //print_vec(xy,4*n-1);

        for(long long int i=0; i<4*n -1; ++i)
        {
            if(last == xy[i][0])
            {
                count += 1;
            }
            else
            {
                if(count % 2 != 0)
                {
                    cout<<last<<" ";
                    flag = 1;
                    break;
                }
                else
                {
                    count = 1;
                    last = xy[i][0];
                }
            }
            //printf("value of count %lld value of xy[i] %lld value of value of last %lld \n",
            //count,xy[i][0],last);            
        }

        if(flag != 1 && count%2 != 0)
            cout<<last<<" ";

        sort(xy.begin(), xy.end(),sortcol_);
        //print_vec(xy,4*n-1);
        
        count = 0;
        last = xy[0][1];
        flag = 0;

        for(long long int i=0; i<4*n -1; ++i)
        {
            if(last == xy[i][1])
            {
                count += 1;
            }
            else
            {
                if(count % 2 != 0)
                {
                    cout<<last<<" ";
                    flag = 1;
                    break;
                }
                else
                {
                    count = 1;
                    last = xy[i][1];
                }                
            }            
        }

        if(flag != 1 && count%2 != 0)
            cout<<last<<" "; 
        cout<<"\n";
    }

    return 0;
}