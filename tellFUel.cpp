#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  int minRefuelStops(int target, int fuel, vector<vector<int>> &st) {
    int curr = 0;
    sort(st.begin(), st.end());
    priority_queue<int> pq;
    int i = 0;
    int cnt = 0;
    curr += fuel;
    while (curr < target) {
      cnt++;
      while (i < st.size() && st[i][0] <= curr) {
        pq.push(st[i][1]);
        i++;
      }
      if (pq.empty())
        break;
      curr += pq.top();
      pq.pop();
    }
    return curr >= target ? cnt : -1;
  }
};
int main() {
  Solution ob;
  int ngas;
  cin >> ngas;
  vector<vector<int>> val(ngas, vector<int>());
  for (int i = 0; i < ngas; ++i) {
    int tmp;
    cin >> tmp;
    val[i].push_back(tmp);
  }
  cin >> ngas;

  for (int i = 0; i < ngas; ++i) {
    int tmp;
    cin >> tmp;
    val[i].push_back(tmp);
  }

  int d;
  cin >> d;
  int cg;
  cin >> cg;

  cout << (ob.minRefuelStops(d, cg, val));

  return 0;
}