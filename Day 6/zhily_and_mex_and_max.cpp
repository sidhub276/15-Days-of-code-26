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
    for(int q=1;q<=t;q++)
    {
        ll n;
        cin>>n;
        vector<ll>v(n);
        ll ans=0;
        vector<ll>a(n,-1);
        ll maxi=0;
        map<ll,ll>mp;
        set<ll>s;
        for(ll i=0;i<n;i++)
        {
            cin>>v[i];
            maxi=max(v[i],maxi);
            mp[v[i]]+=1;
            s.insert(v[i]);
        }
        a[0]=maxi;
        s.erase(maxi);
        mp[maxi]-=1;
        int j=1;
        for(auto x:s)
        {
            a[j]=x;
            j++;
            mp[x]-=1;
        }
        for(auto x:mp)
        {
            if(x.second>0)
            for(int i=0;i<x.second;i++)
            {
                a[j]=x.first;
                j+=1;
            }
        }
        ans+=n*maxi;
        ll mex=0;
        vector<ll>fre(n+1,0);
        for(int i=0;i<n;i++)
        {
            if(a[i]<=n)fre[a[i]]+=1;
            while(fre[mex]>0)mex+=1;
            ans+=mex;
        }
        cout<<ans<<endl;
    }
    return 0;
}