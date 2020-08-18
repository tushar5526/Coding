#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
int factorial(int n){
    int tmp  = 1;
    while(n){
        tmp *= n;
        --n;
    }
    return tmp;
}


int fact(string s)
{
    int tmp = 1;
    int n = s.size();
    map<char, int> p;
    for(int i=0; i<s.size(); ++i){
        ++p[s[i]];
    }
    while (n)
    {
        tmp *= n;
        --n;
    }
    for(auto i : p){
        tmp /= factorial(i.second);
    }
    return tmp;
}

int main()
{
    string s;
    cin >> s;
    int f = fact(s);
    int x = f;
    string st = s;
    map<string, int> per;
    srand(time(NULL));
    while (f)
    {
        st = s;
        int tmp = s.size();
        string r = "";
        while (tmp)
        {
            int id = rand() % s.size();
            if (st[id] == '\n')
                continue;
            r += st[id];
            st[id] = '\n';
            --tmp;
        }
        if (per.find(r) == per.end())
        {
            ++per[r];
            --f;
            cout << r << " " << x - f  << endl;
        }
    }
    return 0;
}