class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        // int temp;
        // for(int i=0;i<k;i++)
        // {
        //     for(int j=nums.size()-1;j>=0;j--)
        //     {
        //         if(j==nums.size()-1) temp=nums[j];

        //         else
        //         {
        //             nums[j+1]=nums[j];
        //             if(j==0) nums[j]=temp;
        //         }
        //     }
        // }

        k=k%nums.size();
        reverse(nums.begin(),nums.end()-k);
        reverse(nums.end()-k,nums.end());
        reverse(nums.begin(),nums.end());
    }
};