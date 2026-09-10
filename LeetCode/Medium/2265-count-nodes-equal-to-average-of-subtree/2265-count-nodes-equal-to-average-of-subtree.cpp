/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
int count =0;
    pair<int,int> po(TreeNode* root){
        if(root == NULL){
            return{0,0};
        }
        pair<int,int> left = po(root->left);
        pair<int,int> right = po(root->right);
        int nodesum = left.first+right.first+root->val;
        int nodecount = left.second + right.second +1;
        if(root-> val == nodesum/(nodecount)) count++;
        return {nodesum,nodecount};
    }
    int averageOfSubtree(TreeNode* root) {
        po(root);
        return count;
    }
};