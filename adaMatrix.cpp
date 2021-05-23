//https://www.codechef.com/SEPT20B/problems/ADAMAT
#include <bits/stdc++.h>

#define mod 1000000007
#define lli long long int
#define endl '\n'
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
bool isInt(float k)
{
    return floor(k) == k;
}

void print(vector<vector<int>> a)
{
    cout << endl;
    for (auto i : a)
    {
        for (int j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}

void swap(vector<vector<int>> &a, int l)
{
    for (int i = 1; i < l; ++i)
    {
        int tmp = a[0][i];
        a[0][i] = a[i][0];
        a[i][0] = tmp;
    }
}

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<vector<int>> a;
        rep(i, n)
        {
            vector<int> b;
            rep(i, n)
            {
                int tmp;
                cin >> tmp;
                b.push_back(tmp);
            }
            a.push_back(b);
        }
        int count = 0;
        while (1)
        {
            int last = 0;
            rep(i, n)
            {
                if (a[0][i] == last + 1)
                {
                    ++last;
                }
                else
                {
                    break;
                }
            }
            // cout << "value of last " << last << endl;
            if (last == n && a[0][n - 1] == last)
            {
                cout << count << endl;
                break;
            }
            else if (last != 1)
            {
                swap(a, last);
                ++count;
                // print(a);
                // cout << "count " << count << endl;
            }
            else
            {
                last = 0;
                rep(i, n)
                {
                    if (a[i][0] == last + 1)
                    {
                        ++last;
                    }
                    else
                    {
                        break;
                    }
                }
                // cout << "value of last " << last << endl;

                swap(a, last);
                ++count;
                // print(a);
                // cout << "count " << count << endl;
            }
        }
    }
    return 0;
}