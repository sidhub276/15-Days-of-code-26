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
        int n,l,r;
        cin>>n>>l>>r;
        vector<int>v(n);
        forn(i,0,n)cin>>v[i];
        int ans1=0,ans2=0;
        for(int i=0;i<l-1;i++)
        {
            ans1+=v[i];
        }
        for(int i=n-1;i>=r;i--)
        {
            ans2+=v[i];
        }
        cout<<max(ans1,ans2)<<endl;

    }
    return 0;
}