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
        ini
        string s;
        cin>>s;
        int nos=0;
        forn(i,0,n)
        {
            if(s[i]=='*')nos+=1;
        }
        if(nos<=1)
        {
            cout<<"0"<<endl;
            continue;
        }
        if(nos%2==1||nos%2==0)
        {
            int mid=nos/2+1;
            int midin=-1;
            int cur=0;
            forn(i,0,n)
            {
                if(s[i]=='*')cur+=1;
                if(cur==mid)
                {
                    midin=i;
                    break;
                }
            }
            ll ans=0;
            int bun=0;
            for(int i=0;i<midin;i++)
            {
                if(s[i]=='*')bun+=1;
                else ans+=bun;
            }
            bun=0;
            for(int i=n-1;i>midin&&i<n;i--)
            {
                if(s[i]=='*')bun+=1;
                else ans+=bun;
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}