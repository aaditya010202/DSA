// leetcode

class Solution {
    private:
    int splits(vector<int>& nums, int sum)
    {
        int split=1;
        long long s=0;
        for(int i=0;i<nums.size();i++)
        {
            if(s+nums[i]<=sum)
            {
                s+=nums[i];
            }
            else{
                s=nums[i];
                split++;
            }
        }
        return split;
    }
public:
    int splitArray(vector<int>& nums, int k) {
     int low=*max_element(nums.begin(),nums.end());
     int high=accumulate(nums.begin(),nums.end(),0);
     while(low<=high)
     {
         int mid=((low+high)/2);
         if(splits(nums,mid)>k) low=mid+1;
         else high=mid-1;
     }   
     return low;
    }
};