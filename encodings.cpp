#include <bits/stdc++.h>

using namespace std;

void per(string q, string ans)
{
    if (q.size() == 0)
    {
        cout << ans << endl;
        return;
    }
    else if (q.size() == 1)
    {
        if (stoi(q) == 0)
        {
            cout << "\n"; 
            return;
        }
        cout << ans + (char('a' + stoi(q) - 1)) << endl;
        return;
    }
    else if (q.size() >= 2)
    {
        if (stoi(q.substr(0,1)) == 0)
        {
            return;
        }
        else
        {
            per(q.substr(1), ans + (char('a' + stoi(q.substr(0, 1)) - 1)));
        }
        if (stoi(q.substr(0, 2)) <= 26)
        {
            per(q.substr(2), ans + (char('a' + stoi(q.substr(0, 2)) - 1)));
        }
    }
}

int main()
{
    string s;
    cin >> s;
    per(s, "");
    return 0;
}