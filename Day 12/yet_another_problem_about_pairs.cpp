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
#include <climits>
using namespace std;
using ll=long long;
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
        vector<pair<ll,ll>>noin;
        for(ll i=0;i<n;i++)
        {
            cin>>v[i];
            if(v[i]<i+1)noin.emplace_back(v[i],i+1);
        }
        sort(noin.begin(),noin.end());
        int nn=noin.size();
        ll ans=0;
        for(ll i=0;i<nn;i++)
        {
            auto it=upper_bound(noin.begin()+i+1,noin.end(),make_pair(noin[i].second,LLONG_MAX));
            ans+=noin.end()-it;
        }
        cout<<ans<<endl;
    }
    return 0;
}