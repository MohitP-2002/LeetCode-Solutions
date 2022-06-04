// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000


 // } Driver Code Ends
/*You are required to complete this method*/

class Solution{
  public:
    int maxArea(int matrix[MAX][MAX], int m, int n) {
        // Your code here
        int left[n], right[n], height[n];
        fill_n(left,n,0); fill_n(right,n,n); fill_n(height,n,0);
        int maxA = 0;
        for(int i=0; i<m; i++) {
            int cur_left=0, cur_right=n; 
            for(int j=0; j<n; j++) { // compute height (can do this from either side)
                if(matrix[i][j]==1) height[j]++; 
                else height[j]=0;
            }
            for(int j=0; j<n; j++) { // compute left (from left to right)
                if(matrix[i][j]==1) left[j]=max(left[j],cur_left);
                else {left[j]=0; cur_left=j+1;}
            }
            // compute right (from right to left)
            for(int j=n-1; j>=0; j--) {
                if(matrix[i][j]==1) right[j]=min(right[j],cur_right);
                else {right[j]=n; cur_right=j;}    
            }
            // compute the area of rectangle (can do this from either side)
            for(int j=0; j<n; j++)
                maxA = max(maxA,(right[j]-left[j])*height[j]);
            // cout<<maxA<<" ";
        }
        return maxA;
    }
};


// { Driver Code Starts.
int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
}
  // } Driver Code Ends