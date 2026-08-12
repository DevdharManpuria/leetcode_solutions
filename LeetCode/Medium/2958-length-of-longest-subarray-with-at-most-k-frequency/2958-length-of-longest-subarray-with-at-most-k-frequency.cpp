class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size(); 
        unordered_map<int, int> hm; 
        int s = 0;
        int cnt = 0;
        for (int h = 0; h < n; h++) {
            hm[nums[h]]++;
            if (hm[nums[h]] == k + 1)
                cnt++;
            if (cnt > 0) {
                hm[nums[s]]--;
                if (hm[nums[s]] == k)
                    cnt--;
                s++;
            }
        }
        return n - s;
    }
};