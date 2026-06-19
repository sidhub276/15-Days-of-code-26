class Solution {
public:
    int n,m;
    bool visited[301][301];
    int ans=0;
    int dx[4]={1,0,-1,0};
    int dy[4]={0,-1,0,1};
    bool valid(int x,int y,vector<vector<int>>&grid)
    {
        if(x<0||x>=n||y<0||y>=m||grid[x][y]==0||visited[x][y]==true)return false;
        return true;
    }
    int dfs(int x,int y,vector<vector<int>>& grid)
    {
        int cur=1;
        for(int i=0;i<4;i++)
        {
            int X=x+dx[i];
            int Y=y+dy[i];
            if(valid(X,Y,grid)==true)
            {
                visited[X][Y]=true;
                cur+=dfs(X,Y,grid);
            }
        }
        return cur;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid)
    {
        n=grid.size();
        m=grid[0].size();
        ans=0;
        int maxi=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                visited[i][j]=false;
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(valid(i,j,grid)==true)
                {
                    ans+=1;
                    visited[i][j]=true;
                    maxi=max(dfs(i,j,grid),maxi);
                }
            }
        }
        return maxi;
    }
};