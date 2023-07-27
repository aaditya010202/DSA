// coding ninjas
#include <bits/stdc++.h> 

//RECURSION(Top to Down)
// int solve(int index, vector<int> &heights)
// {
//   if(index==0) return 0;

//   int left= solve(index-1,heights)+ abs(heights[index]-heights[index-1]);
//   int right=INT_MAX;
//   if(index>1)right=solve(index-2,heights)+abs(heights[index]-heights[index-2]);

//   return min(left,right);
// }
// int frogJump(int n, vector<int> &heights)
// {
//     return solve(n-1,heights);
// }


//MEMOIZATION(Top to Down)
// int solve(vector<int>& dp,int index, vector<int> &heights)
// {
//   if(index==0) return 0;
//   if(dp[index]!=-1) return dp[index];
//   int left= solve(dp,index-1,heights)+ abs(heights[index]-heights[index-1]);
//   int right=INT_MAX;
//   if(index>1)right=solve(dp,index-2,heights)+abs(heights[index]-heights[index-2]);

//   return dp[index]=min(left,right);
// }

// int frogJump(int n, vector<int> &heights)
// {
//     // Write your code here.
//     vector<int> dp(n+1,-1);
//     return solve(dp,n-1,heights);
// }


// TABULATION(Botton to Up)
// int frogJump(int n, vector<int> &heights)
// {
//     // Write your code here.
//     vector<int> dp(n,0);
//     dp[0]=0;//base case
//     for(int i=1;i<n;i++)
//     {
//       int left=dp[i-1]+abs(heights[i]-heights[i-1]);
//       int right=INT_MAX;
//       if(i>1)right=dp[i-2]+abs(heights[i]-heights[i-2]);
//       dp[i]=min(left,right);
//     }
//     return dp[n-1];
// }


//TABULATION WITH REDUCED SPACE
int frogJump(int n, vector<int> &heights)
{
    // Write your code here.
    int prev=0;
    int prev2=0;
    for(int i=1;i<n;i++)
    {
      int curr=heights[i];
      int left=prev+abs(heights[i]-heights[i-1]);
      int right=INT_MAX;
      if(i>1)right=prev2+abs(heights[i]-heights[i-2]);
      curr=min(left,right);

      prev2=prev;
      prev=curr;
    }
    return prev;
}