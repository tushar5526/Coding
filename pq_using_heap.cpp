#include <bits/stdc++.h>
using namespace std;

class pqHeap
{
public:
    vector<int> pqArray;
    /*
        li = 2*pi + 1
        ri = 2*pi + 2
    */
    void add(int val)
    {
        pqArray.push_back(val);
        int cid = pqArray.size() - 1;
        int pid = (cid - (cid % 2 == 0 ? 2 : 1)) / 2;
        while (pid >= 0 && pqArray[cid] < pqArray[pid])
        {
            int x = pqArray[pid];
            pqArray[pid] = pqArray[cid];
            pqArray[cid] = x;
            cid = pid;
            pid = (cid - (cid % 2 == 0 ? 2 : 1)) / 2;
        }
        // print();
    }

    int remove()
    {
        if (pqArray.size() == 0)
            return -1;
        int x = pqArray.back();
        pqArray.pop_back();
        int ans = pqArray[0];
        pqArray[0] = x;
        int pid = 0, lid = 1, rid = 2;
        while (1)
        {
            lid = pid * 2 + 1;
            rid = pid * 2 + 2;

            int sid = 0, smallest = INT_MAX;
            if (lid < pqArray.size())
                smallest = min(pqArray[pid], pqArray[lid]);
            if (rid < pqArray.size())
                smallest = min(smallest, pqArray[rid]);

            if (smallest == INT_MAX)
                break;

            if (smallest == pqArray[pid])
                sid = pid;
            else if (smallest == pqArray[lid])
                sid = lid;
            else
                sid = rid;

            if (sid == pid)
                break;
            int tmp = pqArray[pid];
            pqArray[pid] = pqArray[sid];
            pqArray[sid] = tmp;

            pid = sid;
        }
        // print();
        return ans;
    }

    int peek()
    {
        if (pqArray.size() == 0)
            return -1;
        return pqArray[0];
    }

    int size()
    {
        return pqArray.size();
    }

    void print()
    {
        cout << "pqArray ";
        for (int i : pqArray)
            cout << i << " ";
        cout << endl;
    }
};

int main()
{
    string s;
    int x;
    cin >> s;
    pqHeap pq = pqHeap();

    while (s != "quit")
    {
        if (s == "add")
        {
            cin >> x;
            pq.add(x);
        }
        else if (s == "peek")
        {
            if (pq.peek() == -1)
                cout << "Underflow\n";
            else
                cout << pq.peek() << endl;
        }
        else
        {
            int rm = pq.remove();
            if (rm == -1)
                cout << "Underflow\n";
            else
                cout << rm << endl;
        }
        cin >> s;
    }
    return 0;
}