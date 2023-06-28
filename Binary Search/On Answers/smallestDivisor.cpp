// leetcode
class Solution {
    private:
    int possible(vector<int>& nums, int divisor)
    {
        int n=nums.size();
        int count=0;
        for(int i=0;i<n;i++)
        {
            count+=ceil(nums[i]/(double)divisor);
        }
        return count;
    }
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low=1;
        int high=*max_element(nums.begin(),nums.end());
        int ans=INT_MAX;
        while(low<=high)
        {
            int mid=((low+high)/2);
            if(possible(nums,mid)<=threshold)
            {
                ans=min(ans,mid);
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        if(ans==INT_MAX) return -1;
        return ans;
    }
};