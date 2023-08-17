// leetcode
class Solution {
    private:
    void dfs(int n, int m, int row, int col, vector<vector<int>> &vis, vector<vector<int>> &grid)
    {
        vis[row][col]=1;
        int drow[]={-1,1,0,0};
        int dcol[]={0,0,1,-1};

        for(int i=0;i<4;i++)
        {
            int r=row+drow[i];
            int c=col+dcol[i];
            if(r<n && r>=0 && c<m && c>=0 && vis[r][c]==0 && grid[r][c]==1)
            {
                dfs(n,m,r,c,vis,grid);
            }
        }
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n, vector<int> (m,0));

        for(int i=0;i<n;i++)
        {
            if(grid[i][0]==1) dfs(n,m,i,0,vis,grid);
            if(grid[i][m-1]==1) dfs(n,m,i,m-1,vis,grid);
        }

        for(int i=0;i<m;i++)
        {
            if(grid[0][i]==1) dfs(n,m,0,i,vis,grid);
            if(grid[n-1][i]==1) dfs(n,m,n-1,i,vis,grid);
        }
        int count=0;
        for(int i=1;i<n-1;i++)
        {
            for(int j=1;j<m-1;j++)
            {
                if(vis[i][j]==0 && grid[i][j]==1) count++;
            }
        }
        return count;
    }
};