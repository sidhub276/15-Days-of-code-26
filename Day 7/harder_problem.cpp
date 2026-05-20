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
        set<int>av;
        set<int>done;
        for(int i=1;i<=n;i++)
        {
            av.insert(i);
        }
        vector<int>ans(n);
        for(int i=0;i<n;i++)
        {
            cin>>v[i];
            av.erase(v[i]);
        }
        for(int i=0;i<n;i++)
        {
            if(done.find(v[i])==done.end())
            {
                ans[i]=v[i];
                done.insert(v[i]);
            }
            else 
            {
                ans[i]=*av.begin();
                av.erase(ans[i]);
                done.insert(ans[i]);
            }
        }
        for(auto x:ans)cout<<x<<" ";
        cout<<endl;
    }
    return 0;
}