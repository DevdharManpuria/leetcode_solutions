class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long, int> hm;
        for (int i : nums) hm[i]++;
        int max_len = hm.count(1) ? hm[1] - (hm[1] % 2 == 0) : 1;
        hm.erase(1); 
        for (auto const& [key, val] : hm) {
            long long curr = key;
            int curr_len = 0;
            while (hm.count(curr) && hm[curr] >= 2) {
                curr_len += 2;
                curr *= curr;
            }
            max_len = max(max_len, curr_len + (hm.count(curr) ? 1 : -1));
        }
        return max(1, max_len);
    }
};