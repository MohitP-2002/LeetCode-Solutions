class Solution {
public:
    void dfs(vector<vector<int>>& graph, int i, vector<vector<int>>& v, vector<int>& p){
        if(i==graph.size()-1) {
            v.push_back(p);
            return;
        }
        for(auto node:graph[i]){
            p.push_back(node);
            dfs(graph, node, v, p);
            //backtrack
            p.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> v;
        int n =graph.size();
        vector<bool> visited(n,false);
        vector<int>p;
        p.push_back(0);
        dfs(graph, 0, v, p);
        return v; 
    }
};