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
    vector<int>prime(10000001,1);
    prime[0]=0;
    prime[1]=0;
    vector<ll>ponly;
    for(int i=2;1LL*i*i<10000001;i++)
    {
        if(prime[i]==0)continue;
        for(ll j=1LL*i*i;j<10000001;j+=i)
        {
            prime[j]=0;
        }
    }
    for(int i=0;i<10000001;i++)
    {
        if(prime[i])ponly.emplace_back(i);
    }
    int nn=ponly.size();
    for(int q=1;q<=t;q++)
    {
        ll n;
        cin>>n;
        ll ans=0;
        for(int i=1;i<=n;i++)
        {
            ll k=n/i;
            auto it=upper_bound(ponly.begin(),ponly.end(),k);
            ans+=it-ponly.begin();
        }
        cout<<ans<<endl;
    }
    return 0;
}