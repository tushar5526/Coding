//https://leetcode.com/problems/super-palindromes/
#include <bits/stdc++.h>

#define mod 1000000007
#define lli long long int
#define endl '\n'
using namespace std;
#define REP(i, n) for (int i = 0; i < n; ++i)
bool is_integer(float k){ return floor(k) == k;}

class Solution
{
public:
    int isInt(float k){ if (floor(k) == k) return 0; else return 1;}

    map<char, int> m = {
        {'1', 1},
        {'2', 2},
        {'3', 3},
        {'4', 4},
        {'5', 5},
        {'6', 6},
        {'7', 7},
        {'8', 8},
        {'9', 9},
        {'0', 0}};

    bool isPalindrome(int n) 
    {    
        int divisor = 1; 
        while (n / divisor >= 10) 
            divisor *= 10; 

        while (n != 0) 
        { 
            int leading = n / divisor;  
            int trailing = n % 10; 
            if (leading != trailing)   
                return false; 
            n = (n % divisor) / 10; 
            divisor = divisor / 100; 
        } 
        return true; 
    } 
    int superpalindromesInRange(string L, string R)
    {
        long long int l = 0,r = 0;
        for(char i : L)
            l = l * 10 + m[i];
        for(char i : R)
            r = r * 10 + m[i];
        int count = 0;
        float sl = sqrt(l);
        l = (long long int)sl + isInt(sl);
        cout<<r<<endl;
        cout<<l<<endl;
        for(long long int i = l; i*i <= r; ++i){
            if(isPalindrome(i)){
                if(isPalindrome(i * i)){
                    ++count;
                    cout<<i<<endl;
                    cin>>sl;
                }
            }
        }
        return count;
    }
};

int main()
{

    Solution sl;
    cout<<sl.superpalindromesInRange("38455498359","999999999999999999");
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    return 0;
}