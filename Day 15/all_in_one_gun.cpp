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
    ll t;
    cin>>t;
    for(ll q=1;q<=t;q++)
    {
        ll n,h,k;
        cin>>n>>h>>k;
        vector<ll>v(n);
        ll sum=0;
        for(int i=0;i<n;i++)
        {
            cin>>v[i];
            sum+=v[i];
        }
        vector<ll>maxel(n);
        vector<ll>minel(n);
        ll maxi=v[n-1];
        for(int i=n-1;i>=0;i--)
        {
            maxi=max(maxi,v[i]);
            maxel[i]=maxi;
        }
        ll mini=v[0];
        for(int i=0;i<n;i++)
        {
            mini=min(v[i],mini);
            minel[i]=mini;
        }
        ll hh=h%sum;
        if(hh==0)
        {
            cout<<(h/sum)*n+(h/sum-1)*k<<endl;
            continue;
        }
        ll news=0;
        ll chota=n+1;
        for(int i=0;i<n-1;i++)
        {
            news+=v[i];
            ll cc=news;
            if(i!=n-1)
            {
                if(maxel[i+1]>minel[i])
                {
                    news-=minel[i];
                    news+=maxel[i+1];
                    if(hh<=news)
                    {
                        chota=i+1;
                        break;
                    }
                    else news=cc;
                }
                else if(hh<=news)
                {
                    chota=i+1;
                    break;
                }
            }
        }
        cout<<(h/sum)*(n+k)+min(chota,n)<<endl;
    }
    return 0;
}