class Solution {
public:
    string getPermutation(int n, int k) 
    {
        vector<char>v;
        for(int i=0;i<n;i++)
        {
            v.push_back('1'+i);
        }
        int nn=n;
        vector<int>fact(10);
        fact[0]=1;
        fact[1]=1;
        for(int i=2;i<10;i++)
        {
            fact[i]=fact[i-1]*i;
        }
        string ans="";
        k--;
        for(int i=nn;i>0;i--)
        {
            int c=fact[i-1];
            int a=k/c;
            ans+=v[a];
            v.erase(v.begin()+a);
            k=k%c;
        }
        return ans;
    }
};