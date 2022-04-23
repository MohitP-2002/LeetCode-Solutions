// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    int dp[101][10001];
    int solver(int e, int f) {
        if(f==0 || f==1) return f;
        if(e==1) return f;
        if(dp[e][f]!=-1) return dp[e][f];
        int ans=INT_MAX;
        for(int i=1;i<=f;i++){
            dp[e-1][i-1] =(dp[e-1][i-1]!=-1)?dp[e-1][i-1]:solver(e-1,i-1);
            dp[e][f-i]=(dp[e][f-i]!=-1)?dp[e][f-i]:solver(e,f-i);
            int temp=1+ max(dp[e-1][i-1] ,dp[e][f-i] );
            ans=(ans<temp)?ans:temp;
        }
        return dp[e][f]=ans;
    }
    int eggDrop(int e, int f) 
    {
        // your code here
        for(int i=0;i<=100;i++){
            for(int j=0;j<=10000;j++){
                dp[i][j]=-1;
            }
        }
        return solver(e,f);
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
        //taking eggs and floors count
        int n, k;
        cin>>n>>k;
        Solution ob;
        //calling function eggDrop()
        cout<<ob.eggDrop(n, k)<<endl;
    }
    return 0;
}
  // } Driver Code Ends