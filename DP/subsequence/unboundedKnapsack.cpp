// coding  ninjas
#include<bits/stdc++.h>
int steal(int n, int w, vector<int> & profit, vector<int> &weight, vector<vector<int>> &dp)
{
    if(n==0 || w==0){
        if(weight[n]<=w) return (w/weight[n])*profit[n];
        return 0;
    }

    if(dp[n][w]!=-1) return dp[n][w];

    int not_pick=steal(n-1, w, profit, weight, dp);
    int pick=INT_MIN;

    if(weight[n]<=w){
        pick=profit[n]+steal(n,w-weight[n],profit, weight, dp);
    }
    
    return dp[n][w]=max(pick, not_pick);

}
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){
    // Write Your Code Here.

    vector<vector<int>> dp(n+1, vector<int> (w+1, -1));
    return steal(n-1, w, profit, weight, dp);

}

