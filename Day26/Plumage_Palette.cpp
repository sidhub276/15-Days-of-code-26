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
    int n,m;
    cin>>n>>m;
    vector<pair<int,pair<int,int>>>v(n);
    set<int>s;
    map<int,int>mp;
    forn(i,0,n)
    {
        int a,b,c;
        cin>>a>>b>>c;
        v[i].first=b;
        v[i].second.first=a;
        v[i].second.second=c;
        s.insert(a);
        mp[a]+=1;
    }
    sort(v.begin(),v.end());
    int fir=v[0].first;
    for(int i=1;i<fir;i++)
    {
        cout<<s.size()<<endl;
    }
    int dytopri=fir;
    int lastday=v.back().first;
    for(int i=0;i<n;i++)
    {
        mp[v[i].second.first]-=1;
        if(mp[v[i].second.first]==0)s.erase(v[i].second.first);
        mp[v[i].second.second]+=1;
        s.insert(v[i].second.second);
        if(i==n-1)
        {
            forn(j,dytopri,m+1)cout<<s.size()<<endl;
            continue;
        }
        if(v[i+1].first==dytopri)continue;
        for(int j=dytopri;j<v[i+1].first;j++)
        {
            cout<<s.size()<<endl;
        }
        dytopri=v[i+1].first;
    }
    return 0;
}