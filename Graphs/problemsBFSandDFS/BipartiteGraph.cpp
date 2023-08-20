// coding ninjas
#include<bits/stdc++.h>
bool bfs(vector<vector<int>> &edge,int node, vector<int> &color)
{
	color[node]=0;
	queue<int> q;
	q.push(node);
	while(!q.empty())
	{
		int front=q.front();
		q.pop();
		for(auto x: edge[front])
		{
			if(color[x]==-1)
			{
				q.push(x);
				color[x]=!color[front];				
			}
			else if(color[x]==color[front]) return false;
		}
	}
	return true;
}

bool isGraphBirpatite(vector<vector<int>> &edges) {
	// Write your code here.
	int n=edges.size();
	
	vector<vector<int>> edge(n);
	for(int i=0;i<edges.size();i++)
	{
		for(int j=0;j<edges[0].size();j++)
		{
			if(edges[i][j]==1)
			{
				edge[i].push_back(j);
			}
		}
	}

	vector<int> color(n,-1);
	
	for(int i=0;i<n;i++)
	{
		if(color[i]==-1)
		{
			if(bfs(edge,i,color)==false) return false;
		}
	}
	return true;
}