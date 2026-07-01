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
        vll v(n);
        forn(i,0,n)cin>>v[i];
        ll mini=0;
        ll maxi=1e9;
        int k=1;
        for(int i=1;i<n;i++)
        {
            if(v[i]==v[i-1])continue;
            if(v[i]>v[i-1])maxi=min(v[i-1]+(v[i]-v[i-1])/2,maxi);
            else mini=max(mini,v[i]+(abs(v[i]-v[i-1])+1)/2);
            if(maxi<mini)
            {
                k=0;
                break;
            }
        }
        if(k==0)cout<<"-1"<<endl;
        else cout<<mini<<endl;
    }
    return 0;
}