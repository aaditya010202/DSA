// leetcode
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        for (int i=0;i<matrix[0].size();i++)
        {
            for(int j=i+1;j<matrix[0].size();j++)
            {
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        for(int i=0;i<matrix.size();i++)
        {
            reverse(matrix[i].begin(),matrix[i].end());
        }


// Brute force(not working)
// int n=matrix.size();
// vector<vector<int>> ans[n][n];
//     for(int i=0;i<n;i++)
//     {
//         for(int j=0;j<n;j++)
//         {
//             ans[j][n-1-i]=matrix[i][j];
//         }
//     }

//     matrix=ans;

//     }
};