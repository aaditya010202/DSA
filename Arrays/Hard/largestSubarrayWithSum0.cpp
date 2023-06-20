// Gfg 

class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        // Your code here
        int sum=0,max_len=0;
        unordered_map<int,int> m;
        for(int i=0;i<n;i++)
        {
            sum+=A[i];
            if(sum==0)
            {
                max_len=i+1;
            }
            else
            {
                if(m.find(sum)!=m.end())
                {
                    max_len=max((i-m[sum]),max_len);
                }
                else 
                m[sum]=i;
            }
        }
        return max_len;
    }
};