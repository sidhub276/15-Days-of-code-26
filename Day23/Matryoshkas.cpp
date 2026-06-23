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
    ll t;
    cin>>t;
    for(ll q=1;q<=t;q++)
    {
        ll n;
        cin>>n;
        vector<ll>v(n);
        map<ll,ll>m;
        for (ll i=0;i<n;i++)
        {
            cin>>v[i];
            m[v[i]]++;
        }
        ll ans=0;
        ll k=0;
        ll last=-1;
        ll curo=0;
        for(auto x:m)
        {
            if(k==0)
            {
                last=x.first;
                curo=x.second;
                ans+=curo;
                k=1;
                continue;
            }
            else if(last+1==x.first)
            {
                if(x.second==curo)
                {
                    last+=1;
                }
                else if(x.second<curo)
                {
                    last+=1;
                    curo=x.second;
                }
                else
                {
                    last+=1;
                    ans+=x.second-curo;
                    curo+=x.second-curo;
                }
            }
            else
            {
                last=x.first;
                curo=x.second;
                ans+=curo;
            }
        }
        cout<<ans<<endl;
        
    }
    return 0;
}