#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#define rep(i, n) for (int i = 0; i < n; ++i)

using namespace std;
const int MAX = 1e4 + 5;
int id[MAX], nodes, edges;
pair<long long, pair<int, int>> p[MAX];

void initialize()
{
    for (int i = 0; i < MAX; ++i)
        id[i] = i;
}

int root(int x)
{
    while (id[x] != x)
    {
        id[x] = id[id[x]];
        x = id[x];
    }
    return x;
}

void union1(int x, int y)
{
    int p = root(x);
    int q = root(y);
    id[p] = id[q];
}

long long kruskal(pair<long long, pair<int, int>> p[])
{
    int x, y;
    long long cost, minimumCost = 0;
    for (int i = 0; i < edges; ++i)
    {
        // Selecting edges one by one in increasing order from the beginning
        x = p[i].second.first;
        y = p[i].second.second;
        cost = p[i].first;
        // Check if the selected edge is creating a cycle or not
        if (root(x) != root(y))
        {
            minimumCost += cost;
            union1(x, y);
        }
    }
    return minimumCost;
}

int main()
{
    int n, d;
    cin >> n >> d;
    long long weight, cost, minimumCost;
    initialize();
    nodes = n;
    edges = (n * (n - 1)) / 2;
    vector<vector<int>> ver;
    rep(i, n)
    {
        vector<int> a;
        for (int j = 0; j < d; ++j)
        {
            int tmp;
            cin >> tmp;
            a.push_back(tmp);
        }
        ver.push_back(a);
    }

    int id = 0;
    rep(i, n)
    {
        for (int j = i + 1; j < n; ++j)
        {
            int wt = 0;
            for (int k = 0; k < d; ++k)
                wt += abs(ver[i][k] - ver[j][k]);
            p[id++] = make_pair(-wt, make_pair(i, j));
        }
    }

    sort(p, p + edges);
    minimumCost = -kruskal(p);
    cout << minimumCost << endl;
    return 0;
}