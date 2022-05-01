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
    void rightView(TreeNode* root, vector<int> & v,int level, int *maxlevel){
        if(root==nullptr) return ;
        if(*maxlevel<level){
            v.push_back(root->val);
            *maxlevel=level;
        }
        rightView(root->right, v, level+1,maxlevel);
        rightView(root->left,v,level+1,maxlevel);
    }
    vector<int> rightSideView(TreeNode* root) {
        if(root==nullptr) return vector<int>();
        vector<int> v;
        int maxlevel=0;
        v.push_back(root->val);
        rightView(root,v,0,&maxlevel);
        return v;
    }
};