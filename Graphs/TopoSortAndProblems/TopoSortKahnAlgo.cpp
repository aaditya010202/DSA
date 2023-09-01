// coding ninjas
#include<bits/stdc++.h>
vector<int> topologicalSort(vector<vector<int>> &graph, int edges, int nodes) {
    // Write your code here!
    vector<vector<int>> arr(nodes);
    vector<int> indegree(nodes,0);
    for(auto x: graph)
    {
        arr[x[0]].push_back(x[1]);
        indegree[x[1]]++;
    }

    queue<int> q;
    vector<int> ans;
    for(int i=0;i<nodes;i++)
    {
        if (indegree[i] == 0) {
          q.push(i);
        }
    }

    while(!q.empty())
    {
        int front=q.front();
        ans.push_back(front);
        q.pop();
        for(auto x: arr[front])
        {
            indegree[x]--;
            if(indegree[x]==0)
            {
                q.push(x);
            }
        }
    }
    return ans;

}

