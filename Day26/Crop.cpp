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
    int h,w;
    cin>>h>>w;
    char arr[h][w];
    for(int i=0;i<h;i++)
    {
        forn(j,0,w)cin>>arr[i][j];
    }
    int up=-1,down=h,ri=w,left=-1;
    for(int i=0;i<h;i++)
    {
        int k=1;
        for(int j=0;j<w;j++)
        {
            if(arr[i][j]=='#')
            {
                k=0;
                break;
            }
        }
        if(k)up=i;
        else
        {
            break;
        }
    }
    for(int i=h-1;i>=0;i--)
    {
        int k=1;
        for(int j=0;j<w;j++)
        {
            if(arr[i][j]=='#')
            {
                k=0;
                break;
            }
        }
        if(k)down=i;
        else
        {
            break;
        }
    }
    for(int j=0;j<w;j++)
    {
        int k=1;
        for(int i=0;i<h;i++)
        {
            if(arr[i][j]=='#')
            {
                k=0;
                break;
            }
        }
        if(k)left=j;
        else
        {
            break;
        }
    }
    for(int j=w-1;j>=0;j--)
    {
        int k=1;
        for(int i=0;i<h;i++)
        {
            if(arr[i][j]=='#')
            {
                k=0;
                break;
            }
        }
        if(k)ri=j;
        else
        {
            break;
        }
    }
    forn(i,0,h)
    {
        int k=0;
        forn(j,0,w)
        {
            if(i>up&&i<down&&j<ri&&j>left)
            {
                cout<<arr[i][j];k=1;
            }
        }
        if(k)cout<<endl;
    }
    return 0;
}