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
using ll=long long;
int main()  
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    for(int q=1;q<=t;q++)
    {
        ll n,m,k;
        ll ans=0;
        cin>>n>>m>>k;
        vector<ll>v(n);
        vector<ll>div(n);
        vector<ll>mod(n);
        for(ll i=0;i<n;i++)
        {
            cin>>v[i];
            div[i]=v[i]/k;
            mod[i]=v[i]%k;
        }
        sort(div.rbegin(),div.rend());
        sort(mod.rbegin(),mod.rend());
        ll a=m/(k+1);
        ll b=m%(k+1);
        ll divsum=0;
        for(ll i=0;i<n;i++)
        {
            divsum+=div[i];
        }
        if(divsum>a)
        {
            ans=a*k+b;
        }
        else if(divsum==a)
        {
            ans+=a*k;
            ll i=0;
            while(b>0&&i<n)
            {
                ll y=mod[i];
                if(y>=b)
                {
                    ans+=b;
                    b=0;
                }
                else if(y==b-1)
                {
                    ans+=b-1;
                    b=0;
                }
                else
                {
                    ans+=y;
                    b-=y+1;
                }
                i+=1;
            }
        }
        else
        {
            ans+=divsum*k;
            ll rem=m-divsum*(k+1);
            ll i=0;
            while(rem>0&&i<n)
            {
                ll y=mod[i];
                if(y>=rem)
                {
                    ans+=rem;
                    rem=0;
                }
                else if(y==rem-1)
                {
                    ans+=rem-1;
                    rem=0;
                }
                else
                {
                    ans+=y;
                    rem-=y+1;
                }
                i+=1;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}