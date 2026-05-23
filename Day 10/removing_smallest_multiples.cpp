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
        string s;
        cin>>s;
        ll ans=0;
        vector<int>v(n);
        for(int i=0;i<n;i++)
        {
            if(s[i]=='0')v[i]=0;
            else v[i]=1;
        }
        for(int i=0;i<n;i++)
        {
            if(s[i]=='1')continue;
            else
            {
                for(int j=i;j<n;j+=i+1)
                {
                    if(s[j]=='1')break;
                    if(v[j]==1)continue;
                    v[j]=1;
                    ans+=i+1;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}