// leetcode
class Solution {
    bool solve(int n, int target, vector<int> &nums, vector<vector<int>> &dp, vector<int> &first, vector<int> &vis){
        if(n==0) return(nums[n]==target);
        if(target==0) return true;
        if(dp[n][target]!=-1) return dp[n][target];
        int not_take=solve(n-1, target, nums, dp,first, vis);
        int take=false;
        if(nums[n]<=target){
            first.push_back(nums[n]);
            vis[n]=1;
            take=solve(n-1, target-nums[n],nums, dp, first, vis);
            first.pop_back();
            vis[n]=-1;
        }
        return dp[n][target] = take || not_take;
    }
public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=accumulate(nums.begin(),nums.end(),0);
        if(sum%2!=0) return false;
        int target=sum/2;

        vector<int> vis(n,-1);
        vector<vector<int>> dp(n+1, vector<int>(target+1,-1));
        vector<int> first;

        if(solve(n-1,target,nums,dp, first,vis)==false) return false;
        // int sum2=0;
        // for(int i=0;i<n;i++){
        //     if(!vis[i]){
        //         sum2+=nums[i];
        //     }
        // }
        // if(sum2=target) return true;
        // return false;

        return true;
    }
};