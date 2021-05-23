#include <bits/stdc++.h>

using namespace std;

int main()
{
    stack<long long> st;
    map<long long, long long> id;
    long long n;
    cin >> n;
    vector<long long> a(n, 0);
    for (long long i = 0; i < n; ++i)
    {
        cin >> a[i];
        id[a[i]] = i;
    }
    vector<long long> ans(n, 0);
    ans[0] = 1;
    st.push(a[0]);
    for (long long i = 1; i < n; ++i)
    {           
        while (st.size() > 0 && a[i] >= st.top())
            st.pop();
        if (st.size() == 0)
            ans[i] = i + 1;
        else
        {
            ans[i] = i - id[st.top()];
        }
        st.push(a[i]);
    }

    for (long long i : ans)
        cout << i << endl;
    while(st.size() > 0){
        cout<<st.top()<<" ";
        st.pop();
    }
    return 0;
}