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
int nod(ll n)
{
    set<int>s;
    while(n!=0)
    {
        s.insert(n%10);
        n/=10;
    }
    return s.size();
}
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
        int k=0;
        ll nn=n;
        if(nn%10==0)k=1;
        while(nn!=0)
        {
            nn/=10;
            if(nn>0&&nn%10==0)k=1;
        }
        if(k==1)
        {
            cout<<"10"<<endl;
            continue;
        }
        else
        {
            int nn=0;
            while(n!=0)
            {
                nn+=1;
                n/=10;
            }
            ll ans=1;
            for(int i=0;i<nn;i++)
            {
                ans*=10;
            }
            ans+=1;
            cout<<ans<<endl;
        }
        
    }
    return 0;
}