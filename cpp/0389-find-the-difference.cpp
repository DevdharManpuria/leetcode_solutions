class Solution {
public:
    char findTheDifference(string s, string t) {
        int char_count[26] = {0};

        for(char c : s){
            char_count[c - 'a']++;
        }

        for(char c : t){
            if(--char_count[c - 'a'] < 0){
                return c;
            }
        }

        return ' ';
    }
};