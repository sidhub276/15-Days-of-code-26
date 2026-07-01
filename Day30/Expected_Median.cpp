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

constexpr int N=1000005;
constexpr int PRIME=1000000007;

ll pw(ll a,ll b,ll m)
{
    if(b==0)return 1%m;
    if(b%2==0)
    {
        ll t=pw(a,b/2,m);
        return (1ll*t*t%m);
    }
    else{
        ll t=pw(a,(b-1)/2,m);
        t=(1ll*t*t)%m;
        return(1ll*a*t%m);
    }
}

ll fact[N],inv_fact[N];

void init()
{
    ll p=PRIME;
    fact[0]=1;
    ll i;
    for(i=1;i<N;i++)
    {
        fact[i]=(1ll*fact[i-1]*i)%p;
    }
    i--;
    inv_fact[i]=pw(fact[i],p-2,p);
    for(--i;i>=0;i--)
    {
        inv_fact[i]=inv_fact[i+1]*(i+1)%p;
    }
}

ll ncr(ll n,ll r)
{
    if(r>n||n<0||r<0)return 0;
    else return fact[n]*inv_fact[r]%PRIME*inv_fact[n-r]%PRIME;
}

int main()  
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    init();
    int t;
    cin>>t;
    for(int q=1;q<=t;q++)
    {
        ini;
        ll k;
        cin>>k;
        vll v(n);
        ll n1=0,n0=0;
        forn(i,0,n)
        {
            cin>>v[i];
            n1+=v[i];
        }
        n0=n-n1;
        ll ans=0;
        for(int i=0;i<=k/2;i++)
        {
            if(n0<i)break;
            ans+=ncr(n0,i)*ncr(n1,k-i);
            ans%=PRIME;
        }
        cout<<ans<<endl;
    }
    return 0;
}