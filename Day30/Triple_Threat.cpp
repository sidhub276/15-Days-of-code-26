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
        ll n,x;
        cin>>n>>x;
        vector<ll>ans(3*n,-1);
        ll n0=3*n-x;
        for(int i=0;i<n&&n0>0;i++)
        {
            if(n0>0)
            {
                ans[i]=0;
                n0-=1;
            }
            if(n0>0)
            {
                ans[i+n]=0;
                n0-=1;
            }
        }
        for(int i=0;i<3*n;i++)
        {
            if(ans[i]==-1&&x>0)
            {
                ans[i]=1;
                x--;
            }
            else if(ans[i]==-1&&x==0)ans[i]=0;
        }
        forn(i,0,3*n)cout<<ans[i];
        cout<<endl;
    }
    return 0;
}