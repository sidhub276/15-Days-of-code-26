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
        string s;
        cin>>s;
        int k=1;
        set<char>se;
        se.insert('a');
        se.insert('e');
        se.insert('i');
        se.insert('o');
        se.insert('u');
        for(int i=0;i<n-3;i++)
        {
            if(se.find(s[i])==se.end()&&se.find(s[i+1])==se.end()&&se.find(s[i+2])==se.end()&&se.find(s[i+3])==se.end())
            {
                k=0;
            }
        }
        if(k)cout<<"No"<<endl;
        else cout<<"Yes"<<endl;
    }
    return 0;
}