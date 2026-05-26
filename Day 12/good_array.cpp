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
    t=1;
    for(int q=1;q<=t;q++)
    {
        int n;
        cin>>n;
        vector<int>v(n);
        ll sum=0;
        vector<int>ans;
        for(int i=0;i<n;i++)
        {
            cin>>v[i];
            sum+=v[i];
        }
        vector<int>vv=v;
        sort(vv.rbegin(),vv.rend());
        int fm=vv[0],sm=vv[1];
        for(int i=0;i<n;i++)
        {
            if(v[i]==fm)
            {
                if(sum-fm-sm==sm)ans.emplace_back(i+1);
            }
            else if(sum-v[i]-fm==fm)ans.emplace_back(i+1);
        }
        cout<<ans.size()<<endl;
        for(auto x:ans)
        {
            cout<<x<<" ";
        }
        cout<<endl;
    }
    return 0;
}