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
        int i=0;
        int j=n-1;
        int a=v[n/2-1];
        int b=v[n/2];
        int k=1;
        while(i<j)
        {
            if(a-v[i]!=v[j]-b)k=0;
            i++;
            j--;
        }
        if(k==0)cout<<"No"<<endl;
        else cout<<"Yes"<<endl;
    }
    return 0;
}