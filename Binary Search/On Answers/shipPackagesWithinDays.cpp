// leetcode
class Solution {
    private:
    int daysPossible(vector<int>& weights, int capacity)
    {
        int sum=0;
        int day=1;
        for(int i=0;i<weights.size();i++)
        {
            if(sum+weights[i]>capacity)
            {
                day+=1;
                sum=weights[i];
            }
            else{
                sum+=weights[i];
            }
        }
        return day;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low=*max_element(weights.begin(),weights.end());
        int high=accumulate(weights.begin(),weights.end(),0);//first index, second index, initial value of sum
        int ans=INT_MAX;
        while(low<=high)
        {
            int mid=((low+high)/2);
            if(daysPossible(weights,mid)<=days){
                ans=min(ans,mid);
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};