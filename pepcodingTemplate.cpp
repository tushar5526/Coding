#include <bits/stdc++.h>
using namespace std;

class staticVar
{
public:
    static int maxSubTreeSum;
    static string maxSubTreeSumAns;
    static int diameter;
};

class Node
{
public:
    int data;
    vector<Node *> children;
};

void printArray(vector<int> a)
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
    cout << "]\n";
}

Node *constructor(vector<int> &arr)
{
    Node *root = new Node();
    root->data = arr[0];
    stack<Node *> s;
    s.push(root);
    for (int i = 1; i < arr.size(); ++i)
    {
        if (arr[i] == -1)
        {
            s.pop();
            continue;
        }
        Node *tmp = new Node();
        tmp->data = arr[i];
        s.top()->children.push_back(tmp);
        s.push(tmp);
    }
    return root;
}

void reverseQueue(queue<Node *> &q)
{
    if (q.empty())
        return;

    Node *data = q.front();
    q.pop();
    reverseQueue(q);
    q.push(data);
}

void levelWiseZigZag(Node *root)
{
    queue<Node *> q;
    q.push(root);
    int f = 1;
    while (q.size())
    {
        queue<Node *> qtmp;
        while (q.size())
        {
            Node *tmp = q.front();
            cout << tmp->data << " ";
            q.pop();
            for (int i = tmp->children.size() - 1; i >= 0; --i)
                qtmp.push(tmp->children[i]);
        }
        f = !f;
        if (f)
            reverseQueue(qtmp);
        cout << endl;
        q = qtmp;
    }
}

void display(Node *root)
{
    if (!root)
        return;
    cout << root->data << " ";
    for (Node *c : root->children)
        display(c);
}

void Display(Node *node)
{
    string str = to_string(node->data) + " -> ";
    for (Node *child : node->children)
    {
        str += to_string(child->data) + ", ";
    }
    str += ".";
    cout << str << endl;

    for (Node *child : node->children)
    {
        Display(child);
    }
}

void mirror(Node *root)
{
    if (!root)
        return;
    for (Node *c : root->children)
        mirror(c);
    reverse(root->children.begin(), root->children.end());
}

void removeLeaf(Node *root)
{
    if (root->children.size() == 0)
        return;
    vector<Node *> child;
    for (Node *c : root->children)
    {
        if (c->children.size() != 0)
            child.push_back(c);
    }
    root->children = child;
    for (Node *c : child)
        removeLeaf(c);
}

void preorder(Node *root, vector<int> &pre)
{
    if (!root)
        return;
    pre.push_back(root->data);
    for (Node *c : root->children)
        preorder(c, pre);
}

void postorder(Node *root, vector<int> &post)
{
    if (!root)
        return;
    for (Node *c : root->children)
        postorder(c, post);
    post.push_back(root->data);
}
void linearize(Node *root)
{
    Node *parent = root;
    stack<Node *> s;

    do
    {
        for (int i = parent->children.size() - 1; i >= 0; --i)
            s.push(parent->children[i]);
        Node *curr = s.top();
        parent->children = {curr};
        parent = curr;
        s.pop();
    } while (!s.empty());
}

bool find(Node *root, int val)
{
    if (!root)
        return false;
    if (root->data == val)
        return true;
    for (Node *c : root->children)
        if (find(c, val))
            return true;
    return false;
}

vector<int> findNodeToRootPath(Node *root, int val, vector<int> a)
{
    if (!root)
        return {};

    a.push_back(root->data);
    if (root->data == val)
    {
        return a;
    }
    for (Node *c : root->children)
    {
        vector<int> tmp = findNodeToRootPath(c, val, a);
        if (tmp.size() != 0)
            return tmp;
    }
    vector<int> tmp;
    return tmp;
}

bool findNodeToRootPath2(Node *root, int val, vector<int> &a)
{
    if (!root)
        return false;
    if (root->data == val)
    {
        a.push_back(val);
        return true;
    }
    for (Node *c : root->children)
    {
        if (findNodeToRootPath2(c, val, a))
        {
            a.push_back(root->data);
            return true;
        }
    }
    return false;
}

int lcancestor(Node *node, int a, int b)
{
    for (Node *c : node->children)
        if (find(c, a) && find(c, b))
            return lcancestor(c, a, b);
    return node->data;
}

int lcancestor2(Node *root, int a, int b)
{
    vector<int> va, vb;
    findNodeToRootPath2(root, a, va);
    findNodeToRootPath2(root, b, vb);
    int vap = va.size() - 1;
    int vbp = vb.size() - 1;
    while (1)
    {
        if (va[vap] != vb[vbp])
            return va[vap + 1];
        --vap;
        --vbp;
    }
}

int findMinimumDistance(Node *root, int a, int b)
{
    vector<int> va, vb;
    findNodeToRootPath2(root, a, va);
    findNodeToRootPath2(root, b, vb);
    int la = lcancestor2(root, a, b);
    int as = 0, bs = 0;
    for (int i = 0; i < va.size(); ++i)
        if (va[i] == la)
            break;
        else
            ++as;

    for (int i = 0; i < vb.size(); ++i)
        if (vb[i] == la)
            break;
        else
            ++bs;

    return as + bs;
}

bool areSimilar(Node *root1, Node *root2)
{
    if (root1->children.size() != root2->children.size())
        return false;

    for (int i = 0; i < root1->children.size(); ++i)
        if (!areSimilar(root1->children[i], root2->children[i]))
            return false;
    return true;
}

bool areSimilarhack(vector<int> &a, vector<int> &b)
{
    if (a.size() != b.size())
        return false;
    for (int i = 0; i < a.size(); ++i)
        if (a[i] == -1 || b[i] == -1)
            if (a[i] != b[i])
                return false;
    return true;
}

bool areSimilarMirror(Node *root1, Node *root2)
{
    if (root1->children.size() != root2->children.size())
        return false;
    for (int i = 0; i < root1->children.size(); ++i)
        if (!areSimilarMirror(root1->children[i], root2->children[root2->children.size() - i - 1]))
            return false;
    return true;
}

bool isSymmetric(Node *root)
{
    int start = 0;
    int end = root->children.size() - 1;
    while (start < end)
    {
        if (!areSimilarMirror(root->children[start], root->children[end]))
            return false;
        ++start;
        --end;
    }
    return true;
}

void multisolver(Node *node, int &size, int &min, int &max, int &height, int depth)
{
    ++size;
    min = std::min(min, node->data);
    max = std::max(max, node->data);
    height = std::max(height, depth);

    for (Node *c : node->children)
        multisolver(c, size, min, max, height, depth + 1);
}

void maxSubtreeSum(Node *node)
{
    if (!node)
        return;
    int sum = node->data;
    for (Node *c : node->children)
    {
        maxSubtreeSum(c);
        sum += c->data;
    }
    if (sum > staticVar::maxSubTreeSum)
    {
        staticVar::maxSubTreeSum = sum;
        staticVar::maxSubTreeSumAns = to_string(node->data) + "@" + to_string(sum);
    }
    node->data = sum;
}

int staticVar::maxSubTreeSum = 10;
string staticVar::maxSubTreeSumAns = "";
int staticVar::diameter = INT_MIN;

void diameterOfTree(Node *node)
{
    if (node->children.size() == 0)
    {
        node->data = 0;
        return;
    }
    for (Node *c : node->children)
        diameterOfTree(c);

    int edges = 0;

    for (Node *c : node->children)
        if (c->data + 1 > edges)
            edges = c->data + 1;

    node->data = edges;
    vector<int> data;
    if (node->children.size() >= 2)
    {
        for (Node *c : node->children)
            data.push_back(c->data);
        sort(data.begin(), data.end());
        int a = data[data.size() - 1];
        int b = data[data.size() - 2];
        if (a + b + 2 > staticVar::diameter)
            staticVar::diameter = a + b + 2;
    }
}

void iterativePreorderandPostOrder(Node *node)
{
    stack<Node *> s;
    s.push(node);
    string pre = "", post = "";
    while (!s.empty())
    {
        Node* curr = s.top();
        pre += to_string(curr->data) + " ";
        
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    Node *root = constructor(a);
    diameterOfTree(root);
    cout << staticVar::diameter;
    return 0;
}