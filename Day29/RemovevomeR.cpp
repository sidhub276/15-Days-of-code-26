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
        int n;
        cin>>n;
        string s;
        cin>>s;
        int nn=0;
        char cur=s[0];
        forn(i,0,n)
        {
            if(s[i]!=cur)
            {
                nn+=1;
                cur=s[i];
            }
        }
        nn+=1;
        if(nn==2)cout<<"2"<<endl;
        else cout<<"1"<<endl;
    }
    return 0;
}