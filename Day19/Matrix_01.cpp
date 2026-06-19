class Solution {
public:
    bool valid(int x,int y,int n,int m,vector<vector<bool>>&visited)
    {
        if(x<0||x>=n||y<0||y>=m||visited[x][y]==true)return false;
        return true;
    }
    vector<vector<int>>updateMatrix(vector<vector<int>>& mat) 
    {
        int m=mat.size();
        int n=mat[0].size();
        swap(n,m);
        vector<vector<int>>ans(n,vector<int>(m,0));
        vector<vector<bool>>visited(n,vector<bool>(m,false));
        int dx[]={1,0,-1,0};
        int dy[]={0,1,0,-1};
        queue<pair<int,pair<int,int>>>q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]==0)
                {
                    ans[i][j]=0;
                    visited[i][j]=true;
                    q.push(make_pair(0,make_pair(i,j)));
                }

            }
        }
        while(!q.empty())
        {
            int dis=q.front().first;
            int x=q.front().second.first;
            int y=q.front().second.second;
            q.pop();
            for(int i=0;i<4;i++)
            {
                int X=x+dx[i];
                int Y=y+dy[i];
                if(valid(X,Y,n,m,visited))
                {
                    q.push(make_pair(dis+1,make_pair(X,Y)));
                    visited[X][Y]=true;
                    ans[X][Y]=dis+1;
                }
            }
        }
        return ans;
    }
};