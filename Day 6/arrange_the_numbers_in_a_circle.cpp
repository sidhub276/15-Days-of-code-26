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
        int n;
        cin>>n;
        vector<ll>v(n);
        ll ans=0;
        ll n1=0;
        ll nf=0;
        ll to=0;
        ll g2=0;
        for(int i=0;i<n;i++)
        {
            cin>>v[i];
            to+=v[i];
        }
        if(to<3)
        {
            cout<<"0"<<endl;
            continue;
        }
        for(int i=0;i<n;i++)
        {
            if(v[i]>=2)
            {
                g2+=1;
                ans+=v[i];
                if(v[i]>=4)nf+=(v[i]-2)/2;
            }
            else n1+=1;
        }
        if(nf<=n1)
        {
            ans+=nf;
            n1-=nf;
        }
        else 
        {
            ans+=n1;
            n1=0;
        }
        if(g2==1&&n1>0)ans+=1;
        cout<<ans<<endl;
    }
    return 0;
}