// GFG
// Function to find square root
// x: element to find square root
class Solution{
  public:
    long long int floorSqrt(long long int x) 
    {
        // Your code goes here   
        long long low=1;
        long long high=x;
        long long ans=INT_MIN;
        while(low<=high)
        {
            long long mid=(low+high)/2;
            if(mid*mid==x) return mid;
            else if(mid*mid<x) 
            {
                ans=max(mid,ans);
                low=mid+1;
            }
            else 
            {
                high=mid-1;
            }
        }
        return ans;
    }
};