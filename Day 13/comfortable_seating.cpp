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
        sort(v.begin(),v.end());
        if(m[v[0]]==1)cout<<"No"<<endl;
        else cout<<"Yes"<<endl;
    }
    return 0;
}