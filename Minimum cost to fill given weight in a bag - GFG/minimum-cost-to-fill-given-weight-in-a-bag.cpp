// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
#include <bits/stdc++.h>
using namespace std;
//Position this line where user code will be pasted.

class Solution{
		

	public:
	long long  int solver(int cost[], int n , int w, vector<vector<long long>>& dp){
	    if(w==0) return 0;
	    if(n==0 || w<0) return INT_MAX;
	    if(dp[n][w]!=-1) return dp[n][w];
	    if(cost[n-1]!=-1){
	        return dp[n][w]=min(cost[n-1]+solver(cost, n, w-n, dp), solver(cost,n-1,w,dp));
	    }
	    return dp[n][w]=solver(cost, n-1, w, dp);
	}
	int minimumCost(int cost[], int N, int W) 
	{ 
        // Your code goes here
        vector<vector<long long>> dp(N+1, vector<long long>(W+1,-1));
        return solver(cost, N, W, dp);
	} 
};


// { Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, w;
        cin >> n >> w;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minimumCost(a, n, w) << "\n";
	     
    }
    return 0;
}  // } Driver Code Ends