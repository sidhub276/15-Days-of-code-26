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
        ll n,x1,x2,k;
        cin>>n>>x1>>x2>>k;
        if(n<=3)
        {
            cout<<"1"<<endl;
            continue;
        }
        ll dif1=abs(x1-x2);
        ll dif2=abs(n-dif1);
        if(dif1==dif2)
        {
            cout<<k+min(dif1,dif2)<<endl;
        }
        else 
        {
            cout<<k+min(dif1,dif2)<<endl;
        }
    }
    return 0;
}