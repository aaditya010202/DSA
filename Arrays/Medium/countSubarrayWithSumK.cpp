// leetcode
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

        int count=0;
        int curSum=0;
        unordered_map<int,int> m;
        m[0]=1;
        for(int i=0;i<nums.size();i++)
        {
            curSum+=nums[i];
            int left=curSum-k;
            if(m.find(left)!=m.end()) count+=m[left];
            m[curSum]++;
        }
        return count;
    }
};