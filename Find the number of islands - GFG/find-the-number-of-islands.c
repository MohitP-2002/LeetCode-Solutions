// { Driver Code Starts
// Initial Template for C

// Program to count islands in boolean 2D matrix
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define COL 501


 // } Driver Code Ends
// User function Template for C

 void util(int grid[][COL], int i,int j,int r, int c){
        if(i<0 || i>=r || j<0 || j>=c || grid[i][j]!=1) return ;
        grid[i][j]=2;
        util(grid,i-1,j,r,c);
        util(grid,i,j-1,r,c);
        util(grid,i+1,j,r,c);
        util(grid,i,j+1,r,c);
        util(grid,i-1,j-1,r,c);
        util(grid, i+1, j+1, r,c);
        util(grid, i-1, j+1, r,c);
        util(grid, i+1, j-1, r,c);
    }
int countIslands(int grid[][COL], int rows, int col) {
    // your code goes here
    if(rows==0) return 0;
        int ans=0;
        for(int i=0;i<rows;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]==1){
                    util(grid,i,j,rows,col);
                    ans++;
                }
            }
        }
        return ans;
}


// { Driver Code Starts.

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {

        int n, m;
        scanf("%d %d", &n, &m);

        int M[n][COL];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%d", &M[i][j]);
            }
        }

        int ans = countIslands(M, n, m);
        printf("%d\n", ans);
    }

    return 0;
}
  // } Driver Code Ends