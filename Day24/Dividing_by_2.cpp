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
        vector<ll>v(n);
        for(int i=0;i<n;i++)
        {
            cin>>v[i];
        }
        sort(all(v));
        ll ans=0;
        int curno=0;
        int last=v[0];
        for(int i=1;i<n;i++)
        {
            if(last!=v[i])
            {
                int a=last,b=v[i];
                while(a!=b)
                {
                    if(a>b)
                    {
                        a/=2;
                    }
                    else{
                        b/=2;
                    }
                }
                last=a;
            }
        }
        for(int i=0;i<n;i++)
        {
            while(v[i]!=last)
            {
                v[i]/=2;
                ans+=1;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}