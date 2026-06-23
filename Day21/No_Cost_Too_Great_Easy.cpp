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

constexpr int N=1000005;
constexpr int PRIME=1000000007;

ll pw(ll a,ll b,ll m)
{
    if(b==0)return 1%m;
    if(b%2==0)
    {
        ll t=pw(a,b/2,m);
        return (1ll*t*t%m);
    }
    else{
        ll t=pw(a,(b-1)/2,m);
        t=(1ll*t*t)%m;
        return(1ll*a*t%m);
    }
}

ll fact[N],inv_fact[N];

void init()
{
    ll p=PRIME;
    fact[0]=1;
    ll i;
    for(i=1;i<N;i++)
    {
        fact[i]=(1ll*fact[i-1]*i)%p;
    }
    i--;
    inv_fact[i]=pw(fact[i],p-2,p);
    for(--i;i>=0;i--)
    {
        inv_fact[i]=inv_fact[i+1]*(i+1)%p;
    }
}
int gcd(ll a,ll b)
{
    while(b)
    {
        a%=b;
        swap(a,b);
    }
    return a;
}
ll ncr(ll n,ll r)
{
    if(r>n||n<0||r<0)return 0;
    else return fact[n]*inv_fact[r]%PRIME*inv_fact[n-r]%PRIME;
}
ll lcm(ll a,ll b)
{
    return (a*b/gcd(a,b))%PRIME;
}
int main()  
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    init();
    int t;
    cin>>t;
    vector<int>prime(200001,1);
    prime[0]=0;
    prime[1]=0;
    for(int i=2;i<200001;i++)
    {
        if(!prime[i])continue;
        for(ll j=1LL*i*i;j<200001;j+=i)
        {
            prime[j]=0;
        }
    }
    vector<int>onlyfans;
    for(int i=0;i<200001;i++)
    {
        if(prime[i])onlyfans.emplace_back(i);
    }
    for(int q=1;q<=t;q++)
    {
        int n;
        cin>>n;
        vector<int>v(n),b(n);
        for(int i=0;i<n;i++)
        {
            cin>>v[i];
        }
        for(int i=0;i<n;i++)
        {
            cin>>b[i];
        }
        vector<int>vv=v;
        ll k=0;
        map<int,int>mp;
        for(int i=0;i<n;i++)
        {
            for(int j=0;onlyfans[j]*onlyfans[j]<=v[i];j++)
            {
                if(v[i]%onlyfans[j]==0)
                {
                    mp[onlyfans[j]]+=1;
                    if(mp[onlyfans[j]]>1)
                    {
                        k=1;
                        break;
                    }
                    while(v[i]%onlyfans[j]==0)
                    {
                        v[i]/=onlyfans[j];
                    }
                }
                if(k==1)break;
            }
            if(v[i]>1)
            {
                mp[v[i]]+=1;
                if(mp[v[i]]>1)
                {
                    k=1;
                }
            }
            if(k==1)break;
        }
        if(k)
        {
            cout<<"0"<<endl;
            continue;
        }
        k=0;
        for(int i=0;i<n;i++)
        {
            int now=vv[i];
            for(int j=0;onlyfans[j]*onlyfans[j]<=now;j++)
            {
                if(now%onlyfans[j]==0)
                {
                    mp[onlyfans[j]]-=1;
                    while(now%onlyfans[j]==0)
                    {
                        now/=onlyfans[j];
                    }
                }
            }
            if(now>1)
            {
                mp[now]-=1;
            }
            now=vv[i]+1;
            for(int j=0;onlyfans[j]*onlyfans[j]<=now;j++)
            {
                if(now%onlyfans[j]==0)
                {
                    mp[onlyfans[j]]+=1;
                    if(mp[onlyfans[j]]>1)
                    {
                        k=1;
                        break;
                    }
                    while(now%onlyfans[j]==0)
                    {
                        now/=onlyfans[j];
                    }
                }
            }
            if(now>1)
            {
                mp[now]+=1;
                if(mp[now]>1)
                {
                    k=1;
                }
            }
            if(k==1)break;
            now=vv[i]+1;
            for(int j=0;onlyfans[j]*onlyfans[j]<=now;j++)
            {
                if(now%onlyfans[j]==0)
                {
                    mp[onlyfans[j]]-=1;
                    while(now%onlyfans[j]==0)
                    {
                        now/=onlyfans[j];
                    }
                }
            }
            if(now>1)
            {
                mp[now]-=1;
            }
            now=vv[i];
            for(int j=0;onlyfans[j]*onlyfans[j]<=now;j++)
            {
                if(now%onlyfans[j]==0)
                {
                    mp[onlyfans[j]]+=1;
                    while(now%onlyfans[j]==0)
                    {
                        now/=onlyfans[j];
                    }
                }
            }
            if(now>1)
            {
                mp[now]+=1;
            }
        }
        if(k)cout<<"1"<<endl;
        else cout<<"2"<<endl;
    }
    return 0;
}