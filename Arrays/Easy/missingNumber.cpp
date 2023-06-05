// Leetcode solution
class Solution {
public:
    int missingNumber(vector<int>& nums) 
    {
        // my solution
        // int n=nums.size();
        // sort(nums.begin(),nums.end());
        // int i;
        // for(i=0;i<n;i++)
        // {
        //     if(nums[i]!=i)return i;
        // }

        // return i;

        // fastest solution
        int n=nums.size();
        int sum=(n*(n+1))/2;
        for( auto x: nums) sum=sum-x;
        return sum;
    }
};