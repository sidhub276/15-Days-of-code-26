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
    for(int qq=1;qq<=t;qq++)
    {
        int n,m,q;
        cin>>n>>m>>q;
        vector<int>v(m);
        for(int i=0;i<m;i++)
        {
            cin>>v[i];
        }
        sort(v.begin(),v.end());
        for(int i=0;i<q;i++)
        {
            int p;
            cin>>p;
            if(binary_search(v.begin(),v.end(),p)==true)
            {
                cout<<"0"<<endl;
                continue;
            }
            auto itu=upper_bound(v.begin(),v.end(),p);
            auto itl=lower_bound(v.begin(),v.end(),p);
            int up,down;
            if(itu==v.end())
            {
                cout<<n-v.back()<<endl;
                continue;
            }
            else up=*itu;
            if(itl==v.begin())
            {
                cout<<up-1<<endl;
                continue;
            }
            else down=itl-v.begin();
            int d=v[down-1];
            cout<<(up-d)/2<<endl;
        }
    }
    return 0;
}