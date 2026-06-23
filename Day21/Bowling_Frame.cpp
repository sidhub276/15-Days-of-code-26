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
        ll w,b;
        cin>>w>>b;
        ll ans=(-1+sqrt(1+8*(w+b)))/2;
        ans/=1;
        cout<<ans<<endl;
    }
    return 0;
}