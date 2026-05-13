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
        map<ll,ll>m;
        set<ll>s;
        for(int i=0;i<n;i++)
        {
            cin>>v[i];
            s.insert(v[i]);
            m[v[i]]+=1;
        }
        vector<pair<ll,ll>>fre;
        int d=0;
        for(auto x:s)
        {
            fre.emplace_back(m[x],x);
            d+=1;
        }
        if(d==1)cout<<"NO"<<endl;
        else
        {
            sort(fre.begin(),fre.end());
            vector<pair<ll,ll>>ans;
            ll a=fre[0].second;
            ll ain=-1;
            ll b=fre[1].second;
            ll bin=-1;
            for(int i=0;i<n;i++)
            {
                if(v[i]==a)
                {
                    ain=i;
                    break;
                }
            }
            for(int i=0;i<n;i++)
            {
                if(v[i]==b)
                {
                    bin=i;
                    break;
                }
            }
            for(int i=0;i<n;i++)
            {
                if(v[i]!=a&&i!=ain)
                {
                    ans.emplace_back(ain+1,i+1);
                }
            }
            for(int i=0;i<n;i++)
            {
                if(v[i]==a&&i!=bin&&i!=ain)
                {
                    ans.emplace_back(bin+1,i+1);
                }
            }
            cout<<"YES"<<endl;
            for(auto x:ans)
            {
                cout<<x.first<<" "<<x.second<<endl;
            }
        }

    }
    return 0;
}