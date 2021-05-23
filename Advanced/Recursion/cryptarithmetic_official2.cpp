#include <bits/stdc++.h>

using namespace std;

int count(map<char, int> &mp, string &s)
{
    int sum = 0;
    for (int i = 0; i < s.size(); ++i)
    {
        sum = sum * 10 + mp[s[i]];
    }
    return sum;
}
void solve(map<char, int> mp, string &unique, string &s1, string &s2, string &s3, int idx, vector<bool> &used)
{
    if (idx == unique.size())
    {
        int cs1 = count(mp, s1);
        int cs2 = count(mp, s2);
        int cs3 = count(mp, s3);
        if (cs1 + cs2 == cs3)
        {
            // cout << cs1 << " " << cs2 << " " << cs3 << endl;

            for (auto i : mp)
                cout << i.first << "-" << i.second << " ";
            cout << endl;
        }
        return;
    }

    // for (auto i : mp)
    //     cout << i.first << " " << i.second;
    // cout << endl;

    for (int i = 0; i < 10; ++i)
    {
        if (!used[i])
        {
            used[i] = true;
            mp[unique[idx]] = i;
            solve(mp, unique, s1, s2, s3, idx + 1, used);
            used[i] = false;
            mp[unique[idx]] = -1;
        }
    }
}

int main()
{
    string s1, s2, s3, unique;
    cin >> s1 >> s2 >> s3;
    map<char, int> mp;
    for (char i : s1)
    {
        if (mp.find(i) == mp.end())
            unique += i;
        mp[i] = -1;
    }
    for (char i : s2)
    {
        if (mp.find(i) == mp.end())
            unique += i;
        mp[i] = -1;
    }
    for (char i : s3)
    {
        if (mp.find(i) == mp.end())
            unique += i;
        mp[i] = -1;
    }

    vector<bool> used(10, false);

    solve(mp, unique, s1, s2, s3, 0, used);
    return 0;
}