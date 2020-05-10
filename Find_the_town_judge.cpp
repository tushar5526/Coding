//https://leetcode.com/submissions/detail/337213811/?from=/explore/challenge/card/may-leetcoding-challenge/535/week-2-may-8th-may-14th/3325/

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        for(int i = 1; i<=n; i++)
        {
            int flag = 0;
            for(int j = 0; j < trust.size(); j++)
            {
                if(trust[j][0] == i)
                {
                    flag = 1;
                    break;
                }
            }
            if(flag == 0)
            {
                int count = 0;
                for(int j = 0; j < trust.size(); j++)
                {
                    if(trust[j][1] == i)
                    {
                        count++;
                    }
                }
                
                if(count == n-1)
                    return i;
            }
        }
        return -1;
    }
};