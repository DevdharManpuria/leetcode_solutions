class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        vector<int> ans;
        dfs(root,ans);
        return ans[k-1];
    }
    void dfs(TreeNode* r,vector<int>& a){
        if(!r) return;
        dfs(r->left,a);
        a.push_back(r->val);
        dfs(r->right,a);
    }
};