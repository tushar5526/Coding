#include <bits/stdc++.h>

using namespace std;

class Edge
{
public:
    int src;
    int nbr;
    int wt;

    Edge(int src, int nbr, int wt)
    {
        this->src = src;
        this->nbr = nbr;
        this->wt = wt;
    }
};

void printArray(vector<int> a, int newLine = 1)
{
    if (a.size() == 0)
    {
        cout << "[]";
        return;
    }
    cout << "[";
    for (int i = 0; i < a.size() - 1; ++i)
        cout << a[i] << ", ";
    cout << a[a.size() - 1];
    cout << "]";

    if (newLine)
        cout << "\n";
}

void printMultiArray(vector<vector<int>> &a)
{
    if (a.size() == 0)
    {
        cout << "[]";
        return;
    }
    cout << "[";
    for (int i = 0; i < a.size() - 1; ++i)
    {
        printArray(a[i], 0);
        cout << ", ";
    }
    printArray(a[a.size() - 1], 0);
    cout << "]";
}

bool hasPath(vector<vector<Edge>> &graph, int v, int s, map<string, bool> &mp, vector<int> &visited)
{
    string key = to_string(v);
    if (mp.find(key) != mp.end())
        return mp[key];
    visited[v] = 1;

    if (v == s)
        return true;
    for (Edge e : graph[v])
    {
        if (!visited[e.nbr] && hasPath(graph, e.nbr, s, mp, visited))
            return true;
    }
    mp[key] = false;
    visited[v] = 0;
    return false;
}

void printPath(vector<vector<Edge>> &graph, int v, int s, vector<int> &visited, string path)
{
    if (visited[v])
        return;
    if (v == s)
        cout << path + to_string(v) << endl;

    visited[v] = 1;

    for (Edge e : graph[v])
    {
        if (!visited[e.nbr])
            printPath(graph, e.nbr, s, visited, path + to_string(v));
    }

    visited[v] = 0;
}

void connectedComponents(vector<vector<Edge>> &graph, int v, vector<int> &visited, vector<int> &comp)
{
    if (visited[v])
        return;

    visited[v] = 1;
    comp.push_back(v);
    for (Edge e : graph[v])
        connectedComponents(graph, e.nbr, visited, comp);
}

void printHamiltonianPathAndCycle(vector<vector<Edge>> &graph, int v, int count, vector<int> &visited, string path)
{
    if (visited[v])
        return;
    if (count == visited.size())
    {
        string suffix = ".";
        for (Edge e : graph[0])
            if (e.nbr == v)
            {
                suffix = '*';
                break;
            }

        cout << path + to_string(v) + suffix << endl;
        return;
    }

    visited[v] = 1;

    for (Edge e : graph[v])
    {
        if (!visited[e.nbr])
            printHamiltonianPathAndCycle(graph, e.nbr, count + 1, visited, path + to_string(v));
    }

    visited[v] = 0;
}

bool bfs(vector<vector<Edge>> &graph, int src, vector<int> &visited, bool cycle = false)
{
    queue<pair<int, string>> q;
    q.push({src, ""});
    while (!q.empty())
    {
        pair<int, string> curr = q.front();
        q.pop();

        if (visited[curr.first])
            if (cycle)
                return true;
            else
                continue;
        visited[curr.first] = 1;
        if (!cycle)
            cout << curr.first << "@" << curr.second << curr.first << endl;
        for (Edge e : graph[curr.first])
        {
            if (visited[e.nbr])
                continue;
            q.push({e.nbr, curr.second + to_string(curr.first)});
        }
    }
    return false;
}

bool findCycle(vector<vector<Edge>> &graph, int vertices)
{
    vector<int> visited(vertices);
    for (int i = 0; i < vertices; ++i)
        if (!visited[i] && bfs(graph, i, visited, true))
        {
            return true;
        }
    return false;
}

int countInfected(vector<vector<Edge>> &graph, int t, int src)
{
    vector<int> visited(graph.size());
    queue<int> q;
    q.push(src);
    visited[src] = 1;
    int count = 0;
    while (q.size() && t)
    {
        queue<int> tq;
        while (q.size())
        {
            ++count;
            int curr = q.front();
            // cout<<curr<<" ";
            q.pop();
            for (Edge e : graph[curr])
            {
                if (!visited[e.nbr])
                {
                    visited[e.nbr] = 1;
                    tq.push(e.nbr);
                }
            }
        }
        // cout<<endl<<"T "<<t<<endl;
        q = tq;
        t--;
    }
    return count;
}

class dPair
{
public:
    int ver;
    int from;
    int to;
    string psf;
    int wt;
};

bool operator<(const dPair &p1, const dPair &p2)
{
    return p1.wt >= p2.wt;
}

void prims(vector<vector<Edge>> &graph)
{
    priority_queue<dPair> pq;
    vector<int> visited(graph.size());
    for (Edge e : graph[0])
    {
        dPair tmp;
        tmp.from = e.src;
        tmp.to = e.nbr;
        tmp.wt = e.wt;
        pq.push(tmp);
    }
    visited[0] = 1;
    while (pq.size())
    {
        dPair p = pq.top();
        pq.pop();
        if (visited[p.to])
            continue;
        visited[p.to] = 1;
        cout << "[" << p.to << "-" << p.from << "@" << p.wt << "]" << endl;
        for (Edge e : graph[p.to])
        {
            if (visited[e.nbr])
                continue;
            dPair tmp;
            tmp.from = e.src;
            tmp.to = e.nbr;
            tmp.wt = e.wt;
            pq.push(tmp);
        }
    }
}

void dijkstra(int src, vector<vector<Edge>> &graph)
{
    dPair pair;
    pair.ver = src;
    pair.psf = to_string(src);
    pair.wt = 0;
    priority_queue<dPair> pq;
    vector<int> visited(graph.size());
    pq.push(pair);
    while (pq.size())
    {
        dPair p = pq.top();
        pq.pop();
        // cout <<"TMP " << p.ver << " via " << p.psf << " @ " << p.wt << endl;

        if (visited[p.ver])
            continue;
        visited[p.ver] = 1;

        cout << p.ver << " via " << p.psf << " @ " << p.wt << endl;
        for (Edge e : graph[p.ver])
        {
            if (visited[e.nbr])
                continue;
            dPair tmp;
            tmp.ver = e.nbr;
            tmp.psf = p.psf + to_string(e.nbr);
            tmp.wt = e.wt + p.wt;
            pq.push(tmp);
        }
    }
}

void topologicalSort(vector<vector<Edge>> &graph, int src, vector<int> &visited, stack<int> &s)
{
    if (visited[src])
        return;
    cout<<src<<" ";
    visited[src] = 1;
    for (Edge e : graph[src])
    {
        topologicalSort(graph, e.nbr, visited, s);
    }
    s.push(src);
}

int main()
{
    int vtces, edges;
    cin >> vtces >> edges;
    vector<vector<Edge>> graph(vtces, vector<Edge>());
    for (int i = 0; i < edges; ++i)
    {
        int v1, v2, wt = 0;
        cin >> v1 >> v2;
        graph[v1].push_back(Edge(v1, v2, wt));
        graph[v2].push_back(Edge(v2, v1, wt));
    }
    stack<int> s;
    vector<int> visited(graph.size());
    for(int i = 0; i < vtces; ++i)
        topologicalSort(graph, i, visited, s);
    cout<<endl;
    while(!s.empty())
    {
        cout<<s.top()<<"\n";
        s.pop();
    }
    return 0;
}