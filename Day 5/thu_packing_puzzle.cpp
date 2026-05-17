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
        ll tt,hh,uu;
        cin>>tt>>hh>>uu;
        ll ans=0;
        if(tt>=uu)
        {
            ans+=uu*4;
            tt-=uu;
            uu=0;
            if(tt>=hh*2)
            {
                ans+=hh*7;
                tt-=hh*2;
                hh=0;
                if(tt>0)ans+=tt*2+1;
            }
            else
            {
                ll a=tt/2;
                ll b=tt%2;
                ans+=a*7;
                ans+=b*5;
                hh-=a;
                hh-=b;
                ans+=hh*3;
            }
        }
        else
        {
            ans+=tt*4;
            uu-=tt;
            tt=0;
            ans+=(uu+hh)*3;
        }
        cout<<ans<<endl;
    }
    return 0;
}