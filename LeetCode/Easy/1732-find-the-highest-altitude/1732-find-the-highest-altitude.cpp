class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int ans=INT_MIN;
        int alt=0;
        for(int i : gain){
            alt+=i;
            ans=max(alt,ans);
        }
        return ans > 0 ? ans : 0;
    }
};