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
        int n,m;
        cin>>n>>m;
        vector<ll>k(n),c(m);
        for(int i=0;i<n;i++)
        {
            cin>>k[i];
        }
        for(int i=0;i<m;i++)
        {
            cin>>c[i];
        }
        sort(k.rbegin(),k.rend());
        int g=0;
        ll ans=0;
        for(int i=0;i<n;i++)
        {
            if(g<m)
            {
                if((c[g]<c[k[i]-1]))
                {
                    ans+=c[g];
                    g+=1;
                }
                else 
                {
                    ans+=c[k[i]-1];
                }
            }
            else 
            {
                ans+=c[k[i]-1];
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}