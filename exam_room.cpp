//
#include <bits/stdc++.h>

#define mod 1000000007
#define lli long long int
#define endl '\n'
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
bool isInt(float k){return floor(k) == k;}
void pvec(vector<int> v){for(int i : v)cout<<i<<" ";cout<<endl;}


class ExamRoom
{
public:
    vector<int> s;
    int n,ns = 9,md = -1;
    ExamRoom(int n)
    {
        n = n;
        s.push_back(0);
        s.push_back(n-1);
    }

    int seat()
    {
        int tmp = ns;
        md = -1;
        for(int i = 0; i<s.size()-1; ++i){
            if(s[i+1] - s[i] > md){
                md = s[i+1] - s[i];
                ns = (s[i+1] + s[i])/2;
            }
        }
        s.push_back(ns);
        sort(s.begin(),s.end());
        pvec(s);
        return tmp;
    }

    void leave(int p)
    {
        s.erase(remove(s.begin(),s.end(),p), s.end());
        pvec(s);
    }
};

int main()
{
    ExamRoom* e = new ExamRoom(10);
    cout<<e->seat()<<endl;
    cout<<e->seat()<<endl;
    cout<<e->seat()<<endl;
    cout<<e->seat()<<endl;
    e->leave(4);
    cout<<e->seat()<<endl;
    
    return 0;
}