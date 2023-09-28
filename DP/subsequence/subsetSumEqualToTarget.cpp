// coding ninjas
#include <bits/stdc++.h> 

// bool solve(int n, int k , vector<int> &arr){
//     if(k==0) return true;
//     if(n==0) return (arr[n]==k);

//     bool not_take=solve(n-1, k, arr);
//     bool take=false;
//     if(k>=arr[n])
//     {
//         take=solve(n-1,k-arr[n],arr);
//     }

//     return (take||not_take);
// }
// bool subsetSumToK(int n, int k, vector<int> &arr) {
//     // Write your code here.
    
//     return solve(n,k,arr);
    
// }


// MEMOIZATION
bool solve(int n, int k , vector<int> &arr, vector<vector<int>> &dp){
    if(k==0) return true;
    if(n==0) return (arr[n]==k);

    if(dp[n][k]!=-1) return dp[n][k];
    bool not_take=solve(n-1, k, arr,dp);
    bool take=false;
    if(k>=arr[n])
    {
        take=solve(n-1,k-arr[n],arr,dp);
    }

    return dp[n][k]=(take||not_take);
}
bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    // int dp[pow(10,3)+1][pow(10,3)+1]={-1};
    vector<vector<int>> dp(n+1, vector<int>(k+1,-1));
    return solve(n,k,arr,dp);
    
}
