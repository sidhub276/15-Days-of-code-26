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

ll zer(ll n)
{
    ll ret=0;
    while(n%10==0)
    {
        n/=10;
        ret+=1;
    }
    return ret;
}

ll dig(ll n)
{
    ll ret=0;
    while(n!=0)
    {
        n/=10;
        ret+=1;
    }
    return ret;
}

int main()  
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    for(int q=1;q<=t;q++)
    {
        ll n,m;
        cin>>n>>m;
        vector<ll>v(n);
        vector<pair<ll,ll>>zer_dig(n);
        ll total=0;
        for(int i=0;i<n;i++)
        {
            cin>>v[i];
            zer_dig[i].first=zer(v[i]);
            zer_dig[i].second=dig(v[i]);
            total+=dig(v[i]);
        }
        sort(zer_dig.rbegin(),zer_dig.rend());
        for(int i=0;i<n;i++)
        {
            if((i+1)%2==1)total-=zer_dig[i].first;
        }
        if(total>m)cout<<"Sasha"<<endl;
        else cout<<"Anna"<<endl;
    }
    return 0;
}