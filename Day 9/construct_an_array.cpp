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
        int a=2*n;
        int b=n/2*2+1;
        for(int i=1;i<=n;i++)
        {
            if(i%2==0)
            {
                cout<<a<<" ";
                a-=2;
            }
            else 
            {
                cout<<b<<" ";
                b-=2;
            }
        }
        cout<<endl;
    }
    return 0;
}