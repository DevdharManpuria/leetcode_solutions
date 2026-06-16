class Solution {
public:
    string processStr(string s) {
        string res;
        for(char c:s){
            if(c-'a'>=0 && c-'a'<=25) res.push_back(c);
            if(c=='*' && !res.empty()) res.pop_back();
            if(c=='#') res+=res;
            if(c=='%' && !res.empty()) reverse(res.begin(), res.end());
        }
        return res;
    }
};