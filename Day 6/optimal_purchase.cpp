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
        ll a,b,c;
        cin>>a>>b>>c;
        ll aa=a/3*c+a%3*b;
        ll bb;
        if(a%3==0)bb=a/3*c;
        else bb=a/3*c+c;
        ll cc=a*b;
        cout<<min(aa,min(bb,cc))<<endl;
    }
    return 0;
}