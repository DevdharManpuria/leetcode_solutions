class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<pair<int, int>> valueWithIndex;
        for (int i = 0; i < nums.size(); ++i) {
            valueWithIndex.push_back({nums[i], i});
        }

        sort(valueWithIndex.begin(), valueWithIndex.end(),
             [](const pair<int, int>& a, const pair<int, int>& b) {
                 return a.first > b.first;
             });

        vector<pair<int, int>> topK(valueWithIndex.begin(), valueWithIndex.begin() + k);

        sort(topK.begin(), topK.end(),
             [](const pair<int, int>& a, const pair<int, int>& b) {
                 return a.second < b.second;
             });

        vector<int> result;
        for (const auto& p : topK) {
            result.push_back(p.first);
        }
        return result;
    }
};
