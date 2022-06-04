// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// Back-end complete function Template for C++

class Solution{
public:
    void dfs(int node, vector<int> adj[], vector<bool>& visited){
        visited[node]=true;
        for(auto i:adj[node]){
            if(!visited[i])
            dfs(i,adj,visited);
        }
    }
    vector<vector<int>> transitiveClosure(int N, vector<vector<int>> graph)
    {
        // code here
        vector<int> adj[N];
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(graph[i][j]==1){
                    adj[i].push_back(j);
                }
            }
        }
        for(int i=0;i<N;i++){
            vector<bool> visited(N,false);
            dfs(i,adj,visited);
            for(int k=0;k<N;k++){
                if(visited[k])graph[i][k]=1;
            }
        }
        return graph;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> graph(N, vector<int>(N, -1));
        for(int i = 0;i < N;i++)
            for(int j=0;j<N;j++)
            cin>>graph[i][j];
        
        Solution ob;
        vector<vector<int>> ans = ob.transitiveClosure(N, graph);
        for(int i = 0;i < N;i++)
            {for(int j = 0;j < N;j++)
                cout<<ans[i][j]<<" ";
        cout<<"\n";}
    }
    return 0;
}  // } Driver Code Ends