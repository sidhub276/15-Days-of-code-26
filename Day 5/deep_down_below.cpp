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
        vector<pair<ll,vector<ll>>>v(n);
        vector<pair<ll,ll>>r(n);
        for(int i=0;i<n;i++)
        {
            ll a;
            cin>>a;
            v[i].first=a;
            for(int j=0;j<a;j++)
            {
                ll b;
                cin>>b;
                v[i].second.emplace_back(b-j+1);
            }
            sort(v[i].second.rbegin(),v[i].second.rend());
            r[i].first=v[i].second[0];
            r[i].second=v[i].second[0]+v[i].first;
        }
        sort(r.begin(),r.end());
        ll zyada=0;
        ll ans=r[0].first;
        for(int i=0;i<n-1;i++)
        {
            if(r[i].second>r[i+1].first)
            {
                zyada+=r[i].second-r[i+1].first;
            }
            else if(r[i].second<r[i+1].first)
            {
                ll diff=abs(r[i].second-r[i+1].first);
                if(zyada>=diff)
                {
                    zyada-=diff;
                }
                else
                {
                    diff-=zyada;
                    ans+=diff;
                    zyada=0;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}