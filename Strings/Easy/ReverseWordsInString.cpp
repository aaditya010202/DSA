// leetcode
class Solution {
public:
    string reverseWords(string s) {
    int n=s.length();
    stack<string> st;

    for(int i=0;i<n;i++)
    {
        while(s[i]==' ' && i<n) i++;
        string word;
        while(s[i]!=' ' && i<n)
        {
            word+=s[i];
            i++;
        }
        st.push(word);
    }
    string ans;
    while(!st.empty())
    {
        if(ans=="")
        {
            ans=st.top();
            st.pop();
        }
        else 
        {
            ans=ans+' '+st.top();
            st.pop();
        }
    }    
    return ans;
    }
};