//
#include <bits/stdc++.h>

#define mod 1000000007
#define lli long long int
#define endl '\n'
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
bool isInt(float k)
{
    return floor(k) == k;
}

lli comb(lli n, lli r)
{
    return n * (n - 1) / 2;
}

unsigned lli nsum(lli n)
{
    return n * (n + 1) / 2;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        lli n;
        cin >> n;
        unsigned lli ts = nsum(n);
        // cout<<"ts "<<ts<<endl;
        if (ts % 2 != 0)
        {
            cout << 0 << endl;
            continue;
        }

        lli tn;

        tn = (-1 + sqrt(1 + 4 * ts)) / 2 + 1;
        // cout<<"tn "<<tn<<endl;
        lli s = 0;
        int z = 0;
        while (s < ts / 2)
        {
            s = ts - nsum(--tn);
            ++z;
        }
        // cout<<"z "<<z<<endl;
        unsigned lli count = 0;
        lli p = tn;
        // cout<<tn<<" "<<tn<<" "<<ts<<endl;
        if (s == ts / 2)
        {
            // cout << "p " << p << endl;
            // cout<<"tn "<<tn<<" n - tn "<<n - tn<<" comb(n - tn, 2) "<<comb(n - tn, 2)<<endl;
            count += comb(tn, 2) + comb(n - tn, 2);
            // cout << "count " << count << endl;
            --p;
        }
        do
        { //can be optimised here
            lli sp = ts - nsum(p);
            // cout << "sp " << sp << " p " << p << endl;
            lli x = (ts / 2 - (sp - n));
            if (x > p)
            {
                count += (n - p) - (x - p);
                // cout << "count1 " << count << endl;
            }
            else
            {
                if (x < n - p)
                    count += x;
                else
                    count += n - p;
                // cout << "count2 " << count << endl;
            }
            /*
            for (int i = p + 1; i <= n; ++i)
            {
                // cout << "cond " << (ts / 2 - (sp - i)) << endl;
                if ((ts / 2 - (sp - i)) <= p)
                {
                    if ((ts / 2 - (sp - i)) <= 0)
                        continue;
                    ++count;
                }
                else
                    break;
            }
            */
            --p;
        } while (ts - nsum(p) - n < ts / 2);
        cout << count << endl;
    }
    return 0;
}