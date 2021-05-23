#include <bits/stdc++.h>

using namespace std;

struct point {
  int x;
  string s;
};

bool sorter(point const &lhs, point const &rhs) { return lhs.x <= rhs.x; }

int main() {
  vector<point> points;
  int n;
  cin >> n;
  while (n--) {
    int tmp;
    cin >> tmp;
    point tp = point();
    tp.x = tmp;
    tp.s = "S";
    points.push_back(tp);
  }
  cin >> n;
  int ab = 2 * n;

  while (n--) {
    int tmp;
    cin >> tmp;
    point tp = point();
    tp.x = tmp;
    tp.s = "E";
    points.push_back(tp);
  }
  sort(points.begin(), points.end(), &sorter);
  int sum = 0;
  int counter = 0;
  for (int i = 0; i < ab; ++i) {
    cout << points[i].x << " " << points[i].s << endl;
    if (points[i].s == "S")
      ++counter;
    else
      --counter;
    if (counter > 1)
      ++sum;
    
  }
  cout << sum;
}