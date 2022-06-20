class Solution {
public:
    int maxProfit(vector<int>& A) {
        int N = A.size();
        int K=2;
        if(N==0) return 0;
        vector<vector<int>> dp(K+1, vector<int>(N,0));
        for(int i=1;i<=K;i++){
            int diff=-A[0];
            for(int j=1;j<N;j++){
                dp[i][j]=max(dp[i][j-1], A[j]+diff);
                diff=max(diff, dp[i-1][j]-A[j]);
            }
        }
        return dp[K][N-1];
    }
};