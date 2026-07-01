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
        vll v(n),pos(n),neg(n);
        forn(i,0,n)cin>>v[i];
        ll p=0;
        for(int i=0;i<n;i++)
        {
            if(v[i]>0)p+=v[i];
            pos[i]=p;
        }
        ll ne=0;
        for(int i=n-1;i>=0;i--)
        {
            if(v[i]<0)ne+=(-1*v[i]);
            neg[i]=ne;
        }
        ll ans=0;
        for(int i=0;i<n;i++)
        {
            ans=max(ans,pos[i]+neg[i]);
        }
        cout<<ans<<endl;
    }
    return 0;
}