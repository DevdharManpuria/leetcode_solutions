class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int ans=0;
        for(int i: nums)
        if (to_string(i).size()%2==0)
        ans++;
        return ans;
    }
};