// leetcode
// RECUSION
// class Solution {
//     private: 
//     int solve(int n,int index, int buy, vector<int> &prices){
//         if(index==n) return 0;
//         int profit=0;
//         if(buy){
//             profit=max(-prices[index]+solve(n,index+1,0,prices),0+solve(n,index+1,1,prices));
//         }
//         else{
//             profit=max(prices[index]+solve(n, index+1, 1, prices), 0+solve(n, index+1, 0, prices));
//         }
//         return profit;
//     }
// public:
//     int maxProfit(vector<int>& prices) {
//         int n=prices.size();
//         return solve(n,0,1,prices);
//     }
// };

// MEMOIZATION
class Solution {
    private: 
    int solve(int n,int index, int buy, vector<int> &prices,vector<vector<int>> &dp){
        if(index==n) return 0;
        int profit=0;
        if(dp[index][buy]!=-1) return dp[index][buy];

        if(buy){
            profit=max(-prices[index]+solve(n,index+1,0,prices,dp),0+solve(n,index+1,1,prices,dp));
        }
        else{
            profit=max(prices[index]+solve(n, index+1, 1, prices,dp), 0+solve(n, index+1, 0, prices,dp));
        }
        return dp[index][buy]=profit;
    }
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n, vector<int>(2,-1));
        return solve(n,0,1,prices,dp);
    }
};

