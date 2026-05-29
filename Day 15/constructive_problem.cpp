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
    for(ll q=1;q<=t;q++)
    {
        ll n;
        cin>>n;
        vector<ll>v(n);
        map<ll,ll>m;
        ll sum=0;
        for (ll i=0;i<n;i++)
        {
            cin>>v[i];
            m[v[i]]++;
            sum+=v[i];
        }
        ll mex=0;
        for(auto x:m)
        {
            if(x.first==mex)mex+=1;
            else break;
        }
        if(n==1&&v[0]==0)
        {
            cout<<"No"<<endl;
            continue;
        }
        else if(n==1)
        {
            cout<<"Yes"<<endl;
            continue;
        }
        if(n==mex)
        {
            cout<<"No"<<endl;
            continue;
        }
        vector<ll>in;
        for(ll i=0;i<n;i++)
        {
            if(v[i]==mex+1)in.emplace_back(i);
        }
        if(in.size()==0)
        {
            cout<<"Yes"<<endl;
            continue;
        }
        sort(in.begin(),in.end());
        if(in.size()==1)
        {
            cout<<"Yes"<<endl;
            continue;
        }
        map<ll,ll>mm;
        for(ll i=in[0];i<=in.back();i++)
        {
            mm[v[i]]+=1;
        }
        ll k=1;
        for(auto x:mm)
        {
            if(x.first<mex)
            {
                if(m[x.first]-x.second<1)
                {
                    k=0;
                    break;
                }
            }
        }
        if(k==1)cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}