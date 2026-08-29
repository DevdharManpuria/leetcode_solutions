class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        if(nums.size() == 0) return ans;
        int a = nums[0];
        for(int i=1;i<=nums.size();i++){
            if(i == nums.size() || nums[i] != (long long)nums[i-1]+1){
                if(a == nums[i-1]) ans.push_back(to_string(a));
                else ans.push_back(to_string(a) + "->" + to_string(nums[i-1]));
                if(i<nums.size()) a = nums[i];
            }
        }
        return ans;
    }
};