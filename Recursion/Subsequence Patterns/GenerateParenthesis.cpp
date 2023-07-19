// leetcode
class Solution {
    private:
    void solve(vector<string> &ans, int open, int close, string s)
    {
        if(open==0 && close==0)
        {
            ans.push_back(s);
            return ;
        }
        if(open==close)
        {
            string s1=s;
            s1.push_back('(');
            solve(ans,open-1,close,s1);
        }
        else if(open==0)
        {
            string s2=s;
            s2.push_back(')');
            solve(ans,open,close-1,s2);
        }
        else
        {
            string s3=s;
            string s4=s;
            s3.push_back('(');
            s4.push_back(')');
            solve(ans,open-1,close,s3);
            solve(ans,open,close-1,s4);
        }
    }    
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        int open=n;
        int close=n;
        string s="";
        solve(ans,open,close,s);
        return ans;
    }
};