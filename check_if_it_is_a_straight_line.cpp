/*
https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/535/week-2-may-8th-may-14th/3323/
*/

class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int y = coordinates[1][1] - coordinates[0][1];
        int x = (coordinates[1][0] - coordinates[0][0]);
        float ratio = float(y)/x;
        int flag = 0;
        
        for(int i = 2; i<coordinates.size(); i++)
        {
            
            int tempX = (coordinates[i][0] - coordinates[i-1][0]);
            int tempY = (coordinates[i][1] - coordinates[i-1][1]);
            float tempRatio = float(tempY)/tempX;
            
            if(y == 0)
            {
                if(tempY != 0)
                {
                    return false;
                }
            }
            else if(x == 0)
            {
                if(tempX != 0)
                {
                    return false;
                }
            }
            else if(ratio != tempRatio)
            {
                return false;
            }
        }
        
        if(flag == 0)
        {
            return true;
        }
        
        return false;
        
    }
};