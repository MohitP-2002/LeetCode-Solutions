// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int checkMirrorTree(int n, int e, int A[], int B[]) {
        // code here
        vector<int> adj[n+1],adj1[n+1];
        for(int i=0;i<2*e;i+=2){
            adj[A[i]].push_back(A[i+1]);
            adj1[B[i]].push_back(B[i+1]);
        }
        for(int i=0;i<=n;i++){
            reverse(adj[i].begin(),adj[i].end());
            if(adj[i]!=adj1[i]) return 0;
        }
        return 1;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,e;
        
        cin>>n>>e;
        int A[2*e], B[2*e];
        
        for(int i=0; i<2*e; i++)
            cin>>A[i];
            
        for(int i=0; i<2*e; i++)
            cin>>B[i];

        Solution ob;
        cout << ob.checkMirrorTree(n,e,A,B) << endl;
    }
    return 0;
}  // } Driver Code Ends