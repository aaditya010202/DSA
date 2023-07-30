// leetcode
//RECURSION
// class Solution {
//     private:
//     int solve(int m, int n, int row, int col)
//     {
//         if(row<0) return 0;
//         if(col<0) return 0;
//         if(row==0 && col==0) return 1;
//         int left=solve(m,n,row,col-1);
//         int up=solve(m,n,row-1,col);
//         return left+up;
//     }
// public:
//     int uniquePaths(int m, int n) {
//         if(m==1 & n==1) return 1;
//         return solve(m,n,m-1,n-1);
//     }
// };


//MEMOIZATION
// class Solution {
//     private:
//     int solve(int m, int n, int row, int col, vector<vector<int>> &dp)
//     {
//         if(row<0) return 0;
//         if(col<0) return 0;
//         if(dp[row][col]!=-1) return dp[row][col];
//         if(row==0 && col==0) return 1;
//         int left=solve(m,n,row,col-1,dp);
//         int up=solve(m,n,row-1,col,dp);
//         return dp[row][col]=left+up;
//     }
// public:
//     int uniquePaths(int m, int n) {
//         if(m==1 & n==1) return 1;
//         vector<vector<int>> dp(m,vector<int> (n,-1));
//         return solve(m,n,m-1,n-1,dp);
//     }
// };


// TABULATION
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int> (n,-1));

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==0 && j==0) dp[0][0]=1;
                else{

                int up=0,left=0;
                if(j>0) left=dp[i][j-1];
                if(i>0) up=dp[i-1][j];
                dp[i][j]=left+up;
                }
            }
        }
        return dp[m-1][n-1];
    }
};
