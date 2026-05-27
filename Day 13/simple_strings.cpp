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
    string s;
    cin>>s;
    ll n=s.length();
    vector<pair<char,ll>>fre;
    ll curl=0;
    char cur=s[0];
    for(ll i=0;i<n;i++)
    {
        if(s[i]==cur)
        {
            curl+=1;
        }
        else 
        {
            fre.emplace_back(cur,curl);
            curl=1;
            cur=s[i];
        }
    }
    fre.emplace_back(cur,curl);
    ll nn=fre.size();
    string ans="";
    for(ll i=0;i<nn;i++)
    {
        if(fre[i].second==1)
        {
            ans+=fre[i].first;
            continue;
        }
        char ne;
        set<char>fin;
        if(i>0)fin.insert(fre[i-1].first);
        if(i<n-1)fin.insert(fre[i+1].first);
        fin.insert(fre[i].first);
        for(int j=0;j<26;j++)
        {
            if(fin.find('a'+j)==fin.end())
            {
                ne='a'+j;
                break;
            }
        }
        for(int j=1;j<=fre[i].second;j++)
        {
            if(j%2==1)ans+=fre[i].first;
            else ans+=ne;
        }
    }
    cout<<ans<<endl;
    return 0;
}