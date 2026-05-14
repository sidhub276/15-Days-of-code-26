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
    t=1;
    for(int q=1;q<=t;q++)
    {
        ll k,a,b;
        cin>>k>>a>>b;
        ll ak=a/k;
        ll bk=b/k;
        if(ak+bk==0)cout<<"-1"<<endl;
        else if(ak==0&&b%k!=0)cout<<"-1"<<endl;
        else if(bk==0&&a%k!=0)cout<<"-1"<<endl;
        else cout<<ak+bk<<endl;

    }
    return 0;
}