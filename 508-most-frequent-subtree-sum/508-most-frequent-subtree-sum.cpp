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
    int solver(TreeNode* root, map<int,int>& m){
        if(root==NULL) return 0;
        root->val=root->val+solver(root->left,m )+ solver(root->right,m);
        m[root->val]++;
        return root->val;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        map<int,int> m;
        map<int,vector<int>, greater<int>> map;
        solver(root,m);
        for(auto i:m){
            map[i.second].push_back(i.first);
        }
        for(auto i:map){
            return i.second;
        }
        return {};
    }
};