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
    int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL) return 0;
        queue<pair<TreeNode*, int>> q;
        q.push({root,0});
        int ans=0;
        while(!q.empty()){
            int size=q.size();
            int first,last;
            for(int i=0;i<size;i++){
                unsigned int cur=q.front().second;
                if(i==0) first=cur;
                if(i==size-1) last=cur;
                if(q.front().first->left){
                    q.push({q.front().first->left,2*cur+1});
                }
                if(q.front().first->right){
                    q.push({q.front().first->right,2*cur+2});
                }
                q.pop();
            }
            ans=max(ans, last-first+1);
        }
        return ans;
    }
};