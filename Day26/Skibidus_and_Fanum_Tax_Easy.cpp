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
        ll n,m;
        cin>>n>>m;
        vll a(n),b(m);
        forn(i,0,n)cin>>a[i];
        forn(i,0,m)cin>>b[i];
        sort(all(b));
        int k=1;
        auto itt=lower_bound(b.begin(),b.end(),2*a[0]);
        if(itt!=b.begin())
        {
            a[0]=b[0]-a[0];
        }
        forn(i,1,n)
        {
            ll o1=1e18;
            if(a[i]>=a[i-1]) 
            {
                o1=a[i];
            }
            ll o2=1e18;
            auto it=lower_bound(b.begin(),b.end(),a[i-1]+a[i]);
            if(it!=b.end()) 
            {
                o2=*it-a[i];
            }
            ll b=min(o1,o2);
            if(b==1e18) 
            {
                k=0;
                break;
            } else 
            {
                a[i]=b;
            }
        }
        if(k)cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}