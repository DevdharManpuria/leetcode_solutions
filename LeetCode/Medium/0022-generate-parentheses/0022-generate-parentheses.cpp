class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string stack;      
        backtrack(0,0,n,res,stack);
        return res;  
    }
    void backtrack(int o,int c,int n,vector<string>&res,string& stack){
        if(o==c && o==n){
            res.push_back(stack);
            return;
        }
        if(o<n){
            stack+='(';
            backtrack(o+1,c,n,res,stack);
            stack.pop_back();
        }
        if(c<o){
            stack+=')';
            backtrack(o,c+1,n,res,stack);
            stack.pop_back();
        }
    }
};