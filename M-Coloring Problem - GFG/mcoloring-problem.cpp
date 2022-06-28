// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// Function to determine if graph can be coloured with at most M colours such
// that no two adjacent vertices of graph are coloured with same colour.
bool isValid(bool graph[101][101], int i, int k, vector<int>& color, int n){
    for(int j=0;j<n;j++){
        if(graph[i][j] && color[j]==k) return false;
    }
    return true;
}
bool solver(bool graph[101][101], int m , int n , int i, vector<int>& color){
    if(i==n) return true;
    for(int k=0;k<m;k++){
        if(isValid(graph, i, k, color,n)){
            color[i]=k;
            if(solver(graph,m,n,i+1, color)) return true;
            color[i]=-1;
        }
    }
    return false;
}
bool graphColoring(bool graph[101][101], int m, int n) {
    // your code here
    vector<int> color(n,-1);
    return solver(graph, m,n,0, color);
}

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        cout << graphColoring(graph, m, n) << endl;
    }
    return 0;
}
  // } Driver Code Ends