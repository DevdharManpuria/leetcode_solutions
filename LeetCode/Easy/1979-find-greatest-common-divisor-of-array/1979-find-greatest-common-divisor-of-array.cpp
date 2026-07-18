class Solution {
public:
    int findGCD(vector<int>& nums) {
        int mn = INT_MAX;
        int mx = INT_MIN;
        for(int i : nums){
            mn = min(i,mn);
            mx = max(i,mx);
        }
        int ans = 0;
        for(int i = 1;i<=mn;i++){
            if(mn%i == 0 && mx%i == 0)
                ans = i;
        }
        return ans;
    }
};