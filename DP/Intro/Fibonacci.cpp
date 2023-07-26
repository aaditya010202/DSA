// coding ninjas
#include<bits/stdc++.h>
using namespace std;
//Memoization
// int fibo(int n, int *dp)
// {
//         if(n<=2) return 1;
//         if(dp[n]!=-1) return dp[n];
//         return dp[n]=fibo(n-1,dp)+fibo(n-2,dp);
// }
// int main()
// {
//         /*
//         *  Write your code here. 
//          *  Read input as specified in the question.
//          *  Print output as specified in the question.
//         */
//         int n;
//         cin>> n;
//         int dp[n+1];
//         memset(dp,-1,sizeof(dp));
//         cout<<fibo(n,dp);
//         return 0;
// }


//Tabulation
// int main()
// {
//         int n;
//         cin>> n;
//         int dp[n+1];
//         dp[0]=0;
//         dp[1]=1;
//         for(int i=2;i<=n;i++)
//         {
//                 dp[i]=dp[i-1]+dp[i-2];
//         }
//         cout<<dp[n];
//         return 0;
// }


//Tabulation with reduced space complexity
int main()
{
        int n;
        cin>> n;
        // int dp[n+1];
        int prev2=0;
        int prev=1;
        int curr=1;
        for(int i=2;i<=n;i++)
        {
                curr=prev+prev2;
                prev2=prev;
                prev=curr;
        }
        cout<<curr;
        return 0;
}