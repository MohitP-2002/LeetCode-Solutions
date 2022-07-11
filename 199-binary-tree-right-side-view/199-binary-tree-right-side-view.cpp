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
    int maxLevel=0;
    void rightView(TreeNode* root, vector<int>& v, int level){
        if(!root) return;
        if(level>maxLevel){
            v.push_back(root->val);
            maxLevel=level;
        }
        rightView(root->right, v, level+1);
        rightView(root->left, v, level+1);
    }
    vector<int> rightSideView(TreeNode* root) {
        if(!root) return {};
        vector<int> v;
        v.push_back(root->val);
        rightView(root, v, 0);
        return v;
    }
};