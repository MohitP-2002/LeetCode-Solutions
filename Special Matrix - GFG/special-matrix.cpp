// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
	int FindWays(int n, int m, vector<vector<int>>b){
	    // Code here
	    vector<vector<int>> grid(n, vector<int>(m,0));
	    for(int i=0;i<b.size();i++){
	        grid[b[i][0]-1][b[i][1]-1]=1;
	    }
	    int mod = 1e9+7;
	    if(grid[n-1][m-1]==1) return 0;
	    vector<vector<int>> dp(n+1, vector<int>(m+1,0));
	    dp[0][1]=1;
	    for(int i=1;i<=n;i++){
	        for(int j=1;j<=m;j++){
	            if(grid[i-1][j-1]!=1){
	                dp[i][j]=(dp[i-1][j]%mod+dp[i][j-1]%mod)%mod;
	            }
	        }
	    }
	    return dp[n][m]%(mod);
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m, k;
		cin >> n >> m >> k;
		vector<vector<int>>blocked_cells;
		for(int i = 0; i < k; i++){
			int x, y;
			cin >> x >> y;
			blocked_cells.push_back({x, y});
		}
		Solution obj;
		int ans = obj.FindWays(n, m, blocked_cells);
		cout << ans <<'\n';
	}
	return 0;
}  // } Driver Code Ends