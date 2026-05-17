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
        map<int,int>m;
        for (int i=0;i<n;i++)
        {
            cin>>v[i];
            m[v[i]]++;
        }
        int ans=m[0]+min(m[1],m[2]);
        ans+=(max(m[1],m[2])-min(m[1],m[2]))/3;
        cout<<ans<<endl;
    }
    return 0;
}