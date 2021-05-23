//
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

bool comp(vector<int> a, vector<int> b)
{
    return a.size() < b.size();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        vector<int> ir;
        vector<int> ans(n);
        vector<int> shv(n);
        vector<vector<int>> mans(n, vector<int>(0));
        int lfx = -1, mx = 0, sh = 0;
        rep(i, n)
        {
            if (s[i] == 'X')
            {
                sh = 0;
                ir.clear();
                lfx = i;
            }
            else if (s[i] == ':')
            {
                ++sh;
            }
            else if (s[i] == 'I')
            {
                ir.push_back(i);
            }
            else if (s[i] == 'M')
            {
                cout << "IRU is ";
                for (int i : ir)
                    cout << i << ' ';
                cout << endl;
                for (int j = 0; j < ir.size() && ir[j] > lfx; ++j)
                {
                    int tsh = 0;
                    if (i > 0)
                        tsh = shv[i - 1] - shv[ir[j]];
                    int pw = k + 1 - abs(i - ir[j]) - tsh;
                    cout << "sheets for Magnet at id left " << i << " are " << tsh << "for rod " << ir[j] << "and pow " << pw << " lfx " << lfx << endl;
                    if (pw <= 0)
                        break;
                    ++ans[ir[j]];
                    mans[i].push_back(ir[j]);
                }
            }
            shv[i] = sh;
        }
        sh = 0;
        lfx = 1e9;
        ir.clear();
        fill(shv.begin(), shv.end(), 0);
        for (int i = n - 1; i >= 0; --i)
        {
            if (s[i] == 'X')
            {
                sh = 0;
                ir.clear();
                lfx = i;
            }
            else if (s[i] == ':')
            {
                ++sh;
            }
            else if (s[i] == 'I')
            {
                ir.push_back(i);
            }
            else if (s[i] == 'M')
            {
                cout << "IR is ";
                for (int i : ir)
                    cout << i << ' ';
                cout << endl;
                // cout << "ir size for mag " << i << " " << ir.size() << endl;
                //ulta check karo
                for (int j = ir.size() - 1; j >= 0 && ir[j] < lfx; --j)
                {
                    int tsh = 0;
                    if (i < n - 1)
                        tsh = shv[i + 1] - shv[ir[j]];

                    int pw = k + 1 - abs(i - ir[j]) - tsh;
                    cout << "sheets for Magnet at id right " << i << " are " << tsh << "for rod " << ir[j] << "and pow " << pw << " lfx " << lfx << endl;

                    if (pw <= 0)
                        break;
                    ++ans[ir[j]];
                    mans[i].push_back(ir[j]);
                }
            }
            shv[i] = sh;
        }

        for (auto i : mans)
        {
            for (int j : i)
            {
                cout << j << " ";
            }
            cout << endl;
        }
        sort(mans.begin(), mans.end(), comp);
        for (int i = 0; i < mans.size(); ++i)
            sort(mans[i].begin(), mans[i].end());
        // cout << "Sorted\n";
        // for (auto i : mans)
        // {
        //     if (i.size() == 0)
        //         continue;
        //     for (int j : i)
        //     {
        //         cout << j << " ";
        //     }
        //     cout << endl;
        // }
        // for (auto i : mans)
        // {
        //     for (int j : i)
        //     {
        //         cout << j << " ";
        //     }
        //     cout << endl;
        // }
        map<int, bool> irused;
        mx = 0;
        for (auto i : mans)
        {
            if (i.size() != 0)
                for (int j : i)
                {
                    // cout << "j " << j;
                    if (irused[j] == 0)
                    {
                        ++mx;
                        irused[j] = true;
                        break;
                    }
                }
        }
        cout << mx << endl;
    }
    return 0;
}