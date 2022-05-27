class Solution {
public:
    
    bool solver(vector<int> adj[], int V,int node,vector<int>& color){
        queue<int> q;
        q.push(node);
        color[node]=1;
        while(!q.empty()){
            int curr=q.front();
            q.pop();
            for(auto i:adj[curr]){
                    if(color[i]==color[curr])
                        return false;
                    if(color[i]==-1){
                        color[i]=1-color[curr];
                        q.push(i);
                    }
                }
            }
        
        return true;
        
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        int n =graph.size();
        vector<int> color(n,-1);
        vector<int> adj[n];
        for(int i=0;i<graph.size();i++){
            for(int j=0;j<graph[i].size();j++){
                adj[i].push_back(graph[i][j]);
            }
        }
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                if(solver(adj,n,i,color)==false) return false;
            }
        }
        
        return true;
    }
};