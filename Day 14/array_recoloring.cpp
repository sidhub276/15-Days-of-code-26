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
        ll n,k;
        cin>>n>>k;
        vector<ll>v(n);
        for(int i=0;i<n;i++)
        {
            cin>>v[i];
        }
        if(k>1)
        {
            sort(v.rbegin(),v.rend());
            ll ans=0;
            for(int i=0;i<k+1;i++)
            {
                ans+=v[i];
            }
            cout<<ans<<endl;
            continue;
        }
        ll ans1=v[0];
        ll max1=0;
        for(int i=1;i<n;i++) 
        {
            max1=max(max1,v[i]);
        }
        ans1+=max1;
        ll ans2=v[n-1];
        ll max2=0;
        for(int i=0;i<n-1;i++)
        {
            max2=max(max2,v[i]);
        }
        ans2+=max2;
        cout<<max(ans1,ans2)<<endl;
    }
    return 0;
}