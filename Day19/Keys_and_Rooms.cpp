class Solution 
{
public:
    void dfs(int a,vector<bool>&visited,vector<vector<int>>& adj)
    {
        for(auto x:adj[a])
        {
            if(visited[x])continue;
            else
            {                    
                visited[x]=true;
                dfs(x,visited,adj);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>&rooms) 
    {
        int n=rooms.size();
        vector<vector<int>>adj(n);
        vector<bool>visited(n,false);
        for(int i=0;i<n;i++)
        {
            visited[i]=false;
            int nn=rooms[i].size();
            for(int j=0;j<nn;j++)
            {
                adj[i].emplace_back(rooms[i][j]);
            }
        }
        visited[0]=true;
        dfs(0,visited,adj);
        int ans=0;
        for(auto x:visited)
        {
            if(x==true)ans+=1;
        }
        if(ans==n)return true;
        return false;


    }
};