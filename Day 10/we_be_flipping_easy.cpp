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
        vector<ll>pn(n);
        for(int i=0;i<n;i++)
        {
            cin>>v[i];
            if(v[i]>0)pn[i]=1;
            else pn[i]=0;
        }
        vector<ll>ans;
        vector<pair<int,int>>pr;
        int pl=0;
        int fi=-1;
        for(int i=0;i<n;i++)
        {
            if(pn[i]==0)
            {
                if(pl==0)continue;
                else
                {
                    pr.emplace_back(fi,i-1);
                    pl=0;
                }
            }
            else
            {
                if(pl==0)
                {
                    pl+=1;
                    fi=i;
                }
                else pl+=1;
            }
        }
        if(pl!=0)
        {
            pr.emplace_back(fi,n-1);
        }
        for(auto x:pr)
        {
            if(x.first==0)ans.emplace_back(x.second+1);
            else
            {
                ans.emplace_back(x.second+1);
                ans.emplace_back(x.first);
            }
        }
        cout<<ans.size()<<endl;
        for(auto x:ans)
        {
            cout<<x<<" ";
        }
        cout<<endl;
    }
    return 0;
}