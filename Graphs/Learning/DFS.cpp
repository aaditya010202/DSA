// coding  ninjas
vector<int> solve(int node, vector<vector<int>> &arr, vector<bool> &vis, vector<int> &temp)
{
    vis[node]=1;
    temp.push_back(node);

    for(auto x: arr[node])
    {
        if(!vis[x])
        {
            solve(x,arr,vis,temp);
        }
    }
    return temp;
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    // Write your code here
    vector<vector<int>> arr(V);
    vector<bool> vis(V,0);
    vector<vector<int>> dfs;
    for(auto x: edges)
    {
        arr[x[0]].push_back(x[1]);
        arr[x[1]].push_back(x[0]);
    }

    for(auto x: arr)
    {
        sort(x.begin(), x.end());
    }

    stack<int> s;
    
    
    for(int i=0;i<V;i++)
    {
        if(!vis[i])
        {
            vector<int> temp;
            dfs.push_back(solve(i,arr,vis,temp));
        }
            
    }
    return dfs;
}


// GFG
// class Solution {
//     private:
//     void solve(int node, vector<int> adj[], vector<int> &dfs, vector<bool> &vis)
//     {
//         vis[node]=1;
//         dfs.push_back(node);
//         for(auto x: adj[node])
//         {
//             if(!vis[x])
//             {
//                 solve(x,adj,dfs,vis);
//             }
//         }
//     }
//   public:
//     // Function to return a list containing the DFS traversal of the graph.
//     vector<int> dfsOfGraph(int V, vector<int> adj[]) {
//         // Code here
    
//         vector<bool> vis(V,0);
//         vector<int> dfs;
        
//         solve(0,adj,dfs,vis);
//         return dfs;
        
//     }
// };