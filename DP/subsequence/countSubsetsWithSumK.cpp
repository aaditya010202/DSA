// coding ninjas
#include<bits/stdc++.h>
const int MOD = 1e9 + 7;
int solve(vector<int> &arr, int k, int n, vector<vector<int>> &dp){
	if(k==0) {
		return 1;
	}
	if(n==0){
		return arr[n]==k?1:0;
	}

	if(dp[n][k]!=-1) return dp[n][k];

	int	not_take=solve(arr, k, n-1, dp);
	int take=0;
	if(arr[n]<=k)
	{
		take=solve(arr, k-arr[n], n-1, dp);
	}

	return dp[n][k]=(take+not_take)%MOD;
}


int findWays(vector<int>& arr, int k)
{
	// Write your code here.
	int n=arr.size();
	vector<vector<int>> dp(n, vector<int>(k+1,-1));
	return solve(arr, k, n-1, dp);


}


