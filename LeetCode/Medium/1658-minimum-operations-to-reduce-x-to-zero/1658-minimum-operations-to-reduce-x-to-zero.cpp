class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int k = reduce(nums.begin(),nums.end()) -x,n=nums.size();
        if(k<0) return -1;
        if(k == 0) return n;
        int best = -1;
        int i=0,sum=0;
        for(int j=0;j<n;j++){
            sum+=nums[j];
            while(sum>k){
                sum-= nums[i++];
            }
            if(sum==k) best = max(best,j-i+1);
        }
        return best+1 ? n-best : -1;
    }
};