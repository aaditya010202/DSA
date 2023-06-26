class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        // Brute force solution
        // int n=nums.size();
        // if(n==1) return nums[0];
        // for(int i=0;i<n;i++)
        // {
        //     if(i==0)
        //     {
        //         if(nums[i+1]!=nums[i]) return nums[i];
        //     }
        //     else if(i==n-1)
        //     {
        //         if(nums[i-1]!=nums[i]) return nums[i];
        //     }
        //     else
        //     {
        //         if(nums[i-1]!=nums[i] && nums[i]!=nums[i+1]) return nums[i];
        //     }
        // }
        // return -1;


        // OPTIMAL SOLUTION
        // index is (even,odd) then the element is present on the right side
        // if (odd, even ) then the element is present on the left side
        int n=nums.size();
        int low=1;
        int high=n-2;
        if(n==1) return nums[0];
        if(nums[0]!=nums[1]) return nums[0];
        if(nums[n-1]!=nums[n-2]) return nums[n-1];
        while(low<=high)
        {
            int mid=((low+high)/2);
            if(nums[mid-1]!=nums[mid] && nums[mid]!=nums[mid+1]) return nums[mid];
            if(mid%2==1)
            {
                if(nums[mid-1]==nums[mid])
                {
                    low=mid+1;
                }
                else
                {
                    high=mid-1;
                }
            }
            else
            {
                if(nums[mid-1]==nums[mid]) 
                {
                    high=mid-1;
                }
                else
                {
                    low=mid+1;
                }
            }
        } 
        return -1;
    }
};