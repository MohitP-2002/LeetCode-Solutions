class Solution {
public:
    int maximalSquare(vector<vector<char>>& mat) {
        int n =mat.size();
        int m =mat[0].size();
        int max=0;
        int dp[n][m];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                dp[i][j]=mat[i][j]-'0';
                if(i && j && mat[i][j]=='1'){
                    dp[i][j]=min(dp[i-1][j-1], min(dp[i-1][j],dp[i][j-1]))+1;
                }
                if(max<dp[i][j]) max=dp[i][j];
            }
        }
        return max*max;
    }
};