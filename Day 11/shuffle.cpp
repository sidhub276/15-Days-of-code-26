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
        ll n,m,x;
        cin>>n>>x>>m;
        ll ansl=-1;
        ll ansr=-1;
        int k=0;
        for(int i=0;i<m;i++)
        {
            ll a,b;
            cin>>a>>b;
            if(k==0)
            {
                if(x>=a&&x<=b&&a!=b)k=1;
            }
            if(k==1)
            {
                if(ansl==-1)
                {
                    ansl=a;
                    ansr=b;
                }
                else if((a<=ansl&&b>=ansl)||(a<=ansr&&b>=ansr)||(a<=ansl&&b>=ansr))
                {
                    ansl=min(ansl,a);
                    ansr=max(ansr,b);
                }
            }
        }
        if(ansl==-1)
        {
            cout<<"1"<<endl;
        }
        else cout<<ansr-ansl+1<<endl;
    }
    return 0;
}