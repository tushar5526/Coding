#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> fl(n);
  for (int i = 0; i < n; ++i)
    cin >> fl[i];
  int k;
  cin >> k;
  sort(fl.begin(), fl.end());
  for (int i = 0; i < k; ++i)
    cout << fl[i] << " ";

  for (int i = n - 1; i >= k; --i)
    cout << fl[i] << " ";
  return 0;
}