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
        int n,c;
        cin>>n>>c;
        int k=1;
        ll ans=0;
        vector<int>a(n),b(n);
        for(int i=0;i<n;i++)cin>>a[i];
        forn(i,0,n)cin>>b[i];
        for(int i=0;i<n;i++)
        {
            if(a[i]<b[i])
            {
                k=0;
                break;
            }
        }
        if(k==1)
        {
            vector<int>aa=a,bb=b;
            sort(all(aa));
            sort(all(bb));
            int ans1=0,ans2=0;
            for(int i=0;i<n;i++)
            {
                ans1+=a[i]-b[i];
                ans2+=aa[i]-bb[i];
            }
            ans2+=c;
            cout<<min(ans1,ans2)<<endl;
        }
        else
        {
            k=1;
            vector<int>aa=a,bb=b;
            sort(all(aa));
            sort(all(bb));
            forn(i,0,n)if(aa[i]<bb[i])k=0;
            if(k==0)
            {
                cout<<"-1"<<endl;
                continue;
            }
            ll ans1=0;
            for(int i=0;i<n;i++)
            {
                ans1+=aa[i]-bb[i];
            }
            cout<<ans1+c<<endl;
            
        }
    }
    return 0;
}