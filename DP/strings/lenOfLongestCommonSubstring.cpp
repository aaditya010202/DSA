// coding ninjas
#include<bits/stdc++.h>

// TABULATION
int lcs(string &str1, string &str2){
    // Write your code here.
    int s1=str1.size();
    int s2=str2.size();

    vector<vector<int>> dp(s1+1, vector<int>(s2+1, 0));
    int ans=INT_MIN;

    for(int i=1;i<=s1;i++){
        for(int j=1;j<=s2;j++){
            if(str1[i-1]==str2[j-1])
            {
                dp[i][j]=1+dp[i-1][j-1];
                ans=max(ans, dp[i][j]);
            }
            else
            {
                dp[i][j]=0;
            }
        }
    }
    return ans;
}

// SPACE OPTIMIZATION
// int lcs(string &str1, string &str2){
//     // Write your code here.
//     int s1=str1.size();
//     int s2=str2.size();

//     vector<int> cur(s2+1, 0), prev(s2+1, 0);
//     int ans=INT_MIN;

//     for(int i=1;i<=s1;i++){
//         for(int j=1;j<=s2;j++){
//             if(str1[i-1]==str2[j-1])
//             {
//                 cur[j]=1+prev[j-1];
//                 ans=max(ans, cur[j]);
//             }
//             else
//             {
//                 cur[j]=0;
//             }
//         }
//         prev=cur;
//     }
//     return ans;
// }