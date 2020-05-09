//https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/534/week-1-may-1st-may-7th/3316/


class Solution {
public:
    int firstBadVersion(int n) {
        long long int start = 1;
        long long int last = n;
        while(last >= start)
        {
            long long int med = (start + last)/2;
            bool temp = isBadVersion(med);
            if(temp == true)
            {
                last = med - 1;
            }
            else
            {
                start = med + 1;
            }
        }
        //cout<<last<<" "<<start;
        return start;
    }
    
};