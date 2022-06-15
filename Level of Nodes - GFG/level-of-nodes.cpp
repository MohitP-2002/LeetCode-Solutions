// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution
{
	public:
	//Function to find the level of node X.
	int nodeLevel(int V, vector<int> adj[], int X) 
	{
	    // code here
	    vector<bool> vis(V,false);
	    queue<pair<int,int>> q;
	    q.push({0,0});
	    while(!q.empty()){
	        auto cur=q.front();
	        q.pop();
	        vis[cur.first]=true;
	        int bt=cur.second;
	        if(cur.first==X) return cur.second;
	        for(auto i:adj[cur.first]){
	            if(vis[i]) continue;
	            q.push({i,bt+1});
	            vis[i]=true;
	        }
	    }
	    return -1;
	}
};

// { Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E, X;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    		adj[v].push_back(u);
    	}
    	cin>>X;

    	Solution obj;
    	cout << obj.nodeLevel(V, adj, X) << "\n";
    }

    return 0;
}

  // } Driver Code Ends