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
        string s;
        cin>>s;
        int n=s.length();
        ll l4=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='1')s[i]='3';
            if(s[i]=='4')l4+=1;
        }
        int c=-1;
        int cur=0;
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='4') continue;

            if(c==-1)
            {
                c = s[i]-'0';
                cur = 1;
                continue;
            }
            if(s[i]-'0'==c)
            {
                cur++;
            }
            else
            {
                v.push_back({c,cur});
                c = s[i]-'0';
                cur = 1;
            }
        }
        v.push_back({c,cur});
        ll t2=0;
        for(auto x:v)
        {
            if(x.first==2)t2+=x.second;
        }
        ll p3=0;
        ll sid=t2;  
        for(auto x:v)
        {
            if(x.first==3)
            {
                p3+=x.second;
            }
            else
            {
                t2-=x.second;
            }
            sid=min(sid,p3+t2);
        }
        ll ans=l4+sid;
        cout<<ans<<endl;
    }
    return 0;
}