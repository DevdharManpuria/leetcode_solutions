class Solution {
public:
    string minWindow(string s, string t) {
        if(t.length()>s.length()) return "";
        unordered_map<char, int> countst;
        int l=0;int r=0;
        for(char c:t){
            countst[c]++;
        }
        unordered_map<char, int> countcurr;
        int have=0;
        int need=countst.size();
        int min_len = INT_MAX;
        int start = -1;
        while(r<s.length()){
            char c=s[r];
            countcurr[c]++;
            if(countst.count(c) && countcurr[c]==countst[c]) have++;
            while(have == need){
                if((r - l + 1)< min_len){
                    min_len=r-l+1;
                    start=l;
                }
                char left = s[l];
                countcurr[left]--;
                if(countst.count(left) && countcurr[left]<countst[left]) have--;
                l++;
            }
            r++;
        }
        return min_len == INT_MAX ? "" : s.substr(start,min_len);
    }
};