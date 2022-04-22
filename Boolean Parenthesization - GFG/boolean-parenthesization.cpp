// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int dp[101][101][2];
int helper(string s,
                      int i,
                      int j,
                      int isTrue)
{
    // Base Condition
    if (i > j)
        return false;
    if (i == j) {
        if (isTrue == 1)
            return s[i] == 'T';
        else
            return s[i] == 'F';
    }
 
    if (dp[i][j][isTrue] != -1)
        return dp[i][j][isTrue];
    long int ans = 0;
    for (int k = i + 1
         ; k <= j - 1; k = k + 2)
    {
        int leftF, leftT, rightT, rightF;
        if (dp[i][k - 1][1] == -1)
        {
            leftT = helper(s, i, k - 1, 1);
            dp[i][k - 1][1]=leftT;
        } // Count no. of T in left partition
        else {
            leftT = dp[i][k - 1][1];
        }
 
        if (dp[k + 1][j][1] == -1)
        {
            rightT = helper(s, k + 1, j, 1);
            dp[k + 1][j][1]=rightT;
        } // Count no. of T in right partition
        else
        {
            rightT = dp[k + 1][j][1];
        }
 
        if (dp[i][k - 1][0] == -1)
        {
            // Count no. of F in left partition
            leftF = helper(s, i, k - 1, 0);
            dp[i][k - 1][0]=leftF;
        }
        else
        {
            leftF = dp[i][k - 1][0];
        }
 
        if (dp[k + 1][j][0] == -1)
        {
            // Count no. of F in right partition
            rightF = helper(s, k + 1, j, 0);
            dp[k + 1][j][0]=rightF;
        }
        else
        {
            rightF = dp[k + 1][j][0];
        }
 
        if (s[k] == '&')
        {
            if (isTrue == 1)
                ans += leftT * rightT;
            else
                ans += leftF * rightF + leftT * rightF
                       + leftF * rightT;
        }
        else if (s[k] == '|')
        {
            if (isTrue == 1)
                ans += leftT * rightT + leftT * rightF
                       + leftF * rightT;
            else
                ans = ans + leftF * rightF;
        }
        else if (s[k] == '^')
        {
            if (isTrue == 1)
                ans = ans + leftF * rightT + leftT * rightF;
            else
                ans = ans + leftT * rightT + leftF * rightF;
        }
        dp[i][j][isTrue] = ans;
    }
    return ans%1003;
}
 
    
    int countWays(int N, string S){
        // code here
        int i=0,j=N-1 ;
        memset(dp,-1,sizeof(dp));
        return helper(S,i,j,1);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.countWays(N, S)<<"\n";
    }
    return 0;
}  // } Driver Code Ends