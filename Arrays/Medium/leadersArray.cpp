// GFG
class Solution{
    //Function to find the leaders in the array.
    public:
    vector<int> leaders(int a[], int n){
        // Code here
        vector<int> ans;
        int m=INT_MIN;
        for(int i=n-1;i>=0;i--)
        {
            
            if(a[i]>=m)
            {
                ans.push_back(a[i]);
            }
                m=max(m,a[i]);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};