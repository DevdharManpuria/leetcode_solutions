class Solution {
public:
    string smallestPalindrome(string s) {
        int freq[26] = {0};
        for (char ch : s) 
            freq[ch - 'a']++;
        string l = "";
        string m = "";
        for(int i = 0; i < 26; i++){
            if(freq[i] == 0) continue;
            char ch = i + 'a';
            if(freq[i] % 2 != 0) {
                m = ch;
            }
            l.append(freq[i] / 2, ch);
        }
        string r = l;
        reverse(r.begin(), r.end());
        return l + m + r;
    }
};
