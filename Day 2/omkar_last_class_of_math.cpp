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
        if(n%2==0)cout<<n/2<<" "<<n/2<<endl;
        else
        {
            vector<ll>div;
            ll i;
            for(i=1;i*i<n;i++)
            {
                if(n%i==0)
                {
                    div.emplace_back(i);
                    div.emplace_back(n/i);
                }
            }
            if(n%i==0)div.emplace_back(i);
            sort(div.begin(),div.end());
            int a=div.size();
            if(div.size()==2)cout<<"1 "<<n-1<<endl;
            else
            {
                cout<<div[a-2]<<" "<<n-div[a-2]<<endl;
            }
        }
    }
    return 0;
}