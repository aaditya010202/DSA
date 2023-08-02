// leetcode
// RECURSION
// class Solution {
//     private:
//     int solve(vector<vector<int>> &obstacleGrid, int row, int col)
//     {
//         if(row==0 && col==0) return 1;
//         if(row<0) return 0;
//         if(col<0) return 0;
//         if(obstacleGrid[row][col]==1) return 0;
//         int left=solve(obstacleGrid,row,col-1);
//         int up=solve(obstacleGrid,row-1,col);
//         return left+up;
//     }
// public:
//     int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
//         int m=obstacleGrid.size();
//         int n=obstacleGrid[0].size();
//         if(obstacleGrid[0][0]==1) return 0;
//         return solve(obstacleGrid,m-1,n-1);
//     }
// };


//MEMOIZATION
// class Solution {
//     private:
//     int solve(vector<vector<int>> &obstacleGrid, int row, int col, vector<vector<int>> &dp)
//     {
//         if(row==0 && col==0) return 1;
//         if(row<0) return 0;
//         if(col<0) return 0;
//         if(dp[row][col]!=-1) return dp[row][col];
//         if(obstacleGrid[row][col]==1) return 0;
//         int left=solve(obstacleGrid,row,col-1,dp);
//         int up=solve(obstacleGrid,row-1,col,dp);
//         return dp[row][col]=left+up;
//     }
// public:
//     int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
//         int m=obstacleGrid.size();
//         int n=obstacleGrid[0].size();
//         vector<vector<int>> dp(m,vector<int> (n,-1));
//         if(obstacleGrid[0][0]==1) return 0;
//         return solve(obstacleGrid,m-1,n-1,dp);
//     }
// };


//TABULATION
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n=obstacleGrid[0].size();
        vector<vector<int>> dp(m,vector<int> (n,-1));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                
                if(obstacleGrid[i][j]==1)
                {
                     dp[i][j]=0;
                }
                else {
                    if(i==0 && j==0) dp[i][j]=1;
                    else {

                    int left=0,up=0;
                    if(j>0) left=dp[i][j-1];
                    if(i>0) up=dp[i-1][j];
                    dp[i][j]=left+up;
                    }
                }
            }
        }
        return dp[m-1][n-1];
    }
};

