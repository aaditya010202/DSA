// GFG
class Solution {
    
private: 
    bool possible(vector<int>& stalls, int dis,int k)
    {
        int n=stalls.size();
        int last=stalls[0];
        int cow=1;
        for(int i=0;i<n;i++)
        {
            if(stalls[i]-last>=dis)
            {
                cow++;
                last=stalls[i];
            }
            
        if(cow>=k) return true;
        }
        return false;
    }
    
public:

    int solve(int n, int k, vector<int> &stalls) {
        // Write your code here
        sort(stalls.begin(),stalls.end());
        int low=1;
        int high=stalls[stalls.size()-1]-stalls[0];
        int ans=INT_MIN;
        while(low<=high)
        {
            int mid=((low+high)/2);
            if(possible(stalls,mid,k)==true)
            {
                ans=mid;
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }
        return ans;
        //OR return high;
    }
};