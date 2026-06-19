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
        int m,n;
        cin>>m>>n;
        if(n<=m)cout<<m-n<<endl;
        else
        {
            int mini=m;
            for(int i=0;i<=n/3;i++)
            {
                int dra=n-(i*3);
                if(dra<0)continue;
                int lose=m-dra-i;
                if(lose<0)continue;
                if(i+dra+lose==m)
                {
                    mini=min(mini,lose);
                }
            }
            cout<<mini<<endl;
        }
    }
    return 0;
}