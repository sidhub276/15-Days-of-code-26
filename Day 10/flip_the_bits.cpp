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
    ll t;
    cin>>t;
    for(int q=1;q<=t;q++)
    {
        ll n;
        string a,b;
        cin>>n>>a>>b;
        vector<ll>sd(n);
        ll op=0;
        for(ll i=0;i<n;i++)
        {
            if(a[i]==b[i])sd[i]=1;
            else sd[i]=0;
        }
        vector<ll>sd10(n,0);
        ll n1=0;
        ll n0=0;
        for(int i=0;i<n;i++)
        {
            if(a[i]=='0')n0+=1;
            else n1+=1;
            if(n1==n0)sd10[i]=1;
        }
        ll ans=1;
        for(ll i=n-1;i>=0;i--)
        {
            if(sd[i]==0&&op%2==0)
            {
                if(sd10[i]==1)op+=1;
                else
                {
                    ans=0;
                    break;
                }
            }
            else if(sd[i]==1&&op%2==1)
            {
                if(sd10[i]==1)op+=1;
                else
                {
                    ans=0;
                    break;
                }
            }
        }
        if(ans==1)cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}