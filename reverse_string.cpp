//https://leetcode.com/explore/challenge/card/june-leetcoding-challenge/539/week-1-june-1st-june-7th/3350/

class Solution {
    public:
        void reverseString(vector<char>& s)
        {
            int len=s.size();
            for(int i=0;i<len/2;i++)
            {
                char tmp=s[i];
                s[i]=s[len-1-i];
                s[len-1-i]=tmp;
            }
        }
};