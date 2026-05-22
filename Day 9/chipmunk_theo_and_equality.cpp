#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <unordered_set>
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
        int n;
        cin>>n;
        unordered_map<ll,ll>c;
        unordered_map<ll,ll>val;
        c.reserve(n*40);
        val.reserve(n*40);
        for(int i=0;i<n;i++)
        {
            ll a;
            cin>>a;
            c[a]+=1;
            ll xx=0;
            if(a==1)
            {
                c[a+1]+=1;
                val[a+1]+=1;
            }
            while(a!=1)
            {
                if(a%2==0)
                {
                    a/=2;
                }
                else
                {
                    a+=1;
                }
                xx+=1;
                c[a]++;
                val[a]+=xx;
            }
        }
        ll ans=1e18;
        for(auto x:c)
        {
            if(x.second==n)
            {
                ans=min(ans,val[x.first]);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}