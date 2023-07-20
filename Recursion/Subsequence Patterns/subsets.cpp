// leetcode
class Solution {

    private: 

    void subsets(vector<int>& nums, int i, vector<int>& sub, vector<vector<int>>& subs) {
        subs.push_back(sub);
        for (int j = i; j < nums.size(); j++) {
            sub.push_back(nums[j]);
            subsets(nums, j + 1, sub, subs);
            sub.pop_back();
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        // RECURSIVE

        vector<vector<int>> subs;
        vector<int> sub;
        subsets(nums, 0, sub, subs);
        return subs;

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

