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
    t=1;
    for(int q=1;q<=t;q++)
    {
        string s;
        cin>>s;
        int n=s.length();
        vector<int>v(n-1,0);
        for(int i=0;i<n-1;i++)
        {
            if(s[i]==s[i+1])v[i]=1;
        }
        int sum=0;
        vector<int>su(n-1);
        for(int i=0;i<n-1;i++)
        {
            sum+=v[i];
            su[i]=sum;
        }
        int m;
        cin>>m;
        for(int i=0;i<m;i++)
        {
            int l,r;
            cin>>l>>r;
            cout<<su[r-1-1]-su[l-1]+v[l-1]<<endl;
        }
    }
    return 0;
}