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
int main()  
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int>adj[200001];
    vector<bool>visited(200001,false);
    adj[1].emplace_back(0);
    adj[1].emplace_back(2);
    for(int i=2;i<200001;i++)
    {
        adj[i].emplace_back(i-1);
        adj[i].emplace_back(2*i);
    }
    int n,m;
    cin>>n>>m;
    queue<pair<int,int>>q;
    if(n==m)
    {
        cout<<"0"<<endl;
        return 0;
    }
    q.push(make_pair((int)0,n));
    visited[n]=true;
    while(!q.empty())
    {
        int cnt=q.front().first;
        int num=q.front().second;
        q.pop();
        for(auto x:adj[num])
        {
            if(x==m)
            {
                cout<<cnt+1<<endl;
                return 0;
            }
            if(x>0&&x<200001&&visited[x]==false)
            {
                q.push(make_pair((int)cnt+1,x));
                visited[x]=true;
            }
        }
    }
    return 0;
}