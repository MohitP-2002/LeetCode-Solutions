// { Driver Code Starts
#include <bits/stdc++.h>
#include<stdio.h>
#include<math.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    int m = 1e9+7;
    long long solver(int n,int k, vector<long long>& dp){
        if(n==0) return 0;
        if(n==1) return k;
        if(n==2) return (k*k);
        if(dp[n]!=-1) return dp[n];
        return dp[n]=(k-1)*(solver(n-1,k,dp)%m+solver(n-2,k,dp)%m)%m;
    }
    long long countWays(int n, int k){
        // code here
        vector<long long> dp(n+1,-1);
        return solver(n,k,dp);
    }
};

// { Driver Code Starts.

int main()
{
	
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		Solution ob;
		cout<<ob.countWays(n,k)<<endl;
	}
	return 0;
}  // } Driver Code Ends