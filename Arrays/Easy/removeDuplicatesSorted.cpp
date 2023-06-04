// Leetcode solution
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // my solution
        // map<int,int> mpp;
        // int n=nums.size();

        // for(int i=0;i<n;i++)
        // {
        //     mpp[nums[i]]++;
        // }

        //     int i=0;
        //     for(auto x:mpp)
        //     {

        //         nums[i]=x.first;
        //         i++;
        //     }
        //     return mpp.size();
        
        // Other solution
        int i=0;
        for(int j=1;j<nums.size();j++) 
        {
            if(nums[i]!=nums[j])
            {
                i++; 
                nums[i]=nums[j];
            }
        }
        return i+1;
    }
};