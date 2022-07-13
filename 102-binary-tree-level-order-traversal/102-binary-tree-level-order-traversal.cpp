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
    vector<vector<int>> v;
    void preorder(TreeNode* root, int level){
        if(root==NULL) return;
        if(v.size()==level) v.push_back(vector<int>());
        
        v[level].push_back(root->val);
        preorder(root->left,level+1);
        preorder(root->right,level+1);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        preorder(root,0);
        return v;
    }
};