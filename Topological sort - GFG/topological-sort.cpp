// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	bool helper(vector<int>adj[],int n,vector<int> indegree,vector<int>&ans){
        queue<int> q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0) q.push(i);
        }
        int count=0;
        while(!q.empty()){
            int cur=q.front();
            q.pop();
            for(auto i:adj[cur]){
                indegree[i]--;
                if(indegree[i]==0) q.push(i);
            }
            ans.push_back(cur);
            count++;
        }
        if(count!=n) return false;
        return true;
    }
	vector<int> topoSort(int n, vector<int> adj[]) 
	{
	    // code here
	    vector<int> ans;
        vector<int> indegree(n,0);
        for(int i=0;i<n;i++){
            for(auto v:adj[i]){
                indegree[v]++;
            }
        }
        if(helper(adj,n,indegree,ans)==false){
            ans.clear();
            return ans;
        }
        return ans;
	}
};

// { Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    
    if(V!=res.size())
    return 0;
    
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}  // } Driver Code Ends