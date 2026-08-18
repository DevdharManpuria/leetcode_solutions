class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        if (k == nums.size()) return *max_element(nums.begin(), nums.end());
        unordered_map<int, int> mp;
        for (int x : nums) mp[x]++;
        if (k == 1) {
            int ans = -1;
            for (auto& [val, freq] : mp) {
                if (freq == 1) ans = max(ans, val);
            }
            return ans;
        }
        int first = (mp[nums.front()] == 1) ? nums.front() : -1;
        int last = (mp[nums.back()] == 1) ? nums.back() : -1;
        return max(first, last);
    }
};
