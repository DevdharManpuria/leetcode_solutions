class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int> comp(n,0);
        vector<bool> ans;
        for(int i=1;i<n;i++)
            comp[i] = nums[i]-nums[i-1]<=maxDiff ? comp[i-1] : comp[i-1]+1;
        for(auto& a: queries)
            ans.push_back(comp[a[0]] == comp[a[1]]);
        return ans;
    }
};