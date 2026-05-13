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
        ll n,x,k;
        cin>>n>>x>>k;
        string s;
        ll x1=0,x2=-1;
        cin>>s;
        ll i,j;
        ll a1=x,b1=0;
        ll a=0,b=0;
        for(i=0;i<n;i++)
        {
            if(s[i]=='L')
            {
                a1-=1;
            }
            else a1+=1;
            if(a1==0)
            {
                x1=1;
                break;
            }
        }
        if(x1)a=i+1;
        for(j=0;j<n;j++)
        {
            if(s[j]=='L')
            {
                b1-=1;
            }
            else b1+=1;
            if(b1==0)
            {
                x2=1;
                break;
            }
        }
        if(x2!=-1)b=j+1;
        if(b==0&&a>0)cout<<"1"<<endl;
        else if(b==0&&a==0)cout<<"0"<<endl;
        else if(a==0)cout<<"0"<<endl;
        else cout<<(k-a)/b+1<<endl;
    }
    return 0;
}