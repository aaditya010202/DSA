// Leetcode solution
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count=0;
        int prevCount=0;
        for(auto x:nums)
        {
            if(x==1) 
            {
                count++;
                if(prevCount<count) prevCount=count;
            }
            else 
            {
                count=0;                
            }
        }
        
        return prevCount;
    }
};