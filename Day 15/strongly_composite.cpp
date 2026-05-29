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
using ll=long long;
int main()  
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    vector<ll>prime(1e6+1,1);
    prime[0]=0;
    prime[1]=0;
    for(ll i=2;i<=1e6;i++)
    {
        if(prime[i]==0)continue;
        for(ll j=i*i;j<=1e6;j+=i)
        {
            prime[j]=0;
        }
    }
    vector<ll>vp;
    for(ll i=0;i<=1e6;i++)
    {
        if(prime[i]==1)vp.emplace_back(i);
    }
    for(ll q=1;q<=t;q++)
    {
        ll n;
        cin>>n;
        vector<ll>v(n);
        set<ll>pf;
        map<ll,ll>m;
        for(ll ii=0;ii<n;ii++)
        {
            cin>>v[ii];
            for(ll i=0;i<vp.size()&&vp[i]*vp[i]<=v[ii];i++)
            {
                if(v[ii]%vp[i]==0)
                {
                    for(ll j=0;v[ii]%vp[i]==0;j++)
                    {
                        v[ii]/=vp[i];
                        pf.insert(vp[i]);
                        m[vp[i]]+=1;
                    }
                }
            }
            if(v[ii]>1)
            {
                pf.insert(v[ii]);
                m[v[ii]]+=1;
            }
 
        }
        ll rem=0;
        ll ans=0;
        for(auto x:pf)
        {
            ans+=m[x]/2;
            rem+=m[x]%2;
        }
        ans+=rem/3;
        cout<<ans<<endl;
    }
    return 0;
}