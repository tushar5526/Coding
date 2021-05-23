#include<bits/stdc++.h>

using namespace std;

vector<int> find(int a[10001], int id, int x, int s, vector<int> b){
    if(id == s) return b;

    if(a[id] == x) b.push_back(id);
    return find(a, id+1, x, s, b);

}

int main(){
    int n;cin>>n;
    int a[10001];
    for(int i=0; i<n; ++i) cin>>a[i];
    int x;cin>>x;
    vector<int> b;
    b = find(a, 0, x, n, b);
    if(b.size() == 0){
        cout<<-1;
        return 0;
    }
    for(int i : b) cout<<i<<endl;
    return 0;
}