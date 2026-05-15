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
        ll n,x,y;
        cin>>n>>x>>y;
        vector<ll>v(n);
        map<ll,vector<ll>>my;
        for(int i=0;i<n;i++)
        {
            cin>>v[i];
            ll mody=v[i]%y;
            my[mody].emplace_back(v[i]);
        }
        ll ans=0;
        for(auto p:my)
        {
            vector<ll>cur=p.second;
            map<ll,ll>mx;
            for(int j=0;j<cur.size();j++)
            {
                cur[j]=cur[j]%x;
                mx[cur[j]]++;
            }
            set<ll>done;
            for(auto it:mx)
            {
                ll r=it.first;
                if(done.count(r))
                continue;
                ll need=(x-r)%x;
                if(r==need)
                {
                    ans+=it.second*(it.second-1)/2;
                }
                else
                {
                    ans+=it.second*mx[need];
                }
                done.insert(r);
                done.insert(need);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}