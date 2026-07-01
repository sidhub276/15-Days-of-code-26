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
        int n;
        cin>>n;
        vector<int>v(n);
        for(int i=0;i<n;i++)
        {
            int a;
            cin>>a;
            a%=(n+1);
            if(a==0)v[i]=-1;
            else v[i]=n+1-a;
        }
        map<int,int>m;
        forn(i,0,n)
        {
            if(v[i]>0)m[v[i]]+=1;
        }
        vector<pair<int,int>>fre;
        int k=1;
        for(auto x:m)
        {
            if(x.second==n)k=0;
        }
        if(k==0)
        {
            cout<<"-1"<<endl;
            continue;
        }
        vector<pair<int,pair<int,int>>>ans(n);
        for(int i=0;i<n;i++)
        {
            if(v[i]==-1)ans[i].first=0;
            else ans[i].first=m[v[i]];
            ans[i].second.first=v[i];
            ans[i].second.second=i;
        }
        sort(ans.rbegin(),ans.rend());
        set<int>rem;
        for(int i=1;i<n+1;i++)
        {
            rem.insert(i);
        }
        vector<int>sid(n);
        for(int i=0;i<n;i++)
        {
            if(rem.size()==1)
            {
                int a1=*rem.begin();
                if(ans[i].second.first!=a1)sid[ans[i].second.second]=a1;
                else
                {
                    int noo=a1;
                    for(int j=0;j<i;j++)
                    {
                        if(ans[j].second.first!=a1&&sid[ans[j].second.second]!=a1)
                        {
                            sid[ans[i].second.second]=sid[ans[j].second.second];
                            sid[ans[j].second.second]=a1;
                            break;
                        }
                    }
                }
                break;
            }
            int a1=*rem.begin();
            rem.erase(a1);
            int a2=*rem.begin();
            rem.erase(a2);
            if(ans[i].second.first!=a1)
            {
                sid[ans[i].second.second]=a1;
                rem.insert(a2);
            }
            else
            {
                sid[ans[i].second.second]=a2;
                rem.insert(a1);
            }
        }
        forn(i,0,n)cout<<sid[i]<<" ";
        cout<<endl;
    }
    return 0;
}