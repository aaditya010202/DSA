// leetcode
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0) return 0;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int count=0;
        int last=INT_MIN;
        int longest=1;
        for(int i=0;i<n;i++)
        {
            if(nums[i]-1==last)
            {
                count++;
                last=nums[i];
            }
            else if(nums[i]!=last)
            {
                count=1;   
                last=nums[i];             
            }
            longest=max(longest,count);
        }
        return longest;


        // optimal 
        // unordered_set<int> s;
        // int n=nums.size();
        // if(n==0) return 0;
        
        // int count=0;
        // int longest=INT_MIN;

        // for(int i=0;i<nums.size();i++)
        // {
        //     s.insert(nums[i]);
        // }

        // for(auto x:s)
        // {
        //     if(s.find(x-1)==s.end())
        //     {
        //         count=1;
        //         x=x+1;
        //         while(s.find(x)!=s.end())
        //         {
        //             count++;
        //             x=x+1;
        //         }
        //         longest=max(longest,count);
        //     }
        // }
        // return longest;

    }
};