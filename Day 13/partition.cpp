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
        vector<ll>v(n);
        map<ll,ll>m;
        for (int i=0;i<n;i++)
        {
            cin>>v[i];
            m[v[i]]++;
        }
        ll maxi=0;
        for(auto x:m)
        {
            maxi=max(maxi,x.second);
        }
        cout<<n-maxi+1<<endl;

    }
    return 0;
}