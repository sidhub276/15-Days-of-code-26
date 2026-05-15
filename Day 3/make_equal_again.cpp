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
        vector<int>v(n);
        for(int i=0;i<n;i++)
        {
            cin>>v[i];
        }
        int f=1;
        int b=1;
        for(int i=0;i<n-1;i++)
        {
            if(v[i]==v[i+1])f+=1;
            else break;
        }
        for(int i=n-1;i>0;i--)
        {
            if(v[i]==v[i-1])b+=1;
            else break;
        }
        if(v[0]==v[n-1])
        {
            if(b==f&&b==n)cout<<"0"<<endl;
            else cout<<n-b-f<<endl;
        }
        else cout<<n-max(b,f)<<endl;
    }
    return 0;
}