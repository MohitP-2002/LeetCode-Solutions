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
    TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int& start, int left, int right)     {
        if(left>right) return NULL;
        int pivot=left;
        while(preorder[start]!=inorder[pivot])pivot++;
        TreeNode* root = new TreeNode(inorder[pivot]);        
        start++;
        root->left=helper(preorder,inorder,start,left,pivot-1);
        root->right=helper(preorder,inorder,start,pivot+1,right);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
         int start=0;
         return helper(preorder,inorder,start,0,inorder.size()-1);
    }
};