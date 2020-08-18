//
#include <bits/stdc++.h>

#define mod 1000000007
#define lli long long int
#define endl '\n'
using namespace std;
#define REP(i, n) for (int i = 0; i < n; i++)

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        map<char, int> sm;
        string s, p;
        cin >> s >> p;
        REP(i, s.size())
        {
            ++sm[s[i]];
        }
        REP(i, p.size())
        {
            --sm[p[i]];
        }

        string l = "";
        for (auto i : sm)
        {
            while (i.second)
            {
                l.push_back(i.first);
                --i.second;
            }
        }
        sort(l.begin(), l.end());
        string f = "";

        int id=-1;
        // cout<<"l is "<<l<<endl;
        // cout<<"p is "<<p<<endl;

        REP(i, l.size())
        {
            if (l[i] < p[0])
            {
                f.push_back(l[i]);
                id = i;
            }
            else if (l[i] == p[0])
            {
                for (int j = 1; j < p.size(); ++j)
                {
                    if (p[j] < p[0])
                    {
                        f += p;
                        break;
                    }
                    else if (p[j] > p[0])
                    {
                        for (int k = i; l[k] == p[0]; ++k)
                        {
                            f.push_back(l[k]);
                            id = k;
                        }
                        f += p;
                        break;
                    }
                }
                break;
            }
            else
            {
                f += p;
                break;
            }
        }

        // cout<<"f is now "<<f<<endl;

        if(id == l.size()-1)
            f += p;

        for (int i = id + 1; i < l.size(); ++i)
            f.push_back(l[i]);

        

        cout << f << endl;
    }
    return 0;
}