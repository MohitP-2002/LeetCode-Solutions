class Solution {
public:

    bool dfs(int v, vector<int> adj[],bool vis[],bool b[]){
        if(vis[v] == false)
        {
            vis[v]=true;
            b[v]=true;
            for(auto i:adj[v]){
                if(!vis[i] && dfs(i,adj,vis,b))
                return true;
                if(b[i]==true)return true;
            }
        }
        b[v]=false;
        return false;
    }
        
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        bool vis[V],b[V];
        for(int i=0;i<V;i++){
           vis[i]=false;
           b[i]=false;
        }
        for(int i=0;i<V;i++){
            if(dfs(i,adj,vis,b)) return true;
        }
        return false;
    }
    bool canFinish(int n, vector<vector<int>>& p) {
        if(p.size()==1) return true;
        vector<int> adj[n+1];
        for(int i=0;i<p.size();i++){
            adj[p[i][0]].push_back(p[i][1]);
        }
        if(isCyclic(n,adj)==true) return false;
        return true;
    }
};