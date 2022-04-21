class Solution {
public:
    
    string helper(string s,string w,int n,int m){
        int dp[n+1][m+1];
        string st="";
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
        int i=n,j=m;
        while(i>0 && j>0){
            if(s[i-1]==w[j-1]){
                st+=s[i-1];
                i--;
                j--;
            }
            else{
                if(dp[i-1][j]>dp[i][j-1]){
                    st+=s[i-1];
                    i--;
                }
                else{
                    st+=w[j-1];
                    j--;
                }
            }
        }
        while(i>0){
            st+=s[i-1];i--;
        }
        while(j>0){
            st+=w[j-1];j--;
        }
        reverse(st.begin(),st.end());
        return st;
    }

    string shortestCommonSupersequence(string str1, string str2) {
        int n=str1.length();
        int m=str2.length();
        return helper(str1,str2,n,m);
    }
};