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
        ll n;
        cin>>n;
        vector<ll>v;
        for(int i=2;i*i<=n;i++)
        {
            if(i==n/i&&n%i==0)
            {
                v.emplace_back(i);
            }
            else if(n%i==0)
            {
                v.emplace_back(i);
                v.emplace_back(n/i);
            }
        }
        sort(v.begin(),v.end());
        if(v.size()==0)cout<<"1"<<" "<<n-1<<endl;
        else if(n%2==0)cout<<n/2<<" "<<n/2<<endl;
        else cout<<v.back()<<" "<<n-v.back()<<endl;
    }
    return 0;
}