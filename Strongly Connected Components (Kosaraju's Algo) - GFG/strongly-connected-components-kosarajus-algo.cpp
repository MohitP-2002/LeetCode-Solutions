// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
// 	int count=0;
	void dfss(int node, stack<int>& s,vector<int>adj[], vector<bool>& visited){
	    visited[node]=true;
	    for(auto i:adj[node]){
	        if(!visited[i]){
	            dfss(i,s,adj,visited);
	        }
	    }
	    s.push(node);
	}
	void dfs(int node, vector<bool>& visited, vector<int> rev[]){
	   // count++;
	    visited[node]=true;
	    for(auto i:rev[node]){
	        if(!visited[i]){
	            dfs(i,visited,rev);
	        }
	    }
	}
    int kosaraju(int V, vector<int> adj[])
    {
        //code here
        int count=0;
        vector<int> rev[V];
        stack<int> s;
        vector<bool> visited(V,false);
        for(int i=0;i<V;i++){
            if(!visited[i])
            dfss(i,s,adj,visited);
        }
        for(int i=0;i<V;i++){
	        for(auto k:adj[i]){
	            rev[k].push_back(i);
	        }
	    }
        for(int i=0;i<V;i++) visited[i]=false;
        while(!s.empty()){
            int cur=s.top();
            s.pop();
            if(!visited[cur]){
                count++;
                dfs(cur,visited,rev);
            }
        }
        return count;
    }
};

// { Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends