//
#include <bits/stdc++.h>

#define mod 1000000007
#define lli long long int
#define endl '\n'
using namespace std;
#define REP(i, n) for (int i = 0; i < n; i++)

class Solution
{
public:
    string largestTimeFromDigits(vector<int> &A)
    {
        sort(begin(A), end(A), greater<int>());
        do
        {
            if ((A[0] < 2 || (A[0] == 2 && A[1] < 4)) && A[2] < 6)
                return to_string(A[0]) + to_string(A[1]) + ":" + to_string(A[2]) + to_string(A[3]);
        } 
        while (prev_permutation(begin(A), end(A)));
        return "";
    }
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solution sl;

    cout << "\n " << sl.lengthOfLastWord("Hello World");
    return 0;
}