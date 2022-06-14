class Solution {
public:
    int helper(string s , string w, int n, int m){
        int dp[n+1][m+1];
        for(int i=0;i<=m;i++){
            dp[0][i]=0;
        }
        for(int i=0;i<=n;i++){
                dp[i][0]=0;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1]==w[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[n][m];
    }

    int minDistance(string word1, string word2) {
        int n=word1.length();
        int m=word2.length();
        int lcs=helper(word1,word2,n,m);
        return (n+m-2*lcs);
    }
};