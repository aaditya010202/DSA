// leetcode
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int s1=s.size();

        string rev="";
        for(int i=s1-1; i>=0; i--){
            rev+=s[i];
        }
        
        int s2=rev.size();
        vector<vector<int>> dp(s1+1, vector<int>(s2+1, 0));

        for(int i=1;i<=s1;i++){
            for(int j=1;j<=s2;j++){
                if(s[i-1]==rev[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
                }
            }
        }

        int len=dp[s1][s2];
        // int i=s1;
        // int j=s2;
        // string ans(len, ' ');
        // while(i>0 && j>0){
        //     if(s[i]==rev[j]){
        //         ans+=s[i];
        //     }
        //     else if(dp[i-1][j]>dp[i][j-1]){
        //         i--;
        //     }
        //     else{
        //         j--;
        //     }
        // }
        return len;
    }
};