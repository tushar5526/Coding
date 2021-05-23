#include <bits/stdc++.h>

using namespace std;

void per(string s, string a){
    if(s.size() == 0){
        cout<<a<<endl;
        return;
    }
    for(int i=0; i<s.size(); ++i){
        string q = s.substr(0,i) + s.substr(i+1);
        string ans = s.substr(i,1);
        // cout<<q<<" "<<ans<<endl;
        per(q,a + ans);
    }
}

int main()
{
    string s;
    cin>>s;
    per(s, "");
    return 0;
}