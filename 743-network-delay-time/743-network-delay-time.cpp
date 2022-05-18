class Solution {
public:
    int selectMinVertex(vector<int> value, vector<bool> vis){
        int vertex=0;
        int min=INT_MAX;
        for(int i=1;i<value.size();i++){
            if(min>value[i] && !vis[i]){
                vertex=i;
                min=value[i];
            }
        }
        return vertex;
    }
    int networkDelayTime(vector<vector<int>>& aj, int V, int S) {
        vector <int>  value(V+1,INT_MAX);
        vector<pair<int,int>> adj[V+1];
        for(auto t:aj){
            adj[t[0]].push_back(make_pair(t[1],t[2]));
        }
        vector<bool> vis(V+1,false);
        value[S]=0;
        for(int i=1;i<=V-1;i++){
            int u=selectMinVertex(value, vis);
            vis[u]=true;
            for(auto v:adj[u]){
                if(!vis[v.first] && value[u]!=INT_MAX && (value[u]+v.second)<value[v.first]){
                    value[v.first]=value[u]+v.second;
                }
            }
            
        }
        int ans=INT_MIN;
        for(int i=1;i<=V;i++){
            ans=max(ans,value[i]);
        }
        return (ans==INT_MAX)?-1:ans;
    }
};