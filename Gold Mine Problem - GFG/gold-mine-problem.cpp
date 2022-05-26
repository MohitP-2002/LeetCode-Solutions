// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int maxGold(int n, int m, vector<vector<int>> M)
    {
        // code here
        vector<vector<int>> dp(n + 2, vector<int>(m));
                
        for (int c = 0; c < m; ++c)
        	for (int r = 0; r < n; ++r)
        		dp[r + 1][c] = M[r][c] +
        			max(dp[r    ][c - 1], 
        			max(dp[r + 1][c - 1], 
        				dp[r + 2][c - 1]));
        
        int ret = 0;
        
        for (int r = 0; r < n + 2; ++r)
        	ret = max(ret, dp[r][m - 1]);
        	
        return ret;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>> M(n, vector<int>(m, 0));
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++)
                cin>>M[i][j];
        }
        
        Solution ob;
        cout<<ob.maxGold(n, m, M)<<"\n";
    }
    return 0;
}  // } Driver Code Ends