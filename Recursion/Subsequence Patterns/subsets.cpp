class Solution {

    private: 
    void solve(int n,int index, vector<vector<int>> &ans,vector<int> &nums, vector<int> &s)
    {
        if(index==n)
        {
            ans.push_back(s);
            return ;
        }

        s.push_back(nums[index]);
        solve(n,index+1,ans,nums,s);
        s.pop_back();
        solve(n,index+1,ans,nums,s);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        // RECURSIVE
        vector<vector<int>> ans;
        vector<int> s;
        solve(nums.size(),0,ans,nums,s);
        return ans;

        // ITERATIVE
        // int n=nums.size();
        // vector<vector<int>> ans;
        // for(int i=0;i<(1<<n);i++)//left shift gives us pow(2,n) so 1<<n is pow(2,n)
        // {
        //     vector<int> sub;
        //     for(int j=0;j<n;j++)
        //     {
        //         if((1<<j)&i){ sub.push_back(nums[j]);
        //         cout<<nums[j];
        //         }
        //     }
        //     cout<<endl;
        //     ans.push_back(sub);
            
        // }
        // return ans;
    }
};

