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
ll hcf(ll a,ll b)
{
    while(b)
    {
        a%=b;
        swap(a,b);
    }
    return a;
}
ll lcm(ll a,ll b)
{
    ll c= hcf(a,b);
    return (a/c)*b;
}
int main()  
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    for(ll q=1;q<=t;q++)
    {
        ll n;
        cin>>n;
        vector<ll>a(n);
        vector<ll>b(n);
        for(ll i=0;i<n;i++)
        {
            cin>>a[i];
        }
        for(ll i=0;i<n;i++)
        {
            cin>>b[i];
        }
        ll k=1;
        if(a[n-1]!=b[0])
        {
            k=0;
        }
        for(ll i=0;i<n-1;i++)
        {
            if(a[i]%a[i+1]!=0)k=0;
        }
        for(ll i=n-1;i>0;i--)
        {
            if(b[i]%b[i-1]!=0)k=0;
        }
        for(int i=1;i<n;i++)
        {
            ll lc=lcm(a[i],b[i]);
            if(hcf(lc,a[i-1])!=a[i])
            {
                k=0;
                break;
            }
        }
        for(int i=n-2;i>=0;i--)
        {
            ll lc=lcm(a[i],b[i]);
            if(hcf(lc,b[i+1])!=b[i])
            {
                k=0;
                break;
            }
        }
        if(k)cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}