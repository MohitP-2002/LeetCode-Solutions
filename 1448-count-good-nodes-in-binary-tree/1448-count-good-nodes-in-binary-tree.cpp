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
    void traverse(TreeNode* root, int max, int& count){
        if(!root) return;
        if(root->val>=max) {
            max=root->val;
            count++;
        }
        traverse(root->left, max, count);
        traverse(root->right, max, count);
    }
    int goodNodes(TreeNode* root) {
        if(!root) return 0;
        int  count=0;
        traverse(root, root->val, count);
        return count;
    }
};