class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int l=0;
        int r=n-1;
        int lm=height[l],rm=height[r];
        int trap=0;
        while(l<r){
            if(lm<rm){
                l++;
                lm=max(lm,height[l]);
                trap+=lm-height[l];
            }
            else{
                r--;
                rm=max(rm,height[r]);
                trap+=rm-height[r];
            }
        }
        return trap;
    }
};