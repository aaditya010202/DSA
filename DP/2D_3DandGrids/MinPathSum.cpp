// leetcode
class Solution {
//RECURSION
// private:
//     int solve(vector<vector<int>> &grid, int row, int col)
//     {
//         if(row==0 && col==0) return grid[row][col];
//         if(row<0 || col<0) return INT_MAX;
//         int up=solve(grid, row-1, col);
//         int left=solve(grid, row, col-1);

//         return grid[row][col]+min(up,left);
//     }
// public:
//     int minPathSum(vector<vector<int>>& grid) {
//         int r=grid.size();
//         int c=grid[0].size();
//         return solve(grid, r-1 , c-1);
//     }


// MEMOIZATION
// private:
//     int solve(vector<vector<int>> &grid, int row, int col, vector<vector<int>> &dp)
//     {
//         if(row==0 && col==0) return grid[row][col];
//         if(row<0 || col<0) return INT_MAX;
//         if(dp[row][col]!=-1) return dp[row][col];
//         int up=solve(grid, row-1, col,dp);
//         int left=solve(grid, row, col-1,dp);

//         return dp[row][col]=grid[row][col]+min(up,left);
//     }
// public:
//     int minPathSum(vector<vector<int>>& grid) {
//         int r=grid.size();
//         int c=grid[0].size();
//         vector<vector<int>> dp(r,vector<int> (c,-1));
//         // dp[0][0]=grid[0][0];
        
//         return solve(grid,r-1,c-1,dp);
//     }


// TABULATION
public:
    int minPathSum(vector<vector<int>>& grid) {
        int r=grid.size();
        int c=grid[0].size();
        vector<vector<int>> dp(r,vector<int> (c,-1));       
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(i==0 && j==0)
                {
                    dp[i][j]=grid[i][j];
                }
                else{
                    int up,left;
                    if(i>0) up=grid[i][j]+dp[i-1][j];
                    else up=INT_MAX;
                    if(j>0) left=grid[i][j]+dp[i][j-1];
                    else left=INT_MAX;
                    dp[i][j]=min(up,left);
                }
            }
        }
        return dp[r-1][c-1];
    }
};