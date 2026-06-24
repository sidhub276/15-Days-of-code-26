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
        ll n,m,k;
        cin>>n>>m>>k;
        vll v(n);
        forn(i,0,n)cin>>v[i];
        sort(all(v));
        ll done=0;
        ll ans=0;
        for(ll i=0;i<n&&k>0;i++)
        {
            if(k>=m)
            {
                ans+=(done+v[i])*m;
                k-=m;
                done+=m;
            }
            else
            {
                ans+=(done+v[i])*k;
                k=0;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}