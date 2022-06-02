/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* dfs(Node* node, map<Node*,Node*>& m){
        vector<Node*> v;
        Node* clone = new Node(node->val);
        m[node]=clone;
        for(auto i:node->neighbors){
            if(m.find(i)!=m.end()){
                v.push_back(m[i]);
            }
            else v.push_back(dfs(i,m));
        }
        clone->neighbors=v;
        return clone;
    }
    Node* cloneGraph(Node* node) {
        map<Node*,Node*> m;
        if(node == NULL) return NULL;
        if(node->neighbors.size()==0) {
            Node* clone = new Node(node->val);
            return clone;
        }
        return dfs(node,m);
    }
};