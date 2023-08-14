// leetcode
class Solution {
    private: 
    void dfs(int node, vector<bool> &vis, vector<vector<int>> &arr)
    {
        vis[node]=1;
        
        for(auto x: arr[node])
        {
            if(!vis[x])
            {
                dfs(x,vis,arr);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<vector<int>> arr(isConnected.size());
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i!=j && isConnected[i][j]==1)
                {
                    arr[i].push_back(j);
                    arr[j].push_back(i);
                }
            }
        }

        vector<bool> vis(n,0);
        int count=0;
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {   
                count++;
                dfs(i,vis, arr);
            }
        }
        return count;
    }
};