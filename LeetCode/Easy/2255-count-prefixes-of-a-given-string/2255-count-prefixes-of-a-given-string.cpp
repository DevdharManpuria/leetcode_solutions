class Solution {
public:
    int countPrefixes(vector<string>& words, string s) {
        int cnt = 0;
        for (auto &word : words)
            cnt += s.substr(0, word.size()) == word;
        return cnt;
    }
};