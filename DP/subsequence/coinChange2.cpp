// leetcode
class Solution {
    private:
    int solve(int target, vector<int>&coins, int n, vector<vector<int>>& dp)
    {
        if(target==0) return 1;
        // if(n<=0){
        //     if(coins[n]==target) return 1;
        //     return 0;
        // }
        if (n < 0 || target < 0) {
            return 0; // Invalid combinations.
        }
        if(dp[n][target]!=-1) return dp[n][target];

        int not_take=solve(target, coins, n-1, dp);
        int take=0;
        if(coins[n]<=target){
            take=solve(target-coins[n], coins, n,dp);
        }

        return dp[n][target]=take+not_take;
    }
public:
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, -1));
        return solve(amount, coins, n-1, dp);
    }
};


