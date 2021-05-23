//https://www.codechef.com/SEPT20B/problems/COVID19B
#include <bits/stdc++.h>

#define mod 1000000007
#define lli long long int
#define endl '\n'
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
bool isInt(float k)
{
	return floor(k) == k;
}

float sol(int a1, float b1, int a2, float b2)
{
	if (a1 == a2)
		return 0;

	return ((b2 - b1) / (a1 - a2)) < 0 ? 0 : (b2 - b1) / (a1 - a2);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		vector<int> a;
		float z[6][6] = {0};
		rep(i, n)
		{
			int tmp;
			cin >> tmp;
			a.push_back(tmp);
		}
		rep(i, n)
		{
			for (int j = 0; j < n; ++j)
			{
				// cout<<"a[i] i a[j] j "<<a[i]<<" "<<i<<" "<<a[j]<<" "<<j<<endl;
				z[i][j] = sol(a[i], i, a[j], j);
			}
		}
		int min = 1e9;
		int max = -1e9;
		// rep(i, n)
		// {
		// 	for (int j = 0; j < n; ++j)
		// 		cout << z[i][j] << " ";
		// 	cout << endl;
		// }
		for (int i = 0; i < n; ++i)
		{
			int inf[5] = {0};
			inf[i] = 1;
			int flag = 0;

			for (int j = 0; j < n; ++j)
			{
				if (z[i][j] != 0)
				{
					flag = 1;
					inf[j] = 1;
					for (int k = 0; k < n; ++k)
					{
						if (z[j][k] > z[i][j])
							inf[k] = 1;
					}
				}
			}
			if (flag == 0)
			{
				min = 1;
			}
			int count = 0;
			rep(i, 5)
			{
				if (inf[i] == 1)
					++count;
			}
			if (count > max)
				max = count;
			if (count < min)
				min = count;
		}
		cout << min << " " << max << endl;
	}
	return 0;
}