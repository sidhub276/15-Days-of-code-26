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
        ll n,k;
        cin>>n>>k;
        vector<ll>v(n);
        map<ll,ll>m;
        set<ll>s;
        for(ll i=0;i<n;i++)
        {
            cin>>v[i];
            m[v[i]]++;
            s.insert(v[i]);
        }
        sort(v.begin(),v.end());
        ll last=(*s.begin())-1;
        ll curl=0;
        ll cur=0;
        vector<ll>all;
        for(auto x:s)
        {
            if(x==last+1&&curl<k)
            {
                cur+=m[x];
                curl+=1;
                all.emplace_back(cur);
            }
            else if(x==last+1)
            {
                cur-=m[x-k];
                cur+=m[x];
                all.emplace_back(cur);
            }
            else
            {
                curl=0;
                cur=0;
                cur+=m[x];
                curl+=1;
                all.emplace_back(cur);
            }
            last=x;
        }
        sort(all.rbegin(),all.rend());
        cout<<all[0]<<endl;
    }
    return 0;
}