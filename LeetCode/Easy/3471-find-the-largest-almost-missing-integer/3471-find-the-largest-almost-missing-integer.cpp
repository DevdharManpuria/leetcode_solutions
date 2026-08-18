class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for (int i : nums) mp[i]++;
        int m = -1;
        int mo = -1;
        for (auto& it : mp) {
            if (it.second == 1) m = max(m, it.first);
            mo = max(mo, it.first);
        }
        if (k == 1) return m;
        if (k == nums.size()) return mo;
        if (mp[nums[0]] > 1 && mp[nums[nums.size() - 1]] > 1) 
            return -1;
        else if (mp[nums[0]] > 1 && mp[nums[nums.size() - 1]] == 1) 
            return nums[nums.size() - 1];
        else if (mp[nums[0]] == 1 && mp[nums[nums.size() - 1]] > 1) 
            return nums[0];
        else 
            return max(nums[0], nums[nums.size() - 1]);
    }
};
