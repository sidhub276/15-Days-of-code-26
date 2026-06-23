class Solution {
public:
    int maxSubArray(vector<int>& nums) 
    {
        vector<int>v=nums;
        sort(v.begin(),v.end());
        int n=v.size();
        if(v[n-1]<0)return v[n-1];
        v=nums;
        int cur=0;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(v[i]+cur>0)
            {
                cur+=v[i];
                ans=max(cur,ans);
            }
            else
            {
                cur=0;
            }
        }
        return ans;
    }
};