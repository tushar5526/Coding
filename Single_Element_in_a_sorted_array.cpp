//https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/535/week-2-may-8th-may-14th/3327/

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        
        int sum = 0;
        for(int i = 0; i < nums.size(); i+=2)
        {
            sum += nums[i]*2;
        }

        int sumt = accumulate(nums.begin(),nums.end(),0);
        cout<<sum<<" "<<sumt;
        return sum - sumt;
    }
};