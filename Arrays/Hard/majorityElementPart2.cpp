// leetcode
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        // vector<int> ans;
        // int n=nums.size();
        // map<int,int> m;
        // for(auto x: nums)
        // {
        //     m[x]++;
        // }

        // for(auto x: m)
        // {
        //     if(x.second>n/3)ans.push_back(x.first);
        // }
        // return ans;


        // optimal solution
        int n=nums.size();
        vector<int> ans;
        int count1=0,count2=0;
        int el1=INT_MIN,el2=INT_MIN;

        for(int x:nums)
        {
            if(count1==0 &&el2!=x )
            {
                count1=1;
                el1=x;
            }
            else if(count2==0 &&el1!=x)
            {
                count2=1;
                el2=x;   
            }
            else if(el1==x) count1++;
            else if(el2==x) count2++;
            else{
                count1--;
                count2--;
            }
            
        }

        int c1=0,c2=0;
        for(int x:nums){
            if(el1==x) c1++;
            else if(el2==x) c2++;
        }
        if(c1>n/3) ans.push_back(el1);
        if(c2>n/3) ans.push_back(el2);
        return ans;
    }
};