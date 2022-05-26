// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    bool isInterleave(string A, string B, string C) 
    {
        //Your code hereth
        int n=A.length();
        int m=B.length();
        if(C.length()!=(m+n)) return false;
        bool dp[n+1][m+1];
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                if(i==0 && j==0) dp[i][j]=true;
                else if(i==0){
                    dp[i][j]=dp[i][j-1] && (B[j-1]==C[i+j-1]);
                }
                else if(j==0){
                    dp[i][j]=dp[i-1][j] && (A[i-1]==C[i+j-1]);
                }
                else{
                    dp[i][j]=(dp[i][j-1] && (B[j-1]==C[i+j-1]))||(dp[i-1][j] && (A[i-1]==C[i+j-1]));
                }
            }
        }
        return dp[n][m];
    }

};

// { Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
		string a,b,c;
		cin>>a;
		cin>>b;
		cin>>c;
		Solution obj;
		cout<<obj.isInterleave(a,b,c)<<endl;
	}
	// your code goes here
	return 0;
}  // } Driver Code Ends