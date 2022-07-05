/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void dfs(int node, int target, vector<int> adj[], vector<int> & v, int k, vector<int>& vis){
        if(k==0){
            if(node!=target)
            v.push_back(node);
            return;
        }
        vis[node]=1;
        for(auto i:adj[node]){
            k-=1;
            if(!vis[i])
            dfs(i,target,adj,v,k,vis);
            k+=1;
        }
        vis[node]=0;
    }
    void graph(TreeNode* root, vector<int> adj[]){
        if(!root) return;
        if(root->left){
            adj[root->val].push_back(root->left->val);
            adj[root->left->val].push_back(root->val);
        }
        if(root->right){
            adj[root->val].push_back(root->right->val);
            adj[root->right->val].push_back(root->val);
        }
        graph(root->left, adj);
        graph(root->right, adj);
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if(k==0) return {target->val};
        vector<int> adj[500];
        graph(root, adj);
        vector<int> v, vis(500,0);
        // int level=0;
        dfs(target->val,target->val, adj, v, k, vis);
        return v;
    }
};