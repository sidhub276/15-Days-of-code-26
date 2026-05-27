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
    string s;
    cin>>s;
    ll n=s.length();
    char cur=s[0];
    ll curl=0;
    vector<pair<char,ll>>fre;
    for(ll i=0;i<n;i++)
    {
        if(s[i]==cur)
        {
            curl+=1;
        }
        else
        {
            if(cur=='o')
            { 
                fre.emplace_back(cur,curl);
                curl=1;
                cur=s[i];
                continue;
            }
            if(curl>1)
            {
                fre.emplace_back('w',curl-1);
                curl=1;
                cur=s[i];
            }
            else
            {
                cur=s[i];
                curl=1;
            }
        }
    }
    if(curl>0)
    {
        if(cur=='o')fre.emplace_back(cur,curl);
        else if(curl>1)fre.emplace_back('w',curl-1);
    }
    ll nn=fre.size();
    ll w=0;
    vector<ll>dp(nn,-1);
    for(int i=nn-1;i>=0;i--)
    {
        if(fre[i].first=='o')
        {
            dp[i]=w*fre[i].second;
        }
        else w+=fre[i].second;
    }
    ll o=0;
    ll ans=0;
    for(int i=nn-1;i>=0;i--)
    {
        if(fre[i].first=='o')
        {
            o+=dp[i];
        }
        else ans+=o*fre[i].second;
    }
    cout<<ans<<endl;
    return 0;
}