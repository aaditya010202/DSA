// leetcode
class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int mini=prices[0];
        int ans=0,cost;

        for(int i=1;i<prices.size();i++)
        {
            cost=prices[i]-mini;
            ans=max(cost,ans);
            mini=min(mini,prices[i]);
        }
        
        return ans;
    }
};