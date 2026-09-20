class Solution {
public:
    int reverseDegree(string s) {
        int ans = 0;
        for(int i=0;i<s.size();i++){
            int a = 26-(s[i] - 'a');
            ans+=a*(i+1);
        }
        return ans;
    }
};