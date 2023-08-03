// leetcode

class Solution {

    // RECURSION
//     private:
//     int solve(vector<vector<int>> &matrix, int row, int col)
//     {
     
//         if(col<0 || col>=matrix.size()) return INT_MAX;
//         if(row==0) return matrix[0][col];
//         int up,left_diag,right_diag;
        
//         if(row>0){

//         up=solve(matrix, row-1, col);
//         if(col>0) left_diag=solve(matrix, row-1, col-1);
//         else left_diag=INT_MAX;
//         right_diag=solve(matrix,row-1,col+1);

//         }

//         return matrix[row][col]+min(up,min(left_diag,right_diag));
//     }
// public:
//     int minFallingPathSum(vector<vector<int>>& matrix) {
//         int r=matrix.size();
//         int c=matrix[0].size();
//         int ans=INT_MAX;
//         for(int i=0;i<c;i++)
//         {
//             ans=min(ans,solve(matrix,r-1,i));             
//         }
//         return ans;
//     }


// MEMOIZATION
//     private:
//     int solve(vector<vector<int>> &matrix, int row, int col,vector<vector<int>> &dp)
//     {
//         if(col<0 || col>=matrix.size()) return INT_MAX;
//         if(row==0) return matrix[0][col];
//         if(dp[row][col]!=-1) return dp[row][col];

//         int up,left_diag,right_diag;
        
//         up=solve(matrix, row-1, col,dp);
//         left_diag=solve(matrix, row-1, col-1,dp);
//         right_diag=solve(matrix,row-1,col+1,dp);

//         return dp[row][col]=matrix[row][col]+min(up,min(left_diag,right_diag));
//     }
// public:
//     int minFallingPathSum(vector<vector<int>>& matrix) {
//         int r=matrix.size();
//         int c=matrix[0].size();
//         int ans=INT_MAX;
//         vector<vector<int>> dp(r, vector<int> (c,-1));
//         for(int i=0;i<c;i++)
//         {
//             ans=min(ans,solve(matrix,r-1,i,dp));   
//         }
//         return ans;
//     }


// TABULATION
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int r=matrix.size();
        int c=matrix[0].size();
        vector<vector<int>> dp(r, vector<int> (c,0));
        for (int i = 0; i < c; i++) {
            dp[0][i] = matrix[0][i];
        }
        for(int j=1;j<r;j++)
        {
            for(int k=0;k<c;k++)
            {
                int down, left_diag, right_diag;
                down=matrix[j][k]+dp[j-1][k];
                if(k-1>=0) left_diag=matrix[j][k]+dp[j-1][k-1];
                else left_diag=INT_MAX;
                if(k+1<c) right_diag=matrix[j][k]+dp[j-1][k+1];
                else right_diag=INT_MAX;
                dp[j][k]=min(down, min(left_diag, right_diag));
            }
        }   

        int ans=INT_MAX;
        for(int i=0;i<c;i++)
        {
            ans=min(ans,dp[r-1][i]);
        }
        return ans;
    }
};