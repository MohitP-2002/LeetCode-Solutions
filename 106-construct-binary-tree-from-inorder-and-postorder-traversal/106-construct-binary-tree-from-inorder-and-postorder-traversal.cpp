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
    TreeNode* helper(vector<int> in, vector<int> post, int start, int end, int& p){
    if(start>end) return nullptr;
    TreeNode* node = new TreeNode(post[p]);
    p--;
    if(start==end) return node;
    int i;
    for(i=start;i<=end;i++){
        if(in[i]==node->val) break;
    }
    node->right=helper(in, post, i+1, end, p);
    node->left=helper(in, post, start, i-1,p);
    return node;
}
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        int p=n-1;;
        return helper(inorder,postorder,0,n-1,p);
    }
};