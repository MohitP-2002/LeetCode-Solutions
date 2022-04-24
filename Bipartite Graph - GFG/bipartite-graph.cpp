// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
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
    
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    vector<int> color(V,-1);
	    for(int i=0;i<V;i++){
	        if(color[i]==-1){
	            if(solver(adj,V,i,color) == false) return false;
	        }
	    }
	    return true;
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
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}  // } Driver Code Ends