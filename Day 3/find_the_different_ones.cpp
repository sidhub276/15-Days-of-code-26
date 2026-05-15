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
    int t;
    cin>>t;
    for(int qq=1;qq<=t;qq++)
    {
        ll n;
        cin>>n;
        vector<ll>v(n);
        for(ll i=0;i<n;i++)cin>>v[i];
        vector<ll>sd(n,0);
        for(ll i=0;i<n-1;i++)
        {
            if(v[i]!=v[i+1])sd[i+1]=1;
        }
        vector<ll>sds(n,0);
        ll x=0;
        for(ll i=0;i<n;i++)
        {
            x+=sd[i];
            sds[i]=x;
        }
        ll q;
        cin>>q;
        for(int i=0;i<q;i++)
        {
            ll l,r;
            cin>>l>>r;
            if(sds[l-1]==sds[r-1])
            {
                cout<<"-1 -1"<<endl;
            }
            else
            {
                ll a=sds[l-1];
                auto it=upper_bound(sds.begin()+l-1,sds.begin()+r-1,a);
                int ans=it-sds.begin();
                cout<<ans<<" "<<ans+1<<endl;
            }
        }
    }
    return 0;
}