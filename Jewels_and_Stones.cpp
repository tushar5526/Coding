//https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/534/week-1-may-1st-may-7th/3317/

class Solution {
public:
    int numJewelsInStones(string J, string S) {
        
        int count = 0;
        for(int i = 0; i<J.length(); i++)
        {
            for(int j = 0; j< S.length(); j++)
            {
                if(S[j] == J[i])
                    count++;
            }
        }       
        return count;
    }
};