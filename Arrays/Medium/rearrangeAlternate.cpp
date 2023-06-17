// leetcode
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> ans(nums.size());
        int pos=0,neg=1;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>0)
            {
                ans[pos]=nums[i];
                pos+=2;
            }
            else
            {
                ans[neg]=nums[i];
                neg+=2;
            }
        }
        return ans;
    }
};


// GFG
//User function template for C++
class Solution{
public:

	void rearrange(int arr[], int n) {
	    // code here
	    int pos=0;
	    int neg=1;
	    int ans[n];
	    for(int i=0;i<n;i++)
	    {
	        if(arr[i]>=0)
	        {
	            ans[pos]=arr[i];
	            pos+=2;
	            
	        }
	        else
	        {
	            ans[neg]=arr[i];
	            neg+=2;
	        }
	    }
	    
	    for(int i=0;i<n;i++)
	    {
	        arr[i]==ans[i];
	    }
	}
};