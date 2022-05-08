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
    void helper(TreeNode* root, vector<int> v, vector<vector<int>>& ans){
        if(!root) return;
        v.push_back(root->val);
        if(root->left==NULL && root->right==NULL){
            ans.push_back(v);
            return;
        }
        helper(root->left,v,ans);
        helper(root->right,v,ans);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>  s;
        vector<int> v;
        vector<vector<int>> ans;
        helper(root,v,ans);
        for(int i=0;i<ans.size();i++){
            string ss="";
            for(int j=0;j<ans[i].size()-1;j++){
                cout<<ans[i][j]<<" ";
                ss+=to_string(ans[i][j]);
                ss+="->";
            }
            ss+=to_string(ans[i][ans[i].size()-1]);
            s.push_back(ss);
        }
        return s;
    }
};