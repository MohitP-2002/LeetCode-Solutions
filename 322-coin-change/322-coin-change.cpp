class Solution {
public:
     int knapSack(int N, int W ,vector<int> wt)
    {
        // code here
        int t[N+1][W+1];
        for(int i=0;i<=N;i++){
            for(int j=0;j<=W;j++){
                if(i==0) t[i][j]=INT_MAX-1;
                if(j==0) t[i][j]=0;
            }
        }
         // for(int i=1,j=1;j<=W;j++){
         //     if(j%wt[0]==0) t[i][j]=j/wt[0];
         //     else
         //         t[i][j]=INT_MAX-1;
         // }
        for(int i=1;i<=N;i++){
            for(int j=1;j<=W;j++){
                if(wt[i-1]<=j){
                    t[i][j]=min(1+t[i][j-wt[i-1]],t[i-1][j]);
                }
                else t[i][j]=t[i-1][j];
            }
        }
        return t[N][W];
    }
    int coinChange(vector<int>& coins, int amount) {
        if(amount==0) return 0;
        int count=knapSack(coins.size(),amount,coins);
        return (count==INT_MAX-1)?-1:count;
    }
};