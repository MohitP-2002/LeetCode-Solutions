// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    int selectMinVertex(vector<int> value, vector<bool> vis){
        int vertex=-1;
        int min=INT_MAX;
        for(int i=0;i<value.size();i++){
            if(min>value[i] && !vis[i]){
                vertex=i;
                min=value[i];
            }
        }
        return vertex;
    }
    vector <int> dijkstra(int V, vector<vector<int>> aj[], int S)
    {
        // Code here
        vector <int>  value(V,INT_MAX);
        vector<bool> vis(V,false);
        value[S]=0;
        for(int i=0;i<V-1;i++){
            int u=selectMinVertex(value, vis);
            vis[u]=true;
            for(auto v:aj[u]){
                if(!vis[v[0]]  && value[u]!=INT_MAX && (v[1]+value[u])<value[v[0]]){
                    value[v[0]]=v[1]+value[u];
                }
            }
        }
        return value;
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
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}

  // } Driver Code Ends