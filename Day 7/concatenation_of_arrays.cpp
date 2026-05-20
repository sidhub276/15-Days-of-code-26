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
        vector<pair<ll,ll>>v(n);
        vector<pair<pair<ll,ll>,ll>>mini(n);
        for(int i=0;i<n;i++)
        {
            cin>>v[i].first>>v[i].second;
            mini[i].first.first=min(v[i].first,v[i].second);
            mini[i].first.second=max(v[i].first,v[i].second);
            mini[i].second=i;
        }
        sort(mini.begin(),mini.end());
        for(int i=0;i<n;i++)
        {
            cout<<v[mini[i].second].first<<" "<<v[mini[i].second].second<<" ";
        }
        cout<<endl;
    }
    return 0;
}