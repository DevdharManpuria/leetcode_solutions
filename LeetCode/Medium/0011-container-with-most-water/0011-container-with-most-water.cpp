class Solution {
public:
    int maxArea(vector<int>& height) {
        int l=0,r=height.size()-1,area=0,temp=0;
        while(l<r){
            temp = min(height[l],height[r])*(r-l);
            (height[l] > height[r]) ? --r : ++l;
            area = max(area,temp);
        }
        return area;
    }
};