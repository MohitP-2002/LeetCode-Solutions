// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

//Function to find the maximum possible amount of money we can win.
class Solution{
    public:
    long long helper(int arr[], int i, int j, int sum, vector<vector<int>>& dp){
        if(i+1==j) return max(arr[i],arr[j]);
        if(dp[i][j]!=-1) return dp[i][j];
        dp[i][j] = max((sum-helper(arr,i+1,j,sum-arr[i],dp)),( sum-helper(arr,i,j-1,sum-arr[j],dp)));
        return dp[i][j];
    }
    long long maximumAmount(int arr[], int n){
        // Your code here
        int sum=0;
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        for(int i=0;i<n;i++) sum+=arr[i];
        return helper(arr,0,n-1,sum,dp);
    }
};

// { Driver Code Starts.
int main() 
{
   
   	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution ob;
		cout<< ob.maximumAmount(a,n)<<endl;
	}
	return 0;
}  // } Driver Code Ends