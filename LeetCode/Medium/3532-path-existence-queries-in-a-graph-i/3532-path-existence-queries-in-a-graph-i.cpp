class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int> comp(n,0);
        for(int i=1;i<n;i++)
            comp[i] = nums[i]-nums[i-1]<=maxDiff ? comp[i-1] : comp[i-1]+1;
        vector<bool> ans(queries.size());
        for(int i=0;i<queries.size();i++){
            int f=queries[i][0];
            int s=queries[i][1];
            ans[i] = (comp[f] == comp[s]);
        }
        return ans;
    }
};