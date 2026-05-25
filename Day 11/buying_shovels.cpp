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
        if(n<=k)
        {
            cout<<"1"<<endl;
            continue;
        }
        vector<ll>div;
        for(ll i=1;i*i<=n;i++)
        {
            if(n%i==0&&i<=k)div.emplace_back(i);
            if(n%i==0&&n/i<=k)div.emplace_back(n/i);
        }
        sort(div.rbegin(),div.rend());
        cout<<n/div[0]<<endl;
    }
    return 0;
}