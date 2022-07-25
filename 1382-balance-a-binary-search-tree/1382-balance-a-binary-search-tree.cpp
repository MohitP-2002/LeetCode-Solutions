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
    vector<int> nums;
    void inorder(TreeNode* root){
        if(!root) return;
        inorder(root->left);
        nums.push_back(root->val);
        inorder(root->right);
    }
    TreeNode* solver(vector<int> nums,int start,int end){
        if(start>end) return NULL;
        int mid=(start+end)/2;
        TreeNode* root= new TreeNode(nums[mid]);
        root->left=solver(nums,start,mid-1);
        root->right=solver(nums,mid+1,end);
        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
        inorder(root);
        int start=0,end=nums.size()-1;
        return solver(nums,start,end);
    }
};