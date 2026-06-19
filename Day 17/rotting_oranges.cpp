class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        bool visited[11][11];
        auto valid=[&](int x,int y)
        {
            if(x<0||x>=n||y<0||y>=m||visited[x][y]==true||grid[x][y]==0)return false;
            else return true;
        };
        int dx[]={1,0,-1,0};
        int dy[]={0,-1,0,1};
        int all=0;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1||grid[i][j]==2)all+=1;
                visited[i][j]=false;
            }
        }
        int done=0;
        queue<pair<int,pair<int,int>>>q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==2)
                {
                    visited[i][j]=true;
                    done+=1;
                    q.push(make_pair(0,make_pair(i,j)));
                }
            }
        }
        while(!q.empty())
        {
            int dis=q.front().first;
            ans=max(dis,ans);
            int x=q.front().second.first;
            int y=q.front().second.second;
            q.pop();
            for(int i=0;i<4;i++)
            {
                int X=x+dx[i];
                int Y=y+dy[i];
                if(valid(X,Y)==true)
                {
                    done+=1;
                    q.push(make_pair(dis+1,make_pair(X,Y)));
                    visited[X][Y]=true;
                }
            }
        }
        if(done<all)return -1;
        else return ans;
    }
};