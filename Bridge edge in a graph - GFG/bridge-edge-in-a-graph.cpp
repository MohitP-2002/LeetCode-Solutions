// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
    //Function to find if the given edge is a bridge in graph.
    void  dfs(int node, int V,vector<int> adj[], vector<bool>& visited){
        visited[node]=true;
        for(auto i:adj[node]){
            if(!visited[i]){
                dfs(i, V, adj, visited);
            }
        }
    }
    int isBridge(int V, vector<int> adj[], int c, int d) 
    {
        // Code here
        adj[c].erase(remove(adj[c].begin(), adj[c].end(), d), adj[c].end());
        adj[d].erase(remove(adj[d].begin(), adj[d].end(), c), adj[d].end());
        vector<bool> visited(V, false);
        dfs(c,V,adj, visited);
        return !visited[d];
    }
};

// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        int i=0;
        while (i++<E) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back (v);
            adj[v].push_back (u);
        }
        
        int c,d;
        cin>>c>>d;
        
        Solution obj;
    	cout << obj.isBridge(V, adj, c, d) << "\n";
    }

    return 0;
}

  // } Driver Code Ends