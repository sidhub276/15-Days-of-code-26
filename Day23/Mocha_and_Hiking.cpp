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
        vll v(n);
        forn(i,0,n)cin>>v[i];
        if(v[0]==1)
        {
            cout<<n+1<<" ";
            forn(i,1,n+1)cout<<i<<sp;
            cout<<endl;
        }
        else if(n==1)
        {
            cout<<"1 2"<<endl;
        }
        else if(v[n-1]==0)
        {
            forn(i,1,n+2)cout<<i<<" ";
            cout<<endl;
        }
        else
        {
            int k=0;
            int in=-1;
            for(int i=0;i<n-1;i++)
            {
                if(v[i]==0&&v[i+1]==1)
                {
                    k=1;
                    in=i;
                    break;
                }
            }
            if(k==0)
            {
                cout<<"-1"<<endl;
            }
            else
            {
                vector<int>ans(n+1);
                for(int i=0;i<=in;i++)
                {
                    ans[i]=i+1;
                }
                ans[in+1]=n+1;
                for(int i=in+2;i<n+1;i++)
                {
                    ans[i]=i;
                }
                vout(ans);
            }
        }
    }
    return 0;
}