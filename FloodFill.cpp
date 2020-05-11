//https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/535/week-2-may-8th-may-14th/3326/

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        
        if(image[sr][sc] == newColor)
            return image;
        
        cout<<sr<<' '<<sc<<endl;
        
        
        for(int i = 0; i<image.size(); i++)
        {
            for(int j = 0; j < image[i].size(); j++)
            {
                cout<<image[i][j];
            }
            cout<<endl;
        }

            cout<<endl;
            cout<<endl;
        
        int iColor = image[sr][sc];
        image[sr][sc] = newColor;

        if(sr - 1 >= 0 && image[sr - 1][sc] == iColor)
        {

            floodFill(image,sr - 1, sc, newColor);
            image[sr - 1][sc] = newColor;

        }
        
        if(sr + 1 < image.size() && image[sr + 1][sc] == iColor)
        {
            floodFill(image,sr + 1, sc, newColor);
            image[sr + 1][sc] = newColor;

        }
        
        if(sc - 1 >= 0 && image[sr][sc - 1] == iColor)
        {
            floodFill(image,sr, sc-1, newColor);
            image[sr][sc - 1] = newColor;
        }
        
        if(sc + 1 < image[0].size() && image[sr][sc + 1] == iColor)
        {
            floodFill(image,sr, sc+1, newColor);
            image[sr][sc + 1] = newColor;
        }
        
        return image;       
    }        
};