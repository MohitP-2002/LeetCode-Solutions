// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

 // } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum money the thief can get.
    int dp[10001];
    int helper(int arr[],int x){
        if(x<0) return 0;
        if(dp[x]!=-1) return dp[x];
        int t1=arr[x]+helper(arr,x-2);
        int t2=helper(arr,x-1);
        return dp[x]=max(t1,t2);
    }
    int FindMaxSum(int arr[], int n)
    {
        // Your code here
        dp[n];
        memset(dp,-1,sizeof(dp));
        return helper(arr,n-1);
    }
};

// { Driver Code Starts.
int main()
{
    //taking total testcases
	int t;
	cin>>t;
	while(t--)
	{
	    //taking number of houses
		int n;
		cin>>n;
		int a[n];
		
		//inserting money of each house in the array
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;
		//calling function FindMaxSum()
		cout<<ob.FindMaxSum(a,n)<<endl;
	}
	return 0;
}
  // } Driver Code Ends