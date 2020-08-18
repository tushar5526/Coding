//https://www.codechef.com/problems/SPAMCLAS

#include<iostream>
#include<vector>

using namespace std;
#define lli long long int

int main()
{
	lli t;
	cin>>t;
	while(t--)
	{
		lli n, minX, maxX;
		cin>>n>>minX>>maxX;
		lli odd = 0, even = 0;		
		
		lli tmp = 0;

		vector<lli> w,b;
			
		for(lli i = 0; i<n; ++i)
		{
			lli _w, _b;
			cin>>_w>>_b;
			w.push_back(_w);
			b.push_back(_b);
		}

		int at = 0;		
		for(lli i=minX; i<= minX + 1; ++i)
		{
			lli tmp = i;
			for(int j=0; j<n; ++j)
			{
				tmp = tmp * w[j] + b[j];
			}

			if(tmp % 2 == 0)
			{	
				++even;
				if(at == 0)
					at = 1;
			}
			else
			{
				++odd;		
				if(at == 0)
					at = 2;
			}
		}
		
        if(even == 2)
        {
            even = maxX - minX + 1;
        }
        else if(odd == 2)
        {
            odd = maxX - minX + 1;
        }
        else if(even == 1 && odd == 1)
        {
            lli total =  maxX - minX + 1;
            
            if(total % 2 == 0)
            {
                even = odd = total/2;
            }
            else
            {
				if(at == 2)
				{
					even = total/2, odd = total/2 + 1;
				}
				else
				{
					even = total/2 + 1,odd = total/2;
				}
				
            }
            
        }
		cout<<even<<" "<<odd<<endl;
	}
	return 0;
}
