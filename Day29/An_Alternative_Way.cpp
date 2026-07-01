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
        ll n;
        cin>>n;
        vll a(n),b(n);
        forn(i,0,n)cin>>a[i];
        forn(i,0,n)cin>>b[i];
        vll dif(n);
        forn(i,0,n)dif[i]=a[i]-b[i];
        ll cur=dif[0];
        ll k=1;
        ll z=0;
        if(n==1&&cur>0)k=0;
        ll sum=0;
        forn(i,0,n){
        sum+=dif[i];
        if(sum>0)
        {
            cout<<"No"<<endl;z=1;
            break;;
        }}
        if(z==0)cout<<"Yes"<<endl;;
    }
    return 0;
}