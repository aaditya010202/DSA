// leetcode
class Solution {
    private: 
    void dfs(int n, int m, int row, int col, vector<vector<int>> &vis, vector<vector<char>>& board)
    {
        vis[row][col]=1;
        int drow[]={-1,1,0,0};
        int dcol[]={0,0,-1,1};
        for(int i=0;i<4;i++)
        {
            int r=row+drow[i];
            int c=col+dcol[i];
            if(r<n && r>=0 && c<m && c>=0 && vis[r][c]==0 && board[r][c]=='O')
            {
                dfs(n,m,r,c,vis,board);
            }
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>> vis(n, vector<int> (m, 0));

        for(int i=0;i<n;i++)
        {
            if(board[i][0]=='O') dfs(n,m,i,0,vis, board);
            if(board[i][m-1]=='O') dfs(n,m,i,m-1,vis, board);
        }
        for(int i=0;i<m;i++)
        {
            if(board[0][i]=='O') dfs(n,m,0,i,vis,board);
            if(board[n-1][i]=='O') dfs(n,m,n-1,i,vis,board);
        }
        
        for(int i=1;i<n-1;i++)
        {
            for(int j=1;j<m-1;j++)
            {
                if(vis[i][j]==0)
                {
                    board[i][j]='X';
                }
            }
        }
    }
};