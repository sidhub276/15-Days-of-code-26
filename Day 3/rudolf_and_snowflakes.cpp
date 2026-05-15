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
    set<ll>s;
    for(ll i=2;i<=1000;i++)
    {
        ll x=1+i;
        ll y=i*i;
        for(int j=0;;j++)
        {
            if(x>1e6-y)break;
            x += y;
            s.insert(x);
            if(y>1L*1e18/i)break;
            y*=i;
        }
    }
    for(ll q=1;q<=t;q++)
    {
        ll n;
        cin>>n;
        if(s.find(n)!=s.end())cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}