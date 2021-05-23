#include <bits/stdc++.h>
using namespace std;

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

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    Node *root = constructor(a);
    int val1, val2;
    cin >> val1 >> val2;
    cout << lcancestor(root, val1, val2);
    return 0;
}
