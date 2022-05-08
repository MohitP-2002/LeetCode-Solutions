/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    void level(Node* root,  vector<vector<Node*>>& v, int l ){
        if(root==NULL) return;
        if(l==v.size()) v.push_back(vector<Node*>());
        v[l].push_back(root);
        level(root->left,v,l+1);
        level(root->right,v,l+1);
    }
    Node* connect(Node* root) {
        if(root==NULL)return NULL;
        root->next=NULL;
        vector<vector<Node*>>v;
        level(root, v, 0);
        for(int i=1;i<v.size();i++){
            for(int j=0;j<v[i].size()-1;j++){
                v[i][j]->next=v[i][j+1];
            }
            v[i][v[i].size()-1]->next=NULL;
        }
        return root;
    }
};