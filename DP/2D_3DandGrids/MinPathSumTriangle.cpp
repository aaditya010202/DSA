// leetcode
class Solution {
    // RECURSION
//     private:
//     int solve(vector<vector<int>> & triangle, int row, int col)
//     {
//         if(row==triangle.size()-1 ) return triangle[row][col];

//         int up=triangle[row][col]+solve(triangle, row+1, col);
//         int left=triangle[row][col]+solve(triangle,row+1, col+1);
//         return min(up,left);
//     }
// public:
//     int minimumTotal(vector<vector<int>>& triangle) {
//         int r=triangle.size();
//         int c=triangle[0].size();
//         return solve(triangle, 0, 0);
//     }

    // MEMOIZATION
    // private:
    // int solve(vector<vector<int>> & triangle, int row, int col, vector<vector<int>> &dp)
    // {
    //     if(row==triangle.size()-1 ) return triangle[row][col];
    //     if(dp[row][col]!=-1) return dp[row][col];

    //     int down=triangle[row][col]+solve(triangle, row+1, col,dp);
    //     int diag=triangle[row][col]+solve(triangle,row+1, col+1,dp);
    //     return dp[row][col]=min(down,diag);

    // }
    // public:
    // int minimumTotal(vector<vector<int>>& triangle) {
    //     int r=triangle.size();
    //     int c=triangle[r-1].size();
    //     vector<vector<int>> dp(r, vector<int> (c,-1));
    //     return solve(triangle, 0, 0, dp);
    // }


    //TABULATION
    public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int r=triangle.size();
        int c=triangle[r-1].size();
        vector<vector<int>> dp(r, vector<int> (c,-1));
        for(int i=0;i<c;i++)
        {
            dp[r-1][i]=triangle[r-1][i];
        }

        for(int i=r-2;i>=0;i--)
        {
            for(int j=i;j>=0;j--)
            {
                int up=triangle[i][j]+dp[i+1][j];
                int diag=triangle[i][j]+dp[i+1][j+1];
                dp[i][j]=min(up,diag);
            }
        }
        return dp[0][0];
    }
};