class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int m = *max_element(nums.begin(),nums.end());
        int ma=1,mi=1;
        for(int n:nums){
            int temp = ma*n;
            ma = max({temp,mi*n,n});
            mi = min({temp,mi*n,n});
            m = max(m,ma);
        }
        return m;
    }
};