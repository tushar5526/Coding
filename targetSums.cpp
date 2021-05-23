#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    int x;
    cin >> x;
    vector<int> dp(x + 1, 0);
    dp[0] = 1;
    for (int i : a)
    {
        for(int j = 1; j <= x; ++j){
            if(j - i >= 0){
                dp[j] += dp[j-i];
            }
        }
    }
    cout<<dp[x];
    return 0;
}