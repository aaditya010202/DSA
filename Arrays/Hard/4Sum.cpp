// leetcode
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans; 
        sort(nums.begin(),nums.end());
        int n=nums.size();
        for(int i=0;i<n;i++)
        { if(i>0 && nums[i]==nums[i-1]) continue;
            for(int j=n-1;j>i;j--)
            {
                if(j<n-1 && nums[j]==nums[j+1]) continue;
                int k=i+1;
                int l=j-1;
                while(k<l)
                {
                    long long sum=(long long)(nums[i])+nums[j]+nums[k]+nums[l];
                    if(sum<target) k++;
                    else if(sum>target) l--;
                    else{
                        vector<int> temp={nums[i],nums[k],nums[l],nums[j]};
                        ans.push_back(temp);
                        k++;
                        l--;
                        while(k<l && nums[k]==nums[k-1]) k++;
                        while(k<l && nums[l]==nums[l+1]) l--;
                    }
                }
            }
        }
        return ans;
    }
};