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