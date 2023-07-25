// leetcode
class Solution {
    private:
    void solve(vector<int> &arr, int k, int n, vector<vector<int>> &ans, vector<int> &s, int index)
    {
        if(s.size()>k) return;
        int sum=accumulate(s.begin(),s.end(),0);
        if(sum> n) return;
        if(index>=arr.size())
        {
            if(sum==n && s.size()==k)ans.push_back(s);
            return;
        }

        s.push_back(arr[index]);
        solve(arr,k,n,ans,s,index+1);
        s.pop_back();
        solve(arr,k,n,ans,s,index+1);
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> arr{1,2,3,4,5,6,7,8,9};
        vector<vector<int>> ans;
        vector<int> s;
        solve(arr,k,n,ans,s,0);
        return ans;
    }
};