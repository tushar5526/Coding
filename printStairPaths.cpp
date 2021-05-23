#include<bits/stdc++.h>
using namespace std;

void path(int c, int n, string s){
    if(c > n){
        return;
    }
    if(c == n){
        cout<<s<<endl;
    }
    path(c+1, n, s + "1");
    path(c+2, n, s + "2");
    path(c+3, n, s + "3");
}

int main(){
    int n;cin>>n;
    path(0, n, "");
    return 0;
}