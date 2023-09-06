// coding ninjas
vector<int> shortestPathInDAG(int n, int m, vector<vector<int>> &edges)
{
    // Write your code here
    vector<int> indegree(n,0);
    vector<vector<pair<int,int>>> arr(n);
    for(auto x: edges)
    {
        arr[x[0]].push_back({x[1],x[2]});
        indegree[x[1]]++;
    }

    // queue<int> q;
    // for(int i=0;i<n;i++)
    // {
    //     if(indegree[i]==0) q.push(i);
    // }

    // stack<int> st;
    // while(!q.empty())
    // {
    //     int node=q.front();
    //     st.push(node);
    //     q.pop();
    //     for(auto x: arr[node])
    //     {
    //         indegree[x.first]--;
    //         if(indegree[x.first]==0)
    //         {
    //             q.push(x.first);
    //         }
    //     }
    // }

    // vector<int> dis(n, INT_MAX);
    
    // dis[0]=0;

    // while(!st.empty())
    // {
    //     int node=st.top();
    //     st.pop();
    //     for(auto x: arr[node])        
    //     {
    //         int v=x.first;
    //         int dist=x.second;

    //         if(dist+dis[node]<dis[v])
    //         {
    //             dis[v]=dis[node]+dist;
    //         }
    //     }
    // }

    // for(int i=0;i<n;i++)
    // {
    //     if(dis[i]==INT_MAX) dis[i]=-1;
    // }
    // return dis; 

    queue<pair<int,int>> q;
    vector<int> dis(n, INT_MAX);
    q.push({0,0});
    dis[0]=0;
    while(!q.empty())
    {
        int node=q.front().first;
        int dist=q.front().second;
        q.pop();
        for(auto x: arr[node])
        {
            int v=x.first;
            int w=x.second;
            if(dist+w<dis[v])
            {
                dis[v]=dist+w;
                q.push({v,dist+w});
            }
        }
    }

    for(int i=0;i<n;i++)
    {
        if(dis[i]==INT_MAX) dis[i]=-1;

    }
    return dis;

}
