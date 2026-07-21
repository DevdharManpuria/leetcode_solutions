class Solution {
public:
    int countPrefixes(vector<string>& words, string s) {
        int cnt = 0;
        for (string &word : words) {
            if (word.size() > s.size()) continue;
            bool ok = true;
            for (int i = 0; i < word.size(); i++) {
                if (word[i] != s[i]) {
                    ok = false;
                    break;
                }
            }
            if (ok) cnt++;
        }
        return cnt;
    }
};