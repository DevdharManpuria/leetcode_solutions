class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int d=0;
        vector<int> res;
        for(char& c:seq){
            if(c=='('){
                ++d;
                res.push_back(d%2);
            }
            else{
                res.push_back(d%2);
                --d;
            }
        }
        return res;
    }
};