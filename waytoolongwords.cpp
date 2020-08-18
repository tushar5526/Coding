#include<iostream>

using namespace std;

int main()
{
	int n;
	cin>>n;
	while(n--)
	{
		string s;
		cin>>s;
		int length = s.length();
		if(length > 10)
		{
			cout<<s[0]<<length - 2<<s[length - 1];
		}
		else
		{
			cout<<s;
		}
		printf("\n");
	}
}