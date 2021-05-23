#include<bits/stdc++.h>
using namespace std;

vector<string> a = {".;", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tu", "vwx", "yz"};

void kpc(string s, int n, string ans){
    if(n == s.size()){
        cout<<ans<<endl;
        return;
    }
    int id = stoi(s.substr(n,1));
    string p = a[id];
    for(char i : p){
        kpc(s, n+1, ans + i);
    }
}

int main(){
    string s;cin>>s;
    kpc(s, 0, "");
    return 0;
}