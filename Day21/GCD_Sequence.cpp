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
int gcd(int a,int b)
{
    while(b)
    {
        a%=b;
        swap(a,b);
    }
    return a;
}
int main()  
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    for(int q=1;q<=t;q++)
    {
        int n;
        cin>>n;
        vector<ll>v(n);
        for(int i=0;i<n;i++)
        {
            cin>>v[i];
        }
        if(n==3)
        {
            cout<<"Yes"<<endl;
            continue;
        }
        int k=1;
        vector<ll>g;
        for(int i=0;i<n-1;i++)
        {
            g.emplace_back(gcd(v[i],v[i+1]));
        }
        int wrong=-1;
        for(int i=0;i<n-2;i++)
        {
            if(g[i]>g[i+1])
            {
                k=0;
                wrong=i;
                break;
            }
        }
        if(k)
        {
            cout<<"Yes"<<endl;
            continue;
        }
        else
        {
            vector<ll>v1=v,v2=v,v3=v;
            v1.erase(v1.begin()+wrong);
            v2.erase(v2.begin()+wrong+1);
            v3.erase(v3.begin()+wrong+2);
            int k1=1,k2=1,k3=1;
            vector<ll>g1,g2,g3;
            for(int i=0;i<n-2;i++)
            {
                g1.emplace_back(gcd(v1[i],v1[i+1]));
                g2.emplace_back(gcd(v2[i],v2[i+1]));
                g3.emplace_back(gcd(v3[i],v3[i+1]));
            }
            for(int i=0;i<n-3;i++)
            {
                if(g1[i]>g1[i+1])k1=0;
                if(g2[i]>g2[i+1])k2=0;
                if(g3[i]>g3[i+1])k3=0;
            }
            if(k1||k2||k3)cout<<"Yes"<<endl;
            else cout<<"No"<<endl;
        }
    }
    return 0;
}