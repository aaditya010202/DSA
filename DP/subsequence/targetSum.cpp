// leetcode
// MEMOIZATION
class Solution {
    private:
    int solve(vector<int> & nums, int target, int n, vector<vector<int>> &dp){
        if(n==0){
            if(nums[n]==0 && target==0) return 2;
            if(nums[n]==target || target==0) return 1;
            return 0;
        }
        if(dp[n][target]!=-1) return dp[n][target];
        int not_take=solve(nums, target, n-1,dp);
        int take=0;
        if(nums[n]<=target){
            take=solve(nums, target-nums[n], n-1,dp);
        }
        return dp[n][target]=take+not_take;
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int sum=accumulate(nums.begin(), nums.end(),0);
        int t=(sum-target)/2;
        if(sum-target<0 || (sum-target)%2!=0 || abs(target)>sum) return 0;
        vector<vector<int>> dp(n, vector<int> (t+1, -1));
        return solve(nums, t, n-1, dp);
    }
};