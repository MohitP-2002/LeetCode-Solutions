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
    
    int solver(TreeNode* root,int& res){
        if(root==nullptr) return 0;
        int l=solver(root->left,res);
        int r=solver(root->right,res);
        int temp=max(l,r) + root->val;
        temp=max(temp,root->val);
        int ans=max(temp,l+r+root->val);
        res=max(res,ans);
        return temp;
    }
    
    int maxPathSum(TreeNode* root) {
        if(root==NULL) return 0;
        int res=INT_MIN;
        solver(root,res);
        return res;
    }
};