// leetcode
class Solution {
    private:
    void solve(vector<int> &nums, set<vector<int>> &ans, vector<int> &s, int index)
    {
        if(index>=nums.size())
        {
            ans.insert(s);
            return ;
        }

        s.push_back(nums[index]);
        solve(nums,ans,s,index+1);
        s.pop_back();
        solve(nums,ans,s,index+1);
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        set<vector<int>> ans;
        vector<int> s;
        solve(nums,ans,s,0);
        vector<vector<int>> ans1;
        for(auto x: ans)
        {
            ans1.push_back(x);
        }
        return ans1;
    }
};