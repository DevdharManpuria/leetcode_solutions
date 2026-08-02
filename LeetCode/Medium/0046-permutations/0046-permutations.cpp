class Solution {
    vector<vector<int>> res;
public:
    vector<vector<int>> permute(vector<int>& nums) {
        backtrack(nums,0);
        return res;
    }
    void backtrack(vector<int>& nu,int idx){
        if(idx==nu.size()){
            res.push_back(nu);
            return;
        }
        for(int i=idx;i<nu.size();i++){
            swap(nu[idx],nu[i]);
            backtrack(nu,idx+1);
            swap(nu[idx],nu[i]);
        }
    }
};