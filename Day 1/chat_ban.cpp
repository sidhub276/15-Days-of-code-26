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
        ll k,x;
        cin>>k>>x;
        ll a=((k*k)+k)/2;
        if(x<=a)
        {
            ll a1=(sqrtl(1+8.0L*x)-1)/2;
            if(a1*(a1+1)/2==x)cout<<a1<<endl;
            else cout<<a1+1<<endl;
        }
        else if(x>=k*k) cout<<2*k-1<<endl;
        else
        {
            ll y=k*k-x;
            ll a1=(sqrtl(1+8.0L*y)-1)/2;
            cout<<2*k-1-a1<<endl;
        }
    }
    return 0;
}