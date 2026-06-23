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
    int n,m;//n mean aahe aani m median
    cin>>n>>m;
    cout<<"3"<<endl;
    vector<int>v(3);
    v[1]=m;
    v[0]=m;
    int sum=n*3;
    v[2]=sum-2*m;
    for(auto x:v)
    {
        cout<<x<<" ";
    }
    return 0;
}