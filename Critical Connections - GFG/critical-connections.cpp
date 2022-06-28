// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

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
                    ans.push_back({min(node,i), max(i,node)});
                }
            }
            else{
                low[node]=min(low[node], tin[i]);
            }
        }
    }
	vector<vector<int>>criticalConnections(int n, vector<int> adj[]){
	    // Code here
	    vector<vector<int>> ans;
        int timer=0;
        vector<int> vis(n,0);
        vector<int> tin(n,-1);
        vector<int> low(n,-1);
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                dfs(i,-1,vis,tin,low,timer,adj,ans);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
	}
};

// { Driver Code Starts.

int main(){
	int tc;
    cin >> tc;
    while(tc--){
        int V, E;
        cin >> V >> E;
        vector<int>adj[V];
        for(int i = 0; i < E; i++){
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        vector<vector<int>>ans = obj.criticalConnections(V, adj);
        
        for(int i=0;i<ans.size();i++)
            cout<<ans[i][0]<<" "<<ans[i][1]<<endl;
    }
	return 0;
}  // } Driver Code Ends