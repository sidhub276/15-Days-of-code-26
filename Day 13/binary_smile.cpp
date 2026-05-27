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
        int n;
        cin>>n;
        string a,b;
        cin>>a>>b;
        map<char,int>m1,m2;
        vector<int>v(n,0);
        for(int i=0;i<n;i++)
        {
            m1[a[i]]+=1;
            m2[b[i]]+=1;
        }
        if(m1['0']!=m2['0'])
        {
            cout<<"-1"<<endl;
            continue;
        }
        int na=0,nb=0;
        for(int i=0;i<n;i++)
        {
            if(a[i]=='1')na+=1;
            if(b[i]=='1')nb+=1;
            if(na==nb)v[i]=1;
        }
        ll ans=0;
        for(int i=0;i<n;i++)
        {
            if(v[i]==0)
            {
                if(a[i]=='1')ans+=1;
            }
            else if(v[i]==1&&i>0)
            {
                if(a[i]=='1'&&v[i-1]==0)ans+=1;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}