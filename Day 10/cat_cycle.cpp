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
        ll n,k;
        cin>>n>>k;
        if(n%2==0)
        {
            if(k%n>0)cout<<k%n<<endl;
            else cout<<n<<endl;
        }
        else
        {
            ll diff=n/2;
            if(k<=n/2)cout<<k<<endl;
            else if(k==n/2+1)
            {
                cout<<k+1<<endl;
            }
            else
            {
                ll ex;
                if(k%n>0)ex=k%n;
                else ex=n;
                ll a=((k-1)/(n/2));
                ll b=(ex+a)%n;
                if(b==0)cout<<n<<endl;
                else cout<<b<<endl;
            }
        }
    }
    return 0;
}