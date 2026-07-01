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
    int t;
    cin>>t;
    for(int q=1;q<=t;q++)
    {
        ini;
        vll p(n);
        vll d(n);
        forn(i,0,n)cin>>p[i];
        forn(i,0,n)cin>>d[i];
        vector<int>v(n,0);
        ll ans=0;
        for(int i=0;i<n;i++)
        {
            int now=d[i];
            int cur=0;
            if(p[now-1]==now&&v[now-1]==0)cur+=1;
            while(p[now-1]!=now)
            {
                int a=p[now-1];
                p[now-1]=now;
                v[now-1]=1;
                cur+=1;
                now=a;
            }
            ans+=cur;
            cout<<ans<<" ";
        }
        cout<<endl;
    }
    return 0;
}