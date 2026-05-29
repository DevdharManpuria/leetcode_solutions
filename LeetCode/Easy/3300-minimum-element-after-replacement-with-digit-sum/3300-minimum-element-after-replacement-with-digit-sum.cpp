class Solution {
public:
    int minElement(vector<int>& nums) {
        int ans=INT_MAX;
        for(int i=0;i<nums.size();i++){
            ans=min(ans,sumdigits(nums[i]));
        }
        return ans;
    }
    int sumdigits(int a){
        int ans=0;
        while(a){
            int d=a%10;
            ans+=d;
            a=a/10;
        }
        return ans;
    }
};