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
    t=1;
    for(int q=1;q<=t;q++)
    {
        ll n,k;
        cin>>n>>k;
        vector<ll>v(n);
        for(int i=0;i<n;i++)
        {
            cin>>v[i];
        }
        sort(v.begin(),v.end());
        ll nn=1;
        int ans=v[n/2];
        int kk=1;
        for(int i=n/2;i<n-1;i++)
        {
            if(k>=(v[i+1]-v[i])*nn)
            {
                ans=v[i+1];
                nn+=1;
                k-=(v[i+1]-v[i])*(nn-1);
            }
            else 
            {
                ans+=k/(nn);
                kk=0;
                break;
            }
        }
        if(kk==1)cout<<ans+k/(n/2+1)<<endl;
        else cout<<ans<<endl;
    }
    return 0;
}