class Solution {
public:
    int minAddToMakeValid(string s) {
        int a = 0,cnt=0;
        stack<char> st;
        for(char c:s){
            if(c == '(') a++;
            else{
                if(a) a--;
                else cnt++;
            }
        }
        return a+cnt;
    }
};