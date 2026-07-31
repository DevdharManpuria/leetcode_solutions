class Solution {
public:
    int minimumPushes(string word) {
        vector<int> cnt(26,0);
        for(char c : word){
            cnt[c-'a']++;
        }
        sort(cnt.rbegin(),cnt.rend());
        int mult = 1;
        int ans = 0;
        for(int i=0;i<26;i++){
            if(i>0 && i%8 == 0) mult++;
            ans += mult*cnt[i];
        }
        return ans;
    }
};