class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        if (nums.empty()) return {};
        int mn = nums[0], mx = nums[0];
        for (int x : nums) {
            mn = min(mn, x);
            mx = max(mx, x);
        }
        vector<bool> has(mx - mn + 1, false);
        for (int x : nums) {
            has[x - mn] = true;
        }
        vector<int> ans;
        for (int i = 0; i < has.size(); i++) {
            if (!has[i]) {
                ans.push_back(mn + i);
            }
        }
        return ans;
    }
};
