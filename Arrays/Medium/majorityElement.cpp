// leetcode solution
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // Better solution
        // map<int,int> m;
        // for(auto x:nums)
        // {
        //     m[x]++;
        // }
        // for(auto i:m)
        // {
        //     if(i.second>nums.size()/2) return i.first;
        // }
        // return -1;


        // optimal solution
        int el;
        int count=0;
        for(int i=0;i<nums.size();i++)
        {
            if(count==0)
            {
                el=nums[i];
                count++;
            }
            else
            {
                if(el==nums[i])count++;
                else count--;
            }
        }
        return el;
    }
};