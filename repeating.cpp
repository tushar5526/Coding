#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	int xr = 0;
	for (int i : a)
		xr ^= i;
	int rmbmask = (xr & (-xr));
	vector<int> on, off;
	for (int i : a)
	{
		// cout << (i & rmbmask) << " ";
		if (i & rmbmask)
		{
			on.push_back(i);
		}
		else
			off.push_back(i);
	}
	int first = 0, second = 0;
	for (int i : on)
		first ^= i;
	for (int i : off)
		second ^= i;
	if(first < second)
	cout << first << endl
		 << second << endl;
	else cout << second << endl
		 << first << endl;
	
	return 0;
}