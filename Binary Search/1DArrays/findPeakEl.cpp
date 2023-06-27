// leetcode
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return 0;
        if(nums[0]>nums[1]) return 0;
        if(nums[n-1]>nums[n-2]) return n-1;
        int low=1;
        int high=n-2;
        int ans=INT_MIN;

        while(low<=high)
        {
            int mid=((low+high)/2);
            if(nums[mid]>=nums[mid-1] && nums[mid]>=nums[mid+1]) {
                return mid;
            }
            else if(nums[mid-1]<=nums[mid])//increasing slope on the left so eliminate left
            {
                low=mid+1;
            }
            else if(nums[mid]>nums[mid+1])//decreasing slope on the right so eliminate right
            {
                high=mid-1;
            }
            else//if both the sides of mid has a peak then go to either of the side
            {
                low=mid+1;
            }
        }
        return -1;
    }
};