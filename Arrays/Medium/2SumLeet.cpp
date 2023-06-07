class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> final;
        for(int i=0;i<nums.size();i++){
           final.push_back(i);
           for(int j=0;j<nums.size();j++){
               if(i==j)continue;
               else if(nums[final[0]]+nums[j]==target) {
                   final.push_back(j);
                   return final;
               }
           }
           final.pop_back();
        }  
        return final; 
    }
};