// coding ninjas
void traverse(int i, vector<int> arr[], vector<int> &vis)
{
    vis[i]=1;
    for(auto x: arr[i])
    {
        if(!vis[x])
        {
            traverse(x,arr,vis);
        }
    }
}
int findNumOfProvinces(vector<vector<int>>& roads, int n) {
    // Write your code here.
    vector<int> arr[n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i!=j && roads[i][j]==1)  arr[i].push_back(j);
        }
    }

    vector<int> vis(n,0);
    int count=0;

    for(int i=0;i< n;i++)
    {
        if(!vis[i])
        {
            traverse(i,arr,vis);
            count++;
        }
    }

    return count;
}

