// leetcode
class Solution {
public:
    int maxDepth(string s) {
        int n=s.length();
        int count=0;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(') 
            {
             count++;
             ans=max(ans,count);   
            }
            else if(s[i]==')')
            {
                 count--;
                 if(count<0) return -1;
            }
        }
        return ans;
    }
};
