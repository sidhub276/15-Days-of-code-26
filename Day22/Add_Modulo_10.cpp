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
#define ll long long
#define vll vector<ll>
#define pll pair<ll,ll>
#define vpll vector<pair<ll,ll>>
#define endl "\n"
#define forn(i,a,b) for(int i=(int)a;i<(int)b;i++)
#define ini ll n; cin>>n;
#define all(v) v.begin(),v.end()
#define sp " "
#define vout(v) forn(i,0,v.size()) cout<<v[i]<<(i==v.size()-1?endl:sp)
int main()  
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    for(int q=1;q<=t;q++)
    {
        ini
        vll v(n);
        forn(i,0,n)cin>>v[i];
        map<int,int>m;
        for(int i=0;i<n;i++)
        {
            m[v[i]%10]+=1;
        }
        int n50=0;
        if(m[5]>=1||m[0]>=1)n50=1;
        if(n50==1)
        {
            int k=0;
            for(int i=1;i<10;i++)
            {
                if(i!=5&&m[i]>1)k=1;
            }
            if(k)
            {
                cout<<"No"<<endl;
                continue;
            }
            if(m[5]==0||m[0]==0)
            {
                k=1;
                ll a=v[0];
                for(int i=0;i<n;i++)
                {
                    if(v[i]!=a)k=0;
                }
                if(k)cout<<"Yes"<<endl;
                else cout<<"No"<<endl;
                continue;
            }
            else
            {
                ll a=0;
                k=1;
                for(int i=0;i<n;i++)
                {
                    if(v[i]%10==0)
                    {
                        a=v[i];
                        break;
                    }
                }
                for(int i=0;i<n;i++)
                {
                    if(v[i]!=a&&v[i]+5!=a)k=0;
                }
                if(k)cout<<"Yes"<<endl;
                else cout<<"No"<<endl;
                continue;
            }
        }
        for(int i=0;i<n;i++)
        {
            while(v[i]%10!=2)
            {
                v[i]+=v[i]%10;
            }
        }
        for(int i=0;i<n;i++)
        {
            v[i]+=8;
            v[i]/=10;
        }
        map<int,int>mp;
        for(int i=0;i<n;i++)
        {
            mp[v[i]%2]+=1;
        }
        if(mp[1]>0&&mp[0]>0)cout<<"No"<<endl;
        else cout<<"Yes"<<endl;
    }
    return 0;
}