//https://www.codechef.com/OCT20B/problems/POSAND
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

int g(int n)
{
	return n ^ (n >> 1);
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
		if (n == 1)
		{
			cout << 1 << endl;
			continue;
		}
		if (isInt(log2(n)))
		{
			cout << -1 << endl;
			continue;
		}
		cout << "2 3 1 ";
		n -= 3;
		int a = 4;
		for (int i = 0; i < n; ++i)
		{
			if (isInt(log2(a)))
			{
				cout << a + 1 << " " << a << " ";
				++i;
				++a;
			}
			else
			{
				cout << a << " ";
			}
			a++;
		}
		cout << endl;
	}
	return 0;
}
