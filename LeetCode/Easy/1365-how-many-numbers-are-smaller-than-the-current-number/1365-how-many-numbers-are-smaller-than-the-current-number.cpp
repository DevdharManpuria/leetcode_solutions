class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> s = nums, ans;
        sort(s.begin(), s.end());
        unordered_map<int, int> m;
        for (int i = 0; i < s.size(); i++) {
            if (m.find(s[i]) == m.end()) {
                m[s[i]] = i;
            }
        }
        for (int x : nums) {
            ans.push_back(m[x]);
        }
        return ans;
    }
};
