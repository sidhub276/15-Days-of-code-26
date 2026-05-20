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
        map<int,int>m;
        set<int>s;
        for (int i=0;i<n;i++)
        {
            cin>>v[i];
            m[v[i]]++;
            s.insert(v[i]);
        }
        int k=0;
        for(auto x:s)k+=1;
        if(k==n)
        {
            cout<<"-1"<<endl;
            continue;
        }
        int mini=10e6;
        for(auto x:s)
        {
            if(m[x]>1)
            {
                int ans=0;
                for(int i=0;i<n;i++)
                {
                    if(v[i]==x)break;
                    ans+=1;
                }
                for(int j=n-1;j>=0;j--)
                {
                    if(v[j]==x)break;
                    ans+=1;
                }
                mini=min(mini,ans);
            }
        }
        cout<<mini<<endl;
    }
    return 0;
}