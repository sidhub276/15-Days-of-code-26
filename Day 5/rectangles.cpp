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
    int n,m;
    cin>>n>>m;
    int arr[n][m];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>arr[i][j];
        }
    }
    vector<pair<int,int>>r(n);
    vector<pair<int,int>>c(m);
    for(int i=0;i<n;i++)
    {
        int w=0;
        int b=0;
        for(int j=0;j<m;j++)
        {
            if(arr[i][j]==1)b+=1;
            else w+=1;
        }
        r[i]={w,b};
    }
    for(int j=0;j<m;j++)
    {
        int w=0;
        int b=0;
        for(int i=0;i<n;i++)
        {
            if(arr[i][j]==1)b+=1;
            else w+=1;
        }
        c[j]={w,b};
    }
    ll ans=-n*m;
    for(int i=0;i<n;i++)
    {
        int a=r[i].first;
        int b=r[i].second;
        ans+=(1LL<<a)-1;
        ans+=(1LL<<b)-1;
    }
    for(int i=0;i<m;i++)
    {
        int a=c[i].first;
        int b=c[i].second;
        ans+=(1LL<<a)-1;
        ans+=(1LL<<b)-1;
    }
    cout<<ans<<endl;
    return 0;
}