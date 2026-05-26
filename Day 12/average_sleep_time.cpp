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
#include <iomanip>
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
        for(ll i=0;i<n;i++)
        {
            cin>>v[i];
        }
        set<ll>done;
        ll total=0;
        for(ll i=0;i<=k-1;i++)
        {
            total+=min(min(i+1LL,n-i),min(k,n-k+1))*v[i];
            done.insert(i);
        }
        for(ll i=n-1;i>=n-k;i--)
        {  if(done.find(i)!=done.end())continue;
            total+=min(min(i+1LL,n-i),min(k,n-k+1))*v[i];
            done.insert(i);
        }
        for(int i=0;i<n;i++)
        {
            if(done.find(i)==done.end())
            {
                total+=min(min(i+1LL,n-i),min(k,n-k+1))*v[i];
                done.insert(i);
            }
        }
       cout<<fixed<<setprecision(9)<<(long double)total/(n-k+1)<<endl;
    }
    return 0;
}