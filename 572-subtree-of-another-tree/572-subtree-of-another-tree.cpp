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
    
    bool isEqual(TreeNode* root, TreeNode* subRoot){
        if(root==nullptr && subRoot==nullptr){
            return true;
        }
        if(root==nullptr || subRoot==nullptr) return false;
        if(root->val!=subRoot->val){
            return false;
        }
        return isEqual(root->left, subRoot->left) && isEqual(root->right,subRoot->right);
    }
    
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root==NULL && subRoot==NULL) return true;
        if(root==NULL) return false;
        if(isEqual(root,subRoot)){
            return true;
        }
        return isSubtree(root->left, subRoot)||
            isSubtree(root->right, subRoot);
    }
};