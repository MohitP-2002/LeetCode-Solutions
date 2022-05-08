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
   void helper(TreeNode* root,vector<int> arr,vector<vector<int>> &ans)
    {
        if(!root)
            return;
        arr.push_back(root->val);
        if(root->left==NULL && root->right==NULL)
        {
           /*This will be only true when the node is leaf node
             and hence we will update our ans vector by inserting
             vector arr which have one unique path from root to leaf*/
           ans.push_back(arr);
           //after that we will return since we don't want to check after leaf node
            return;
        }
        /*recursively going left and right until we find the leaf and updating the arr
        and ans vector simultaneously*/
        helper(root->left,arr,ans);
        helper(root->right,arr,ans);
    }
    int sumNumbers(TreeNode* root) {
        vector<int> arr;
        vector<vector<int>>ans;
        int sum=0;
        helper(root,arr,ans);
        for(int i=0;i<ans.size();i++)
        {
            int s=0;
            for(int j=0;j<ans[i].size();j++){
                s=s*10+ans[i][j];
            }
            sum+=s;
        }
        return sum;
    }
};