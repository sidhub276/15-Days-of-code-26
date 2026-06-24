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
        ll n,k;
        cin>>n>>k;
        vll v(n);
        forn(i,0,n)cin>>v[i];
        int ans=0;
        ll bac=k/2;
        ll fro=k-bac;
        for(ll i=0;i<n&&fro>0;i++)
        {
            if(fro>=v[i])
            {
                fro-=v[i];
                ans+=1;
                v[i]=0;
            }
            else
            {
                v[i]-=fro;
                fro=0;
            }
        }
        for(ll i=n-1;i>=0&&bac>0;i--)
        {
            if(v[i]==0)break;
            if(v[i]<=bac)
            {
                bac-=v[i];
                v[i]=0;
                ans+=1;
            }
            else
            {
                break;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}