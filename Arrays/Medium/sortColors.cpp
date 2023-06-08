// leetcode solution
class Solution {
public:
    void sortColors(vector<int>& nums) {
    // Better solution
    // int count0=0,count1=0,count2=0;
    // for(int i:nums)
    // {
    //     if(i==0) count0++;
    //     else if(i==1) count1++;
    //     else count2++;
    // }
    // int j=0;
    // while(count0!=0)
    // {
    //     nums[j]=0;
    //     j++;
    //     count0--;
    // }
    // while(count1!=0)
    // {
    //     nums[j]=1;
    //     j++;
    //     count1--;
    // }
    // while(count2!=0)
    // {
    //     nums[j]=2;
    //     j++;
    //     count2--;
    // }


    // optimal solution 
    int low=0;
    int mid=0;
    int high=nums.size()-1;
    while(mid<=high)
    {
        if(nums[mid]==0)
        {
            swap(nums[low],nums[mid]);
            low++;
            mid++;
        }
        else if(nums[mid]==1)
        {
            mid++;
        }
        else
        {
            swap(nums[mid],nums[high]);
            high--;
        }
    }
    }
};