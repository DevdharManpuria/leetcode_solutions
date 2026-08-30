class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end());
        long long last = (long long)INT_MIN-1;
        int ans = 0;
        for(int i=0;i<points.size();i++){
            if(last<points[i][0]){
                ans++;
                last = points[i][1];
            }
            else last = min(last,(long long)points[i][1]);
        }
        return ans;
    }
};