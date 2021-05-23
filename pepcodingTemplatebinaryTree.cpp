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
};

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

void displayBinaryTree(Node *root)
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
    displayBinaryTree(root->left);
    displayBinaryTree(root->right);
}

int varStatic::size = 0;
int varStatic::sum = 0;
int varStatic::maxn = INT_MIN;
int varStatic::height = 0;
int varStatic::diameter = 0;

void ssmh(Node *root, int h)
{
    if (!root)
        return;
    varStatic::size++;
    varStatic::sum += root->data;
    varStatic::maxn = max(varStatic::maxn, root->data);
    varStatic::height = max(h, varStatic::height);
    ssmh(root->left, h + 1);
    ssmh(root->right, h + 1);
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

void levelOrderTraversal(Node *root)
{
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        queue<Node *> tq;
        while (!q.empty())
        {
            Node *curr = q.front();
            q.pop();
            cout << curr->data << " ";
            if (curr->left)
                tq.push(curr->left);
            if (curr->right)
                tq.push(curr->right);
        }
        cout << endl;
        q = tq;
    }
}

bool find(Node *node, int val)
{
    if (!node)
        return false;
    if (node->data == val)
        return true;
    return find(node->left, val) || find(node->right, val);
}

bool nodeToRootPath(Node *node, int val, vector<int> &a)
{
    if (!node)
        return false;
    if (node->data == val)
    {
        a.push_back(val);
        return true;
    }
    if (nodeToRootPath(node->left, val, a))
    {
        a.push_back(node->data);
        return true;
    }
    if (nodeToRootPath(node->right, val, a))
    {
        a.push_back(node->data);
        return true;
    }
    return false;
}

void printKthLevel(Node *root, int k, int h)
{
    if (!root || h > k)
        return;
    if (k == h)
    {
        cout << root->data << "\n";
        return;
    }
    printKthLevel(root->left, k, h + 1);
    printKthLevel(root->right, k, h + 1);
}

bool printKDistAway(Node *root, int k, int val, int h, int &valLevel)
{
    if (!root)
        return false;
    if (root->data == val)
    {
        valLevel = h;
        printKthLevel(root, k, 0);
        return true;
    }
    if (printKDistAway(root->left, k, val, h + 1, valLevel))
    {
        if (k - (valLevel - h) == 0)
            cout << root->data << "\n";
        else
            printKthLevel(root->right, k - (valLevel - h) - 1, 0);
        return true;
    }
    else if (printKDistAway(root->right, k, val, h + 1, valLevel))
    {
        if (k - (valLevel - h) == 0)
            cout << root->data << "\n";
        else
            printKthLevel(root->left, k - (valLevel - h) - 1, 0);
        return true;
    }
    return false;
}

void pathRootToLeafInRange(Node *root, int l, int r, string s, int sum)
{
    if (!root)
        return;
    if (root->left == NULL && root->right == NULL)
    {
        if (root->data + sum > l && root->data + sum < r)
            cout << s + to_string(root->data) << endl;
        return;
    }

    pathRootToLeafInRange(root->left, l, r, s + to_string(root->data) + " ", sum + root->data);
    pathRootToLeafInRange(root->right, l, r, s + to_string(root->data) + " ", sum + root->data);
}

void transformToLeftClone(Node *root)
{
    if (!root)
        return;
    Node *next = root->left;
    Node *tmp = new Node(root->data);
    tmp->left = next;
    root->left = tmp;
    transformToLeftClone(next);
    transformToLeftClone(root->right);
}

void undoTransformToLeftClone(Node *root)
{
    if (!root)
        return;
    Node *next = root->left->left;
    root->left = next;
    undoTransformToLeftClone(root->left);
    undoTransformToLeftClone(root->right);
}

void printSingleChildNode(Node *root)
{
    if (!root)
        return;
    if ((!root->left && root->right) || (root->left && !root->right))
    {
        if (root->left)
            cout << root->left->data << "\n";
        if (root->right)
            cout << root->right->data << endl;
    }
    printSingleChildNode(root->left);
    printSingleChildNode(root->right);
}

void removeLeafNodes(Node *root)
{
    if (root->left)
        if (!root->left->left && !root->left->right)
            root->left = NULL;
        else
            removeLeafNodes(root->left);
    if (root->right)
        if (!root->right->left && !root->right->right)
            root->right = NULL;
        else
            removeLeafNodes(root->right);
}

void diameter(Node *root)
{
    if (!root->left && !root->right)
    {
        root->data = 0;
        return;
    }
    int d = 2;
    int l = 0, r = 0;
    if (root->left)
    {
        diameter(root->left);
        d += root->left->data;
        l = root->left->data + 1;
    }
    if (root->right)
    {
        diameter(root->right);
        d += root->right->data;
        r = root->right->data + 1;
    }
    root->data = max(l, r);
    if (d > varStatic::diameter)
        varStatic::diameter = d;
}

void sumOfNodes(Node *root)
{
    if (!root)
        return;
    varStatic::sum += root->data;
    sumOfNodes(root->left);
    sumOfNodes(root->right);
}

void sumOfSubtrees(Node *root)
{
    if (!root)
        return;
    if (root->left)
    {
        sumOfSubtrees(root->left);
        root->data += root->left->data;
    }
    if (root->right)
    {
        sumOfSubtrees(root->right);
        root->data += root->right->data;
    }
}

void tilt(Node *root)
{
    if (!root)
        return;
    if (!root->left && !root->right)
    {
        root->data = 0;
        return;
    }
    int l = 0, r = 0;
    if (root->left)
        l = root->left->data;
    if (root->right)
        r = root->right->data;
    root->data = abs(l - r);
    tilt(root->left);
    tilt(root->right);
}

void preorder(Node *root, vector<int> &a)
{
    if (!root)
        return;
    preorder(root->left, a);
    a.push_back(root->data);
    preorder(root->right, a);
}

bool isBst(Node *root)
{
    vector<int> a;
    preorder(root, a);
    for (int i = 0; i < a.size() - 1; ++i)
        if (a[i] >= a[i + 1])
            return false;
    return true;
}

pair<int, bool> isBstBalanced(Node *node)
{
    if (!node)
        return {0, true};
    pair<int, bool> l, r;
    l = isBstBalanced(node->left);
    r = isBstBalanced(node->right);
    int curr = abs(l.first - r.first);
    // cout << node->data << " " << l.first << " " << r.first << endl;
    if (!(l.second && r.second) || curr > 1)
        return {-1, false};
    else
        return {max(l.first + 1, r.first + 1), true};
}

pair<int, pair<int, int>> maxSubtreeBSTinBST(Node *root, int &nodeRoot, int &cnt)
{
    int count = 1;
    pair<int, pair<int, int>> left, right;

    if (!root->left)
        left = {0, {root->data, root->data}};
    else
        left = maxSubtreeBSTinBST(root->left, nodeRoot, cnt);

    if (!root->right)
        right = {0, {root->data, root->data}};
    else
        right = maxSubtreeBSTinBST(root->right, nodeRoot, cnt);

    if (left.first == -1 || right.first == -1)
        return {-1, {-1, -1}};

    if (left.second.second <= root->data && right.second.first >= root->data)
    {
        int count = 1 + left.first + right.first;
        if (count > cnt)
        {
            cnt = count;
            nodeRoot = root->data;
        }
        return {count, {std::min(left.second.first, right.second.first), std::max(left.second.second, right.second.second)}};
    }
    else
        return {-1, {-1, -1}};
}

int main()
{
    int n;
    cin >> n;
    vector<int> a;
    parseInt(a, n);
    Node *root = constructor(a);
    int nodeRoot = 0, cnt = -1;
    maxSubtreeBSTinBST(root, nodeRoot, cnt);
    cout << to_string(nodeRoot) + "@" + to_string(cnt);
    return 0;
}
