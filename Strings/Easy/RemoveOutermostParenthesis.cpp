// leetcode
class Solution {
public:
    string removeOuterParentheses(string s) {
        int n=s.length();
        string ans;
        int count=0;
        int j=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(')
            {
                if(count==0)count++;
                else
                {
                    count++;
                    ans.push_back(s[i]);
                }
            }
            else
            {
                if(count==1)
                {
                    count--;
                }
                else
                {
                    count--;
                    ans.push_back(s[i]);
                }
            }
        }
        return ans;
    }
};