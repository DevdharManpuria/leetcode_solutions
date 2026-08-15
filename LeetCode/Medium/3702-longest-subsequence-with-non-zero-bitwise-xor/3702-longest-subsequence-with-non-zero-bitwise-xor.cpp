class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int ma=0;
        int xo=0;
        for(int i:nums){
            ma=max(ma,i);
            xo^=i;
        }
        return ma == 0 ? 0 : (xo == 0 ? nums.size()-1 : nums.size());
    }
};