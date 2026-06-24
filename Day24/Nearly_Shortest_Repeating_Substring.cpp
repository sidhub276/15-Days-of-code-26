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
#define ll long long
#define vll vector<ll>
#define pll pair<ll,ll>
#define vpll vector<pair<ll,ll>>
#define endl "\n"
#define forn(i,a,b) for(int i=(int)a;i<(int)b;i++)
#define ini ll n; cin>>n;
#define all(v) v.begin(),v.end()
#define sp " "
#define vout(v) forn(i,0,v.size()) cout<<v[i]<<(i==v.size()-1?endl:sp)
int main()  
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    for(int q=1;q<=t;q++)
    {
        ini;
        string s;
        cin>>s;
        vll v;
        for(ll i=1;i*i<=n;i++)
        {
            if(n%i==0)
            {
                v.emplace_back(i);
                v.emplace_back(n/i);
            }
        }
        sort(v.begin(),v.end());
        for(auto x:v)
        {
            ll parts=n/x;
            if(parts==1)
            {
                cout<<n<<endl;
                break;
            }
            if(parts==2)
            {
                ll bad=0;
                for(int i=0;i<n/parts;i++)
                {
                    if(s[i]!=s[i+n/parts])bad+=1;
                }
                if(bad<=1)
                {
                    cout<<x<<endl;
                    break;
                }
            }
            else
            {
                ll bad12=0;
                for(int i=0;i<n/parts;i++)
                {
                    if(s[i]!=s[i+n/parts])bad12+=1;
                }
                ll bad23=0;
                for(int i=n/parts;i<2*n/parts;i++)
                {
                    if(s[i]!=s[i+n/parts])bad23+=1;
                }
                ll bad13=0;
                for(int i=0;i<n/parts;i++)
                {
                    if(s[i]!=s[i+2*n/parts])bad13+=1;
                }
                string curs="";
                if(bad12==0||bad13==0)
                {
                    curs=s.substr(0,n/parts);
                }
                else if(bad23==0)
                {
                    curs=s.substr(n/parts,2*n/parts);
                }
                if(curs=="")continue;
                ll finalbad=0;
                for(int i=0;i<n;i++)
                {
                    if(s[i]!=curs[i%(n/parts)])finalbad+=1;
                }
                if(finalbad<=1)
                {
                    cout<<x<<endl;
                    break;
                }
            }
        }
    }
    return 0;
}