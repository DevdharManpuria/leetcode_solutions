class Solution {
public:
    int sumdig(int x){
        int copy = x,sum=0;
        while(copy>0){
            int d = copy%10;
            sum+=d;
            copy/=10;
        }
        return sum;
    }
    int smallestIndex(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            if(sumdig(nums[i]) == i) return i;
        }
        return -1;
    }
};