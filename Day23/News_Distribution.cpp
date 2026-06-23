#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <string>
#include <queue>
#include <stack>
#include <unordered_map>
using namespace std;
#define ll long long
#define vll vector<ll>
#define pll pair<ll,ll>
#define vpll vector<pair<ll,ll>>
#define endl "\n"
#define forn(i,a,b) for(int i=(int)a;i<(int)b;i++)
#define ini ll n; cin>>n;
#define all(v) v.begin(),v.end()
#define sp " "
#define vout(v) forn(i,0,v.size()) cout<<v[i]<<(i==v.size()-1?endl:sp)
int n,m;
vector<int>adj[500001];
vector<bool>visited(500001,false);
void dfs(int i,vector<int>&cur)
{
    for(auto x:adj[i])
    {
        if(visited[x])continue;
        cur.emplace_back(x);
        visited[x]=true;
        dfs(x,cur);
    }
}
int main()  
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;
    forn(i,0,m)
    {
        int nn;
        cin>>nn;
        if(nn==0)continue;
        vector<int>v(nn);
        for(int i=0;i<nn;i++)
        {
            cin>>v[i];
        }
        for(int j=1;j<nn;j++)
        {
            adj[v[0]].emplace_back(v[j]);
            adj[v[j]].emplace_back(v[0]);
        }
    }
    map<int,int>mp;
    for(int i=1;i<=n;i++)
    {
        if(visited[i])continue;
        vector<int>cur;
        cur.emplace_back(i);
        visited[i]=true;
        dfs(i,cur);
        visited[i]=true;
        int num=cur.size();
        for(int i=0;i<num;i++)
        {
            mp[cur[i]]=num;
        }
    }
    for(int i=1;i<=n;i++)
    {
        cout<<mp[i]<<" ";
    }
    cout<<endl;
    return 0;
}