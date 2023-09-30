// leetcode
// class Solution {
//     private:
//     int solve(vector<int>& coins, int target, int n){

//         if(n==0){
//             if(target%coins[n]==0) return target/coins[n];
//             return 1e9;
//         }

//         int not_take=0+solve(coins, target, n-1);
//         int take=1e9;
//         if(coins[n]<=target){
//             take=1+solve(coins, target-coins[n], n);
//         }

//         return min(take, not_take);
//     }
// public:
//     int coinChange(vector<int>& coins, int amount) {
//         int n=coins.size();
//         int ans=solve(coins, amount, n-1);
//         if(ans>=1e9) return -1;
//         return ans;
//     }
// };

// MEMIOZATION
class Solution {
    private:
    int solve(vector<int>& coins, int target, int n, vector<vector<int>> &dp){

        if(n==0){
            if(target%coins[n]==0) return target/coins[n];
            return 1e9;
        }
        if(dp[n][target]!=-1) return dp[n][target];
        int not_take=0+solve(coins, target, n-1,dp);
        int take=1e9;
        if(coins[n]<=target){
            take=1+solve(coins, target-coins[n], n,dp);
        }

        return dp[n][target]=min(take, not_take);
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, -1));
        int ans=solve(coins, amount, n-1,dp);
        if(ans>=1e9) return -1;
        return ans;
    }
};