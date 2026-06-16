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
        string s;
        cin>>s;
        int n=s.length();
        vector<int>wa;
        vector<int>wb;
        int k1=0;
        int k2=0;
        for(int i=0;i<n;i++)
        {
            if((i+1)%2==1&&s[i]!='a')wa.emplace_back(i+1);
            if((i+1)%2==0&&s[i]!='b')wa.emplace_back(i+1);
            if((i+1)%2==0&&s[i]!='a')wb.emplace_back(i+1);
            if((i+1)%2==1&&s[i]!='b')wb.emplace_back(i+1);
        }
        int na=wa.size();
        int nb=wb.size();
        if(na<=1||nb<=1)
        {
            cout<<"Yes"<<endl;
            continue;
        }
        int al=wa[0];
        int ag=wa.back();
        int bl=wb[0];
        int bg=wb.back();
        int k=1;
        for(int i=al-1;i<ag;i++)
        {
            if((i+1)%2==0&&s[i]!='a')k=0;
            if((i+1)%2==1&&s[i]!='b')k=0;
        }
        if(k==1)
        {
            cout<<"Yes"<<endl;continue;
        }
        k=1;
        for(int i=bl-1;i<bg;i++)
        {
            if((i+1)%2==0&&s[i]=='a')k=0;
            if((i+1)%2==1&&s[i]=='b')k=0;
        }
        if(k==1)
        {
            cout<<"Yes"<<endl;continue;
        }
        cout<<"No"<<endl;
    }
    return 0;
}