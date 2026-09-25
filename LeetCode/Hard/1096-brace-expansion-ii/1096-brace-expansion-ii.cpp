class Solution {
public:
    vector<string> braceExpansionII(string expression) {
        int i = 0;
        set<string> res = parse(expression, i);
        return vector<string>(res.begin(), res.end());
    }
private:
    set<string> parse(const string& s, int& i) {
        set<string> curr;
        set<string> uni;
        curr.insert("");
        while(i<s.length() && s[i] != '}'){
            if(s[i]==','){
                uni.insert(curr.begin(),curr.end());
                curr.clear();
                curr.insert("");
                i++;
            }
            else{
                set<string> next;
                if(s[i] == '{'){
                    i++;
                    next=parse(s,i);
                    i++;
                }
                else {
                    next.insert(string(1, s[i]));
                    i++;
                }
                set<string> prod;
                for (const string& a : curr) {
                    for (const string& b : next) {
                        prod.insert(a + b);
                    }
                }
                curr = prod;
            }
        }
        uni.insert(curr.begin(), curr.end());
        return uni;
    }
};