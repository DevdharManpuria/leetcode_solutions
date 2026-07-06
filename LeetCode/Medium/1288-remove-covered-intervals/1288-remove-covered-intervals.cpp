class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& it) {
        sort(it.begin(), it.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[0] == b[0]) {
                return a[1] > b[1];
            }
            return a[0] < b[0];
        });
        int ans=0;
        int me=0;
        for(int i=0;i<it.size();i++){
            if(it[i][1]>me){
                me=it[i][1];
                ans++;
            }
        }
        return ans;
    }
};