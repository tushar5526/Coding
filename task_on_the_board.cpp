
#include<bits/stdc++.h>
#include<vector>

using namespace std;

/*
string print(vector<int> a)
{
    for(int i =0; i<a.size(); i++)
        cout<<a[i]<<' ';
    cout<<endl;

    return "";
}

string print(vector<char> a)
{
    for(int i =0; i<a.size(); i++)
        cout<<a[i]<<' ';
    cout<<endl;
}
*/

string make_string(vector<int> a, vector<char> s,string t,vector<int> index)
{

    vector<int> in;
    int flag = 0;

    /*
    cout<<"=================================\n";
    cout<<"a "<<print(a);
    cout<<"s "<<print(s);
    cout<<"t "<<t<<endl;
    cout<<"index "<<print(index);
    */

    for(int i = 0; i<a.size(); i++)
    {
        if(a[i] > 0)
        {
            flag = 1;
            for(int j = 0; j < index.size(); j++)
            {
                a[i] -= abs(index[j] - i);
            }

            if(a[i] == 0)
            {
                in.push_back(i);
            }
        }
        else if(a[i] == 0)
        {   
            a[i] = -1;
            //cout<<"t  after changed "<<t<<endl;
        }
    }   

    if(index.size() > 1)
        {
            char tmp = s[s.size() - 1];
            int count = 1;
            for(int i = s.size() - 2; i>=0; i--)
            {
                if(s[i] == tmp)
                {
                    count += 1;
                    if(count == index.size())
                    {
                        for(int j = 0; j < index.size(); j++)
                        {
                            t[index[j]] = tmp;
                        }
                        break;
                    }
                }
                else
                {
                    count = 1;
                    tmp = s[i];
                }
                
            }

            int flag = 1;
            while(flag == 1 || s[s.size() - 1] == tmp)
            {
                s.pop_back();
                if(s[s.size() - 1] == tmp)
                    flag = 0;
            }
        }
        else
        {
            t[index[0]] = s[s.size() - 1];
            
            while(t[index[0]] == s[s.size() - 1])
                s.pop_back();
            
        }
        


    /*
    cout<<"a "<<print(a);
    cout<<"s "<<print(s);
    cout<<"t "<<t<<endl;
    cout<<"in "<<print(in);
    cout<<"index "<<print(index);
    cout<<"=================================\n";
    cout<<"\n\n";
    */

    if(flag == 1)
    {
        return make_string(a,s,t,in);
    }
    else
    {
        return t;
    }
}

int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        string tmp;
        vector<char> s;
        int n;
        vector<int> a;
        vector<int> index;
        string t = "";
        cin>>tmp>>n;
        for(int i = 0; i<tmp.length(); i++)
        {
            s.push_back(tmp[i]);
        }

        for (int i = 0; i < n; i++)
        {
            int tmp;
            cin>>tmp;
            
            if(tmp  == 0)
                index.push_back(i);

            a.push_back(tmp);
        }
        
        sort(s.begin(), s.end());

        for(int i = 0; i<n; i++)
        {
            t += "0";
        }
        //cout<<"\n\n";
        cout<<make_string(a,s,t,index)<<endl;

    }
    
    return 0;
}