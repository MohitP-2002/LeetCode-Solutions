// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    //Function to find unit area of the largest region of 1s.
    void dfs(vector<vector<int>>& grid, int i, int j, int& res){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]==0) return;
        grid[i][j]=0;
        res++;
        dfs(grid,i-1,j,res);
        dfs(grid,i+1,j,res);
        dfs(grid,i,j-1,res);
        dfs(grid,i,j+1,res);
        dfs(grid,i-1,j-1,res);
        dfs(grid,i-1,j+1,res);
        dfs(grid,i+1,j-1,res);
        dfs(grid,i+1,j+1,res);
    }
    int findMaxArea(vector<vector<int>>& grid) {
        // Code here
        int r = grid.size();
        int c = grid[0].size();
        int ans=0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]==0) continue;
                int res=0;
                dfs(grid,i,j,res);
                ans=max(ans,res);
            }
        }
        return ans;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.findMaxArea(grid);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends