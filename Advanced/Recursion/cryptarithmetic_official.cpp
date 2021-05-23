#include <bits/stdc++.h>

using namespace std;

int count(string &s, map<char, int> &mp)
{
    int sum = 0;
    for (int i = 0; i < s.size(); ++i)
    {
        sum = sum * 10 + mp[s[i]];
    }
    return sum;
}

void isCorrect(string &s3, int sum, map<char, int> &mp, vector<bool> usedNumber)
{
    vector<int> a(26, -1);
    // cout << "isCorect called \n";
    for (auto i : mp)
        a[i.first - 'a'] = i.second;
    int id = s3.size() - 1;
    // cout << "sum started with id " << id << "and sum " << sum << endl;
    // cout.flush();
    int flag = 1;
    if (to_string(sum).size() > s3.size())
    {
        flag = 0;
        id = -1;
    }
    while (id >= 0)
    {
        // for (int i = 0; i < a.size(); ++i)
        // {
        //     if (a[i] == -1)
        //         continue;
        //     cout << (char)((int)('a') + i) << "-" << a[i] << " ";
        // }
        // cout << endl;
        int curr = sum % 10;
        if (a[s3[id] - 'a'] == curr)
        {
            sum /= 10;
            --id;
            continue;
        }
        else if (a[s3[id] - 'a'] == -1 && !usedNumber[curr])
        {
            usedNumber[curr] = true;
            a[s3[id] - 'a'] = curr;
        }
        else
        {
            flag = 0;
            break;
        }
        sum /= 10;
        --id;
    }

    // cout << "sum ended " << sum << endl;
    // cout.flush();

    if (flag)
    {
        // cout << "ANS ";
        for (int i = 0; i < a.size(); ++i)
        {
            if (a[i] == -1)
                continue;
            cout << (char)((int)('a') + i) << "-" << a[i] << " ";
        }
        cout << endl;
    }
}

void solve(int id, string &s1, string &s2, string &s3,
           string &s4,
           map<char, int> &mp, vector<bool> &usedNumbers)
{
    // cout << id << endl;
    if (id == s4.size())
    {
        int cs1 = count(s1, mp);
        int cs2 = count(s2, mp);

        // printf("%d %d\n", cs1, cs2);
        // for (auto i : mp)
        //     cout << i.first << "-" << i.second << " ";
        // cout << endl;
        // // cout << "isCorrect called from solve " << endl;
        isCorrect(s3, cs1 + cs2, mp, usedNumbers);
        return;
    }

    if (mp.find(s4[id]) != mp.end())
    {
        solve(id + 1, s1, s2, s3, s4, mp, usedNumbers);
        return;
    }

    for (int i = 0; i < 10; ++i)
    {
        if (!usedNumbers[i])
        {
            // cout << s4[id] << " to " << i << endl;
            mp[s4[id]] = i;
            usedNumbers[i] = true;
            solve(id + 1, s1, s2, s3, s4, mp, usedNumbers);
            usedNumbers[i] = false;
            mp.erase(s4[id]);
        }
    }
}

int main()
{
    string s1, s2, s3, s4;
    cin >> s1 >> s2 >> s3;
    s4 = s1 + s2;
    map<char, int> mp;
    vector<bool> usedNumbers(10, false);
    solve(0, s1, s2, s3, s4, mp, usedNumbers);
    return 0;
}