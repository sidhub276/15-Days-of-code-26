class Solution {
public:
    int countPrimes(int n) 
    {
        if(n<=2)return 0;
        vector<int>prime(n,1);
        prime[0]=0;
        prime[1]=0;
        for(int i=2;i<n;i++)
        {
            if(prime[i]==0)continue;
            for(long long j=1LL*i*i;j<n;j+=i)
            {
                prime[j]=0;
            }
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(prime[i]==1)ans+=1;
        }
        return ans;
    }
};