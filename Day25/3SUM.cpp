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
        vector<ll>v(n);
        map<int,int>m;
        for (int i=0;i<n;i++)
        {
            cin>>v[i];
            m[v[i]%10]++;
        }
        int k=0;
        if(m[1]>=3||(m[1]&&m[2]&&m[0])||(m[0]>=2&&m[3]))k=1;
        if((m[9]&&m[4]&&m[0])||(m[8]&&m[5]&&m[0])||(m[7]&&m[6]&&m[0])||((m[1]&&m[3]&&m[9]))||((m[1]&&m[4]&&m[8])))k=1;
        if((m[1]&&m[5]&&m[7])||(m[1]&&m[6]>1)||(m[2]>1&&m[9])||(m[3]&&m[2]&&m[8])||(m[4]&&m[2]&&m[7])||(m[5]&&m[2]&&m[6]))k=1;
        if((m[3]>1&&m[7])||(m[3]&&m[4]&&m[6])||(m[3]&&m[5]>1)||(m[5]&&m[9]>1)||(m[6]&&m[8]&&m[9])||(m[7]&&m[8]>1)||(m[9]&&m[7]>1)||(m[4]>1&&m[5]))k=1;
        if(k)cout<<"Yes"<<endl;
        else cout<<"No"<<endl;

        
    }
    return 0;
}