// leetcode
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
     vector<int> ans;
     int low=0;
     int high=nums.size()-1;
     int floor=nums.size();
     while(low<=high)
     {
         int mid=((low+high)/2);
         if(nums[mid]>=target){
             floor=mid;
             high=mid-1;
         }
         else{
             low=mid+1;
         }
     }   

     int ceil=nums.size();
     low=0;
     high=nums.size()-1;
     while(low<=high)
     {
         int mid=((low+high)/2);
         if(nums[mid]>target){
             ceil=mid;
             high=mid-1;
         }
            else{
                low=mid+1;
            }
     }
     cout<<floor<<" "<<ceil;
     if(floor==nums.size() || nums[floor]!=target)
     {
        ans.push_back(-1);
        ans.push_back(-1);
        return ans;
     }
     ans.push_back(floor);
     ans.push_back(ceil-1);
     return ans;
    }
};