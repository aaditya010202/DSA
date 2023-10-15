// leetcode
// CANNOT PASS 1 CASE MEMOIZATION
// class Solution {
//     private:
//     int solve(string text1, string text2, int ind1, int ind2, vector<vector<int>> &dp){
//         if(ind1<0 || ind2<0) return 0;

//         if(dp[ind1][ind2]!= -1) return dp[ind1][ind2];
//         if(text1[ind1]==text2[ind2]) return dp[ind1][ind2]=1+solve(text1, text2, ind1-1, ind2-1, dp);

//         return dp[ind1][ind2]=0+max(solve(text1, text2, ind1-1, ind2, dp), solve(text1, text2, ind1, ind2-1,dp));
//     }
// public:
//     int longestCommonSubsequence(string text1, string text2) {
//         int ind1= text1.size()-1;
//         int ind2=text2.size()-1;
//         vector<vector<int>> dp(ind1+1, vector<int>(ind2+1,-1) );
//         return solve(text1, text2, ind1, ind2,dp);
//     }
// };

// TABULATION
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.length();
        int n = text2.length();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (text1[i - 1] == text2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        return dp[m][n];
    }
};
