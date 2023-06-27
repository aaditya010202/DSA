// leetcode
class Solution {
    private:
    long long time(vector<int>& piles, int hourly)
    {
        long long hours=0;
        for(int x: piles)
        {
            hours+=ceil((double)x/(double)hourly);
        }
        return hours;
    }
    
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1;
        int high=*max_element(piles.begin(),piles.end());
        int ans=INT_MAX;
        while(low<=high)
        {
            int mid=((low+high)/2);
            if(time(piles,mid)<=h)
            {
                ans=min(ans,mid);
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
    return ans;
    }
};