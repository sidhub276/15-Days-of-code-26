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
        vll a(n),b(n);
        forn(i,0,n)cin>>a[i];
        forn(i,0,n)cin>>b[i];
        ll na=0,nb=0,aa=0,bb=0;
        for(int i=0;i<n;i++)
        {
            if(a[i]==1)na+=1;
            if(b[i]==1)nb+=1;
            if(a[i]!=b[i])
            {
                if((i+1)%2==0)bb+=1;
                else aa+=1;
            }
        }
        ll last=-1,seclast=-1;
        ll cnt=0;
        for(int i=n-1;i>=0;i--)
        {
            if(a[i]!=b[i])
            {
                if(last==-1)last=i+1;
                cnt+=1;
            }
        }
        if(cnt%2==0)cout<<"Tie"<<endl;
        else if(cnt==0)
        {
            na%=2;
                nb%=2;
                if(na==1&&nb==0)cout<<"Ajisai"<<endl;
                else if(na==0&&nb==1)cout<<"Mai"<<endl;
                else cout<<"Tie"<<endl;
        }
        else
        {
            if(last%2==0)cout<<"Mai"<<endl;
            else cout<<"Ajisai"<<endl;
        }
        // if(seclast==-1)
        // {
        //     if(last==-1)
        //     {
        //         na%=2;
        //         nb%=2;
        //         if(na==1&&nb==0)cout<<"Ajisai"<<endl;
        //         else if(na==0&&nb==1)cout<<"Mai"<<endl;
        //         else cout<<"Tie"<<endl;
        //     }
        //     else 
        //     {
        //         if(last%2==1)cout<<"Ajisai"<<endl;
        //         else cout<<"Mai"<<endl;
        //     }
        // }
        // else
        // {
        //     if(last%2==seclast%2)
        //     {
        //         if(last%2==0)cout<<"Mai"<<endl;
        //         else cout<<"Ajisai"<<endl;
        //     }
        //     else if(aa==bb)cout<<"Tie"<<endl;
        //     else if(aa>bb)cout<<"Ajisai"<<endl;
        //     else cout<<"Mai"<<endl;
        // }
    }
    return 0;
}