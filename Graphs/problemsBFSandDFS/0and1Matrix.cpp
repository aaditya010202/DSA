
// leetcode
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();

        vector<vector<int>> vis(n, vector<int> (m,0));
        vector<vector<int>> dist(n, vector<int> (m,0));
        queue<pair<pair<int,int>, int>> q;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]==0)
                {
                    q.push({{i,j},0});
                    vis[i][j]=1;
                }
                else 
                {
                    vis[i][j]=0;
                }
            }
        }

        while(!q.empty())
        {
            int r=q.front().first.first;
            int c=q.front().first.second;
            int d=q.front().second;
            dist[r][c]=d;
            q.pop();
            int drow[]={-1,+1,0,0};
            int dcol[]={0,0,-1,+1};

            for(int i=0;i<4;i++)
            {
                int row=r+drow[i];
                int col=c+dcol[i];
                if(row<n && row>=0 && col<m && col>=0 && vis[row][col]==0 && mat[row][col]==1)
                {
                    vis[row][col]=1;
                    q.push({{row,col}, d+1});
                }
            }
        }

        return dist;
    }
};