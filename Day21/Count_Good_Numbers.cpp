class Solution {
public:
    using ll=long long;
    static const int N=1000005;
    ll PRIME=1000000007;
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

    ll ncr(ll n,ll r)
    {
        if(r>n||n<0||r<0)return 0;
        else return fact[n]*inv_fact[r]%PRIME*inv_fact[n-r]%PRIME;
    }
    int countGoodNumbers(long long n) 
    {
        long long even=(n+1)/2;
        long long odd=n-even;
        ll ans=1;
        ans=pw(4,odd,PRIME)*pw(5,even,PRIME);
        ans%=PRIME;
        return ans;
    }
};