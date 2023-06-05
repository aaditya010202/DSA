// Leetcode solution
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // contant space O(1)
        sort(nums.begin(),nums.end());
        for(int i=1;i<nums.size();i=i+2)
        {
            if(nums[i]!=nums[i-1]) return nums[i-1];
        }
        return nums[nums.size()-1];
        
        
        
        //Using map does not take constant space 

        // map<int,int> m;
        // int n=nums.size();

        // for(int i=0;i<n;i++)
        // {
        //     m[nums[i]]++;
        // }        

        // for(auto x:m)
        // {
        //     if(x.second==1) return x.first;
        // }
        // return -1;        
    }
};