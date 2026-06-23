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
        int n;
        cin>>n;
        vector<int>v(n);
        map<int,int>m;
        forn(i,0,n)
        {
            cin>>v[i];
            m[v[i]]+=1;
        }
        vector<int>fre;
        for(auto x:m)fre.emplace_back(x.second);
        sort(fre.rbegin(),fre.rend());
        ll ans=0;
        int now=fre[0];
        for(auto x:fre)
        {
            if(now<=x)
            {
                ans+=now;
                now-=1;
            }
            else if(now>x)
            {
                ans+=x;
                now=x-1;
            }
            if(now<=0)break;
        }
        cout<<ans<<endl;
    }
    return 0;
}