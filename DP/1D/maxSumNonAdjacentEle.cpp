// coding  ninjas
#include <bits/stdc++.h> 

// RECURSION
// int solve(vector<int> &nums, int index)
// {
//     if(index==0) return nums[0];
//     else if(index<=0) return 0;
//     int pick=nums[index]+solve(nums,index-2);
//     int not_pick=0+solve(nums,index-1);

//     return max(pick,not_pick);
// }
// int maximumNonAdjacentSum(vector<int> &nums){
//     // Write your code here.
//     return solve(nums,nums.size()-1);
// }


//MEMOIZATION
// int solve(vector<int>& dp,vector<int> &nums, int index)
// {
//     if(index==0) return nums[0];
//     else if(index<=0) return 0;
//     if(dp[index]!=-1) return dp[index];
//     int pick=nums[index]+solve(dp,nums,index-2);
//     int not_pick=0+solve(dp,nums,index-1);

//     return dp[index]=max(pick,not_pick);
// }
// int maximumNonAdjacentSum(vector<int> &nums){
//     // Write your code here.
//     vector<int> dp(nums.size(),-1);
//     return solve(dp,nums,nums.size()-1);
// }


//TABULATION
// int maximumNonAdjacentSum(vector<int> &nums)
// {
//     int n=nums.size();
//     vector<int> dp(n,0);
//     dp[0]=nums[0];
//     for(int i=1;i<nums.size();i++)
//     {
//         int pick=nums[i];
//         if(i>1) pick+=dp[i-2];
//         int not_pick=0+dp[i-1];

//         dp[i]=max(pick,not_pick);
//     }
//     return dp[n-1];
// }


//TABULATION SPACE OPTIMIZATION
int maximumNonAdjacentSum(vector<int> &nums)
{
    int n=nums.size();
    // vector<int> dp(n,0);
    int prev=nums[0];
    int prev2=0;
    int curr;
    for(int i=1;i<nums.size();i++)
    {
        int pick=nums[i];
        if(i>1) pick+=prev2;
        int not_pick=0+prev;

        curr=max(pick,not_pick);

        prev2=prev;
        prev=curr;
    }
    return prev;
}