class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) 
    {
        vector<vector<int>>ans;
        sort(intervals.begin(),intervals.end());
        int n=intervals.size();
        int curs=intervals[0][0];
        int curl=intervals[0][1];
        for(int i=1;i<n;i++)
        {
            if(intervals[i][0]<=curl)
            {
                curl=max(curl,intervals[i][1]);
            }
            else
            {
                ans.push_back({curs,curl});
                curs=intervals[i][0];
                curl=intervals[i][1];
            }
        }
        ans.push_back({curs,curl});
        return ans;
    }
};