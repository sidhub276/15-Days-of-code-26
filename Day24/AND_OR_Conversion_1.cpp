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
        int k=0;
        int n;
        string a,b;
        cin>>n>>a>>b;
        vector<int>v(n,0);
        forn(i,0,n)if(a[i]==b[i])v[i]=1;
        int a1=0,b1=0,a0=0,b0=0;
        forn(i,0,n)
        {
            if(a[i]=='1')a1+=1;
            if(a[i]=='0')a0+=1;
            if(b[i]=='1')b1+=1;
            if(b[i]=='0')b0+=1;
        }
        if(b0>0&&a0==0)
        {
            cout<<"No"<<endl;
            continue;
        }
        if(b1>0&&a1==0)
        {
            cout<<"No"<<endl;
            continue;
        }
        vector<pair<int,int>>blo;
        int start=0;
        int end=0;
        char cur=a[0];
        for(int i=0;i<n;i++)
        {
            if(a[i]==cur)
            {
                end=i;
            }
            else
            {
                blo.emplace_back(start,end);
                start=i;end=i;
                cur=a[i];
            }
        }
        blo.emplace_back(start,end);
        vector<pair<int,int>>blob;
        start=0;
        end=0;
        cur=b[0];
        for(int i=0;i<n;i++)
        {
            if(b[i]==cur)
            {
                end=i;
            }
            else
            {
                blob.emplace_back(start,end);
                start=i;end=i;
                cur=b[i];
            }
        }
        blob.emplace_back(start,end);
        int na=blo.size();
        int nb=blob.size();
        if(na>nb)cout<<"Yes"<<endl;
        else if(na==nb)
        {
            if(a[0]==b[0])cout<<"Yes"<<endl;
            else cout<<"No"<<endl;
        }
        else cout<<"No"<<endl;
    }
    return 0;
}