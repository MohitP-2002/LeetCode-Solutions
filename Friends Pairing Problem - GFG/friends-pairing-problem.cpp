// { Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends

#define M 1000000007
class Solution
{
public:
    long long int dp[10001];
    int fun(int n){
        if(n<=2) return n;
        if(dp[n]!=-1) return dp[n];
        dp[n-1]=fun(n-1)%M;
        dp[n-2]=fun(n-2)%M;
        dp[n]=(dp[n-1]+(n-1)*dp[n-2])%M;
        return dp[n];
    }
    
    int countFriendsPairings(int n) 
    { 
        memset(dp,-1,sizeof(dp));
        return fun(n);
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
    	Solution ob;
    	cout <<ob.countFriendsPairings(n); 
    	cout<<endl;
    }
} 
  // } Driver Code Ends