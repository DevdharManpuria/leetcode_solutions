class Solution {
public:
    string removeOuterParentheses(string s) {
        int cnt =0;
        string ans="";
        for(char c:s){
            if(c=='(' && ++cnt>1) ans+="(";
            else if(c ==')' && cnt-->1) ans+=")"; 
        }
        return ans;
    }
};