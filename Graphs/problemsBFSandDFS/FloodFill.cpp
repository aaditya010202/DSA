// leetcode
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n=image.size();
        int m=image[0].size();
        vector<vector<bool>> vis(n, vector<bool> (m,false));

        queue<pair<int,int>> q;
        q.push({sr,sc});

        vis[sr][sc]=true;
        int startColor=image[sr][sc];
        image[sr][sc]=color;
        int drow[]={-1,+1,0,0};
        int dcol[]={0,0,-1,+1};
        
        while(!q.empty())
        {
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            for(int i=0;i<4;i++)
            {
                int row=r+drow[i];
                int col=c+dcol[i];
                if(row<n && row>=0 && col<m && col>=0 && image[row][col]==startColor && !vis[row][col])
                {
                    image[row][col]=color;
                    vis[row][col]=true;
                    q.push({row, col});
                }
            }
        }
        return image;
    }
};
