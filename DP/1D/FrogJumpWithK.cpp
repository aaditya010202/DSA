// coding ninjas
// RECURSION
// int solve(int n, int k, vector<int> &heights)
// {
//     if(n==0) return 0;
//     int min_energy=INT_MAX;
//     for(int j=1;j<=k;j++)
//     {
//         // int jump=INT_MAX;
//         if (n - j >= 0) {
//           int jump = solve(n - j, k, heights) + abs(heights[n] - heights[n - j]);
//           min_energy = min(min_energy, jump);
//         }
//     }
//     return min_energy;

// }

// int minimizeCost(int n, int k, vector<int> &height){
//     // Write your code here.
//     return solve(n-1,k,height);

// }

// MEMOIZATION
// int solve(vector<int> &dp,int n, int k, vector<int> &heights)
// {
//     if(n==0) return 0;
//     if(dp[n]!=-1) return dp[n];

//     int min_energy=INT_MAX;
//     for(int j=1;j<=k;j++)
//     {
//         // int jump=INT_MAX;
//         if (n - j >= 0) {
//           int jump = solve(dp,n - j, k, heights) + abs(heights[n] - heights[n - j]);
//           min_energy = min(min_energy, jump);
//         }
//     }
//     return dp[n]=min_energy;

// }

// int minimizeCost(int n, int k, vector<int> &height){
//     // Write your code here.
//     vector<int> dp(n+1,-1);
//     return solve(dp,n-1,k,height);

// }


//TABULATION
int minimizeCost(int n, int k, vector<int> &height){
    // Write your code here.
    vector<int> dp(n,-1);
    dp[0]=0;
    for(int i=1;i<n;i++)
    {
        int min_energy=INT_MAX;
        
        for(int j=1;j<=k;j++)
        {
            if(i-j>=0)
            {
                int jump=dp[i-j]+abs(height[i]-height[i-j]);
                min_energy=min(min_energy,jump);
            }
        }
        dp[i]=min_energy;
    }
    return dp[n-1];
}

