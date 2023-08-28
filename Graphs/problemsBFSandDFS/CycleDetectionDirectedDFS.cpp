// coding ninjas
bool dfs(vector<vector<int>> &arr,vector<int>&vis, vector<int> &pathVis, int node )
{
	vis[node]=1;
	pathVis[node]=1;
	for(auto x: arr[node])
	{
          if (!vis[x]) {
            if(dfs(arr, vis, pathVis, x)) return true;
          }
		  else if(pathVis[x]) return true;
        }
	pathVis[node]=0;
	return false;
}
bool isCyclic(vector<vector<int>>& edges, int v, int e)
{
	// Write your code here
	vector<vector<int>> arr(v);
	vector<int> vis(v,0);
	vector<int> pathVis(v,0);
	for(auto x: edges)
	{

		arr[x[0]].push_back(x[1]);
	}
	for(int i=0;i<v;i++)
	{
		if(!vis[i])
		{
			if(dfs(arr,vis,pathVis,i)==true) return true;
		}
	}
	return false;
}
