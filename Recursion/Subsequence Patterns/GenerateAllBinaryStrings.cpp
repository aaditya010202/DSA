// coding ninjas
void solve(vector<string> &ans,string s, int K)
{
  if (K == 0) {
    ans.push_back(s);
    return;
  }
    if(s.back()=='0')
    {
        string s1=s;
        s1.push_back('0');
        string s2=s;
        s2.push_back('1');
        solve(ans,s1,K-1);
        solve(ans,s2,K-1);
    }
    else if(s.back()=='1')
    {
        string s3=s;
        s3.push_back('0');
        solve(ans,s3,K-1);
    }
}

vector<string> generateString(int N) {
    // Write your code here.
    vector<string> ans;
    string n1="0";
    string n2="1";
    solve(ans,n1,N-1);
    solve(ans,n2,N-1);
    return ans;
}