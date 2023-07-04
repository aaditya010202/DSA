// leetcode
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // MY SOLUTION
        // string ans;
        // int n=strs.size();
        // if(n==0) return "";
        // ans=strs[0];
        // for(int i=1;i<n;i++)
        // {
        //     int j=0;
        //     while(strs[i][j]==ans[j] && j<strs[i].length())
        //     {
        //         j++;
        //     }
        //     ans=strs[i].substr(0,j);
        // }
        // return ans;

        // OPTIMAL
        string ans;
        sort(strs.begin(),strs.end());
        int n=strs.size();
        string first=strs[0];
        string last=strs[n-1];
        for(int i=0;i<min(first.length(),last.length());i++)
        {
            if(first[i]==last[i])ans=ans+first[i];
            else return ans;
        }
        return ans;
    }
};