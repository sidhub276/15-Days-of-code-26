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
        int n;
        cin>>n;
        vector<ll>v(n);
        vector<pair<ll,ll>>nsum(n);
        ll neg=0;
        for(int i=0;i<n;i++)
        {
            cin>>v[i];
            if(v[i]>0)
            {
                nsum[i].first=1;
                nsum[i].second=neg;
            }
            else
            {
                nsum[i].first=0;
                neg+=(-1*v[i]);
                nsum[i].second=neg;
            }
        }
        vector<pair<ll,ll>>faida;
        for(int i=0;i<n;i++)
        {
            if(nsum[i].first==1&&i>0)
            {
                faida.emplace_back(nsum[i].second-v[i],i);
            }
        }
        sort(faida.rbegin(),faida.rend());
        if(faida.size()==0||faida[0].first<0)
        {
            cout<<"0"<<endl;
            cout<<endl;
        }
        else
        {
            vector<ll>ans;
            vector<ll>lastq;
            for(int i=0;i<=faida[0].second-1;i++)
            {
                lastq.emplace_back(v[i]);
            }
            int nn=lastq.size();
            vector<ll>pn(nn);
            for(int i=0;i<nn;i++)
            {
                if(lastq[i]>0)pn[i]=1;
                else pn[i]=0;
            }
            vector<pair<int,int>>pr;
            int pl=0;
            int fi=-1;
            for(int i=0;i<nn;i++)
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
                pr.emplace_back(fi,nn-1);
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
            ans.emplace_back(faida[0].second+1);
            cout<<ans.size()<<endl;
            for(auto x:ans)
            {
                cout<<x<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}