#include<iostream>
using namespace std;

void sub(string ques, string ans){
    if(ques.size() == 0){
        cout<<ans<<endl;
        return;
    }
    string ch = ques.substr(0,1);
    string roq = ques.substr(1);
    sub(roq, ans + ch);
    sub(roq, ans + "");
}

int main(){
    string s;cin>>s;
    sub(s,"");
    return 0;
}