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
#include <iomanip>
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
        long double n,d,h;
        cin>>n>>d>>h;
        vector<long double>v(n);
        long double ans=0;
        for(int i=0;i<n;i++)
        {
            cin>>v[i];
        }
        for(int i=0;i<n-1;i++)
        {
            if(v[i]+h<=v[i+1])
            {
                ans+=0.5*d*h;
            }
            else 
            {
                ans+=0.5*(v[i+1]-v[i])*(d+d*(1-(v[i+1]-v[i])/h));
            }
        }
        ans+=0.5*d*h;
        cout<<fixed<<setprecision(15)<<ans<<endl;
    }
    return 0;
}