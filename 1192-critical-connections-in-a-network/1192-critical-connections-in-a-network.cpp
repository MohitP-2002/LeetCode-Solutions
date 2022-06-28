class Solution {
public:
    void dfs(int node, int parent, vector<int>& vis, vector<int>& tin, vector<int>& low, int timer, vector<int>adj[], vector<vector<int>>& ans){
        vis[node]=1;
        tin[node]=low[node]=timer++;
        for(auto i:adj[node]){
            if(i==parent) continue;
            if(vis[i]==0){
                dfs(i,node,vis,tin,low,timer,adj,ans);
                low[node]=min(low[node],low[i]);
                if(low[i]>tin[node]){
                    ans.push_back({node,i});
                }
            }
            else{
                low[node]=min(low[node], tin[i]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& c) {
        vector<vector<int>> ans;
        vector<int> adj[n];
        for(int i=0;i<c.size();i++){
            adj[c[i][0]].push_back(c[i][1]);
            adj[c[i][1]].push_back(c[i][0]);
        }
        int timer=0;
        vector<int> vis(n,0);
        vector<int> tin(n,-1);
        vector<int> low(n,-1);
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                dfs(i,-1,vis,tin,low,timer,adj,ans);
            }
        }
        return ans;
    }
};