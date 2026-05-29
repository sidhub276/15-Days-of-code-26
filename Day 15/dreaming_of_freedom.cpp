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
    vector<ll>prime(1e6+1,1);
    prime[0]=0;
    prime[1]=0;
    for(int i=2;i<1e6+1;i++)
    {
        if(prime[i]==0)continue;
        for(int j=i*2;j<1e6+1;j+=i)
        {
            prime[j]=0;
        }
    }
    for(int q=1;q<=t;q++)
    {
        int n,k;
        cin>>n>>k;
        if(n==1)
        {
            cout<<"Yes"<<endl;
            continue;
        }
        if(n<=k)
        {
            cout<<"No"<<endl;
            continue;
        }
        if(n>k)
        {
            if(prime[n]==1)cout<<"Yes"<<endl;
            else
            {
                int div=-1;
                for(int i=2;i*i<=n;i++)
                {
                    if(n%i==0)
                    {
                        div=i;
                        break;
                    }
                }
                if(div<=k)cout<<"No"<<endl;
                else cout<<"Yes"<<endl;
            }
        }
    }
    return 0;
}