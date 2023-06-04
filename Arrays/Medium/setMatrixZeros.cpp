// Leetcode solution
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<pair<int,int>>arr;
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[0].size();j++)
            {
                if(matrix[i][j]==0)
                {
                    arr.push_back(make_pair(i,j));
                }
            }
        }
        for(auto x:arr)
        {
            for(int i=0;i<matrix.size();i++)
            {
                matrix[i][x.second]=0;
            }
            for(int i=0;i<matrix[0].size();i++)
            {
                matrix[x.first][i]=0;
            }
        }
    }
};