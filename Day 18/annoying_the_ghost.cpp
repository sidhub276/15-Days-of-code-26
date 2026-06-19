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
        vector<ll>a(n),b(n);
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        for(int i=0;i<n;i++)
        {
            cin>>b[i];
        }
        vector<ll>a0=a;
        vector<ll>a1=a;
        sort(a0.begin(),a0.end());
        int k=1;
        for(int i=0;i<n;i++)
        {
            if(a0[i]>b[i])
            {
                k=0;
                break;
            }
        }
        if(k==0)
        {
            cout<<"-1"<<endl;
            continue;
        }
        ll ans=0;
        for(int i=0;i<n;i++)
        {
            int in=-1;
            for(int j=i;j<n;j++)
            {
                if(b[i]>=a[j])
                {
                    ans+=j-i;
                    in=j;
                    break;
                }
            }
            ll c=a[in];
            for(int k=in;k>i;k--)
            {
                a[k]=a[k-1];
            }
            a[i]=c;
        }
        cout<<ans<<endl;
    }
    return 0;
}