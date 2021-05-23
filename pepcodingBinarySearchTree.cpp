#include <bits/stdc++.h>
using namespace std;

class varStatic
{
public:
    static int size;
    static int sum;
    static int maxn;
    static int height;
    static int diameter;
    static int minn;
};

int varStatic::size = 0;
int varStatic::sum = 0;
int varStatic::maxn = INT_MIN;
int varStatic::minn = INT_MAX;
int varStatic::height = 0;
int varStatic::diameter = 0;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int data)
    {
        left = NULL;
        right = NULL;
        this->data = data;
    }

    Node()
    {
        left = NULL;
        right = NULL;
    }
};

Node *bstConstructor(vector<int> &a, int lo, int hi)
{
    if (lo > hi)
        return NULL;
    Node *root = new Node(a[(lo + hi) / 2]);
    root->left = bstConstructor(a, lo, lo + (hi - lo) / 2 - 1);
    root->right = bstConstructor(a, lo + (hi - lo) / 2 + 1, hi);
    return root;
}

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

void displayBST(Node *root)
{
    if (!root)
        return;
    string s = "";
    if (root->left)
        s = to_string(root->left->data);
    else
        s = ".";
    s += " <- " + to_string(root->data) + " -> ";
    if (root->right)
        s += to_string(root->right->data);
    else
        s += ".";
    cout << s << endl;
    displayBST(root->left);
    displayBST(root->right);
}

void parseInt(vector<int> &a, int n)
{
    string s;
    int cnt = 0;
    while (cnt != n)
    {
        ++cnt;
        cin >> s;
        if (s == "n")
            a.push_back(-1);
        else
            a.push_back(stoi(s));
    }
}

bool find(Node *root, int val)
{
    if (!root)
        return false;
    if (root->data == val)
        return true;
    if (val < root->data)
        return find(root->left, val);
    return find(root->right, val);
}

void travelAndfind(Node *root)
{
    if (!root)
        return;
    varStatic::size += 1;
    varStatic::sum += root->data;
    varStatic::maxn = max(root->data, varStatic::maxn);
    varStatic::minn = min(root->data, varStatic::minn);
    travelAndfind(root->left);
    travelAndfind(root->right);
}

void inorder(Node *root)
{
    if (!root)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

Node *constructor(vector<int> &arr)
{
    if (arr.size() == 0)
        return NULL;
    Node *root = new Node(arr[0]);
    stack<pair<Node *, int>> s;
    s.push({root, 1});
    int id = 0;

    while (!s.empty())
    {
        pair<Node *, int> *curr = &s.top();
        if (curr->second == 1)
        {
            ++id;
            curr->first->left = NULL;
            if (arr[id] != -1)
            {
                curr->first->left = new Node(arr[id]);
                s.push({curr->first->left, 1});
            }
            ++curr->second;
        }
        else if (curr->second == 2)
        {
            ++id;
            curr->first->right = NULL;
            if (arr[id] != -1)
            {
                curr->first->right = new Node(arr[id]);
                s.push({curr->first->right, 1});
            }
            ++curr->second;
        }
        else
        {
            s.pop();
        }
    }
    return root;
}

void addNode(Node *root, int val)
{
    if (!root)
        return;
    if (val < root->data)
    {
        if (!root->left)
        {
            root->left = new Node(val);
            return;
        }
        else
            addNode(root->left, val);
    }
    else
    {
        if (!root->right)
        {
            root->right = new Node(val);
            return;
        }
        else
            addNode(root->right, val);
    }
}

Node *addNode2(Node *root, int val)
{
    if (!root)
        return new Node(val);
    if (val < root->data)
    {
        root->left = addNode2(root->left, val);
        return root;
    }
    else if (val > root->data)
    {
        root->right = addNode2(root->right, val);
        return root;
    }
    else
        return root;
}

Node *findMaxinBST(Node *root)
{
    if (root->right)
        return findMaxinBST(root->right);
    return root;
}

Node *deleteNode(Node *root, int val)
{
    if (!root)
        return NULL;
    if (root->data == val)
    {
        if (root->left && root->right)
        {
            Node *maxInLeft = findMaxinBST(root->left);
            int data = maxInLeft->data;
            deleteNode(maxInLeft, data);
            root->data = data;
            return root;
        }
        else if (root->left)
        {
            root->data = root->left->data;
            Node *tmp = root->left;
            root->left = tmp->left;
            root->right = tmp->right;
            delete tmp;
            return root;
        }
        else if (root->right)
        {
            root->data = root->right->data;
            Node *tmp = root->right;
            root->left = tmp->left;
            root->right = tmp->right;
            delete tmp;
            return root;
        }
        else
        {
            delete root;
            return NULL;
        }
    }
    else if (val < root->data)
        root->left = deleteNode(root->left, val);
    else
        root->right = deleteNode(root->right, val);

    return root;
}

void replaceWithSumOfLarger(Node *root, int &sum)
{
    if (!root)
        return;
    replaceWithSumOfLarger(root->right, sum);
    int data = root->data;
    root->data = sum;
    sum += data;
    replaceWithSumOfLarger(root->left, sum);
}

void nodeToRootPath(Node *root, int val, vector<int> &a)
{
    if (!root)
        return;
    a.push_back(root->data);

    if (root->data == val)
    {
        return;
    }
    if (val < root->data)
    {
        nodeToRootPath(root->left, val, a);
        return;
    }
    else
        nodeToRootPath(root->right, val, a);
    return;
}

int lca(Node *root, int a, int b)
{
    vector<int> pa, pb;
    nodeToRootPath(root, a, pa);
    nodeToRootPath(root, b, pb);

    // for(int i : pa) cout<<i<<" ";
    // cout<<endl;
    // for(int i : pb) cout<<i<<" ";
    // cout<<endl;

    int id = 0;
    for (int i = 0; i < pa.size(); ++i)
    {
        if (i >= pb.size())
            break;
        id = i;
        if (pa[i] != pb[i])
        {
            id = i - 1;
            break;
        }
    }
    return pa[id];
}

void printInRange(Node *root, int lo, int hi)
{
    if (!root)
        return;
    if (root->data >= lo && root->data <= hi)
    {
        printInRange(root->left, lo, hi);
        cout << root->data << "\n";
        printInRange(root->right, lo, hi);
    }
    else if (root->data < lo && root->data < hi)
        printInRange(root->right, lo, hi);
    else
        printInRange(root->left, lo, hi);
}

void targetSumPairBST(Node *root, Node *node, int &sum)
{
    if (!node)
        return;
    targetSumPairBST(root, node->left, sum);
    if ((node->data < sum - node->data) && find(root, sum - node->data))
        cout << node->data << " " << sum - node->data << endl;
    targetSumPairBST(root, node->right, sum);
}
int main()
{
    int n;
    cin >> n;
    vector<int> a;
    parseInt(a, n);
    Node *root = constructor(a);
    int x;
    cin >> x;
    targetSumPairBST(root, root, x);
}
