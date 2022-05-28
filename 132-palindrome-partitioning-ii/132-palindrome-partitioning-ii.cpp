class Solution {
public:
    bool isPalindrome(int i, int j, string& str){
        while(i<j){
            if(str[i]!=str[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    int fun(int i, int n, string& str, vector<int>& dp){
        //base case 
        if(i==n) return 0;
        //memoization
        if(dp[i]!=-1) return dp[i];
        int minCost=INT_MAX;
        for(int j=i;j<n;j++){
            if(isPalindrome(i,j,str)){
                int cost=1+fun(j+1,n,str, dp);
                minCost=min(minCost,cost);
            }
        }
        return dp[i]=minCost;
    }
    int minCut(string s) {
        int n =s.length();
        vector<int> dp(n,-1);
        return fun(0,n,s,dp)-1;
    }
};