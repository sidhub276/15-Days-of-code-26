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
        ll maxi=0;
        ll ans=0;
        vector<ll>a(n);
        vector<ll>b(n);
        for(int i=0;i<n;i++)cin>>a[i];
        for(int i=0;i<n;i++)cin>>b[i];
        for(int i=0;i<n;i++)
        {
            ll x,y;
            x=a[i];
            y=b[i];
            ans+=max(x,y);
            maxi=max(maxi,min(x,y));
        }
        ans+=maxi;
        cout<<ans<<endl;
    }
    return 0;
}