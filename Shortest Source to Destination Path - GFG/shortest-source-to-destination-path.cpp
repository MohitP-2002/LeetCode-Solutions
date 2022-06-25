// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    bool isValid(int x, int y, int n, int m){
        if(x<0 || y<0 || x>=n || y>=m) return false;
        return true;
    } 
    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
        // code here
        if(A[X][Y]==0 || A[0][0]==0) return -1;
        queue<vector<int>>q;
        q.push({0,0,0});
        int ans=INT_MAX;
        int dx[4]={1,-1,0,0};
        bool flag =false;
        int dy[4]={0,0,-1,1};
        while(!q.empty()){
            auto cur=q.front();
            q.pop();
            if(cur[0]==X && cur[1]==Y){
                flag = true;
                ans=cur[2];
                break;
            }
            for(int i=0;i<4;i++){
                int x = cur[0]+dx[i];
                int y = cur[1]+dy[i];
                if(isValid(x,y,N,M) && A[x][y]==1){     
                    q.push({x,y,cur[2]+1});
                    A[x][y]=0;
                }
            }
        }
        if(flag) return ans;
        return -1;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    }
}  // } Driver Code Ends