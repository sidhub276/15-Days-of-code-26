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
        vector<int>v(n);
        for(int i=0;i<n;i++)
        {
            cin>>v[i];
        }
        vector<int>ans;
        ans.emplace_back(v[0]);
        for(int i=1;i<n-1;i++)
        {
            if(v[i-1]>v[i]&&v[i]<v[i+1])ans.emplace_back(v[i]);
            if(v[i-1]<v[i]&&v[i]>v[i+1])ans.emplace_back(v[i]);
        }
        ans.emplace_back(v[n-1]);
        cout<<ans.size()<<endl;
        for(auto x:ans)
        {
            cout<<x<<" ";
        }
        cout<<endl;
    }
    return 0;
}