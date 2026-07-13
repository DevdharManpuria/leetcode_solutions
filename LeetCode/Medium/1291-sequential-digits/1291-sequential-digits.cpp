class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> memo;
        for(int i=1;i<=9;++i){
            int n = i;
            for(int j=n+1;j<=9;++j){
                n=n*10 + j;
                memo.push_back(n);
            }
        }    
        sort(memo.begin(),memo.end());
        vector<int> ans;
        for(auto& a:memo)
            if(a>=low && a<=high)   ans.push_back(a);
        return ans;
    }
};