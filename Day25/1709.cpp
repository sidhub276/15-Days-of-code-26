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
        vector<int>a(n);
        vector<int>b(n);
        forn(i,0,n)cin>>a[i];
        forn(i,0,n)cin>>b[i];
        vector<int>aa=a,bb=b;
        vector<pair<int,int>>ex;
        sort(aa.rbegin(),aa.rend());
        sort(all(bb));
        vector<pair<int,int>>ans;
        for(int i=0;i<n;i++)
        {
            if(aa[i]>n&&bb[i]<=n)ex.emplace_back(aa[i],bb[i]);
        }
        for(auto x:ex)
        {
            int na=x.first;
            int nb=x.second;
            int ain=-1;
            int bin=-1;
            for(int i=0;i<n;i++)
            {
                if(a[i]==na)
                {
                    ain=i+1;
                    break;
                }
            }
            for(int i=0;i<n;i++)
            {
                if(b[i]==nb)
                {
                    bin=i+1;
                    break;
                }
            }
            while(ain!=bin)
            {
                if(ain>bin)
                {
                    int cur=a[ain-1];
                    a[ain-1]=a[ain-2];
                    a[ain-2]=cur;
                    ans.emplace_back(1,ain-1);
                    ain-=1;
                }
                if(ain<bin)
                {
                    int cur=a[ain-1];
                    a[ain-1]=a[ain];
                    a[ain]=cur;
                    ans.emplace_back(1,ain);
                    ain+=1;
                }
            }
            ans.emplace_back(3,bin);
            swap(a[ain-1],b[bin-1]);
        }
        for(int i=0;i<n;i++)
        {
            if(a[i]!=i+1)
            {
                int ain=-1;
                for(int j=0;j<n;j++)
                {
                    if(a[j]==i+1)
                    {
                        ain=j+1;
                        break;
                    }
                }
                while(ain!=i+1)
                {
                    int cur=a[ain-1];
                    a[ain-1]=a[ain-2];
                    a[ain-2]=cur;
                    ans.emplace_back(1,ain-1);
                    ain-=1;
                }
            }
            if(b[i]!=n+i+1)
            {
                int bin=-1;
                for(int j=0;j<n;j++)
                {
                    if(b[j]==n+i+1)
                    {
                        bin=j+1;
                        break;
                    }
                }
                while(bin!=i+1)
                {
                    int cur=b[bin-1];
                    b[bin-1]=b[bin-2];
                    b[bin-2]=cur;
                    ans.emplace_back(2,bin-1);
                    bin-=1;
                }
            }
        }
        cout<<ans.size()<<endl;
        for(auto x:ans)
        {
            cout<<x.first<<" "<<x.second<<endl;
        }
    }
    return 0;
}