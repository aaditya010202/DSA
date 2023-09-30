// coding ninjas
// BFS
// #include <bits/stdc++.h> 
// int MOD=1e9+7;
// int solve(int n, int d , vector<int> & arr, int target){
//     if(n==0){
//         if(target==0 && arr[n]==0) return 2; //if the 0th element is 0 then we have 2 options either take it or not take it both will work
//         if(target==0 || arr[n]==target) return 1;
//         return 0;
//     }

//     int not_take=solve(n-1,d,arr,target);
//     int take=0;
//     if(arr[n]<=target){
//         take=solve(n-1,d,arr,target-arr[n]);
//     }

//     return (take+not_take)%MOD;
// }
// int countPartitions(int n, int d, vector<int> &arr) {
//     // Write your code here.

//     int sum= accumulate(arr.begin(), arr.end(), 0);
//     if((sum-d)%2!=0 || sum-d<0 ) return 0;
//     int target=(sum-d)/2;

//     return solve(n-1,d,arr,target);
// }

// MEMIOZATION
#include <bits/stdc++.h> 
int MOD=1e9+7;
int solve(int n, int d , vector<int> & arr, int target, vector<vector<int>> &dp){
    if(n==0){
        if(target==0 && arr[n]==0) return 2; //if the 0th element is 0 then we have 2 options either take it or not take it both will work
        if(target==0 || arr[n]==target) return 1;
        return 0;
    }
    if(dp[n][target]!=-1) return dp[n][target];
    int not_take=solve(n-1,d,arr,target,dp);
    int take=0;
    if(arr[n]<=target){
        take=solve(n-1,d,arr,target-arr[n],dp);
    }

    return dp[n][target]=(take+not_take)%MOD;
}
int countPartitions(int n, int d, vector<int> &arr) {
    // Write your code here.

    int sum= accumulate(arr.begin(), arr.end(), 0);
    if((sum-d)%2!=0 || sum-d<0 ) return 0;
    int target=(sum-d)/2;
    vector<vector<int>> dp(n, vector<int>(target+1, -1));
    return solve(n-1,d,arr,target,dp);
}


