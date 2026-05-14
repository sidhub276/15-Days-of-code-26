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
        ll n,x;
        cin>>n>>x;
        vector<ll>v(n);
        ll maxi=0;
        ll sum=0;
        for(ll i=0;i<n;i++)
        {
            cin>>v[i];
            if(v[i]%x==0)maxi+=v[i]/x;
            else maxi+=v[i]/x+1;
            sum+=v[i];
        }
        if(sum%x==0)cout<<sum/x<<" "<<maxi<<endl;
        else cout<<sum/x+1<<" "<<maxi<<endl;
    }
    return 0;
}