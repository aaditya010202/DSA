// coding ninjas
class Graph {
private:
    bool isCyclic(vector<int> adj[], int node, int vis[])
    {
         
        vis[node] = 1;
        queue<pair<int, int>> q;
        q.push({node, -1});
        while (!q.empty())
        {
            int front = q.front().first;
            int parent = q.front().second;
            q.pop();
            for (auto x : adj[front])
            {
                if (!vis[x])
                {
                    vis[x]=1;
                    q.push({x, front});
                }
                
                else if (x != parent)
                {
                    return true;
                }
            }
        }
        return false;
    }

public:
    bool detectCycle(int V, vector<int> adj[]) {
        int vis[V] = {0};
        for(int i = 0;i<V;i++) {
            if(!vis[i]) {
                if(isCyclic( adj,i, vis)) return true; 
            }
        }
        return false; 
    }
};


