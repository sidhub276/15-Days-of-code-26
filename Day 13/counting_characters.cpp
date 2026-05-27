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
        int n;string s;
        cin>>n>>s;
        ll a=0,b=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='a')a+=1;
            else b+=1;
        }
        cout<<a<<" "<<b<<endl;
    }
    return 0;
}