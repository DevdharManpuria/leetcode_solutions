class Solution {
public:
    long long findKthSmallest(vector<int>& coins, int k) {
        int n = coins.size();
        vector<long long> ol, el;        
        for (int i = 1; i < (1 << n); i++) {
            long long cur = 1;
            int se = 0;
            for (int j = 0; j < n; j++) {
                if ((i >> j) & 1) {
                    cur = lcm(cur, (long long)coins[j]);
                    se++;
                }
            }
            if (se % 2 != 0) 
                ol.push_back(cur);
            else 
                el.push_back(cur);
        }
        long long le = 1;
        long long mi = *min_element(coins.begin(), coins.end());
        long long ri = (long long)k * mi; 
        long long ans = ri;
        while (le <= ri) {
            long long mid = le + (ri - le) / 2;
            long long count = 0;
            for (long long l : ol) count += mid / l;
            for (long long l : el) count -= mid / l;
            if (count >= k) {
                ans = mid;
                ri = mid - 1; 
            }
            else le = mid + 1;  
        }
        return ans;
    }
};