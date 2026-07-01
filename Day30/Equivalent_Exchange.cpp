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
        int n,k;
        cin>>n>>k;
        vll v(n);
        forn(i,0,n)cin>>v[i];
        int b=0,r=0;
        ll kk=1;
        for(int i=0;i<n;i++)
        {
            if(v[i]<0)
            {
                b+=abs(v[i]);
                if(r>=abs(v[i]))
                {
                    r-=abs(v[i]);
                }
                else if(r+k<abs(v[i]))
                {
                    kk=0;
                    break;
                }
                else
                {
                    ll aa=abs(v[i]);
                    aa-=r;
                    r=0;
                    k-=aa;
                }
            }
            if(v[i]>0)
            {
                r+=abs(v[i]);
                if(b>=abs(v[i]))
                {
                    b-=abs(v[i]);
                }
                else if(b+k<abs(v[i]))
                {
                    kk=0;
                    break;
                }
                else
                {
                    ll aa=abs(v[i]);
                    aa-=b;
                    b=0;
                    k-=aa;
                }
            }
        }
        if(kk)cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}