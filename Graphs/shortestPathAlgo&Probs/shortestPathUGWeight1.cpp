// coding  ninjas
vector<int> shortestPath(int n, vector<vector<int>>&edges, int src) {
    // Write your code here.
    vector<vector<int>> arr(n);
    for(auto x: edges)
    {
        arr[x[0]].push_back(x[1]);
        arr[x[1]].push_back(x[0]);
    }

    queue<pair<int,int>> q;
    q.push({src,0});
    vector<int> vis(n,0);
    vector<int> ans(n,INT_MAX);
    while(!q.empty())
    {
        int node=q.front().first;
        int dist=q.front().second;
        q.pop();
        vis[node]=1;
        ans[node]=min(ans[node],dist);
        for(auto x: arr[node])
        {
            if(!vis[x])
            {
                q.push({x,dist+1});
            }
        }
    }

    for(int i=0;i<n;i++)
    {
        if(ans[i]==INT_MAX)ans[i]=-1;
    }
    return ans;

}