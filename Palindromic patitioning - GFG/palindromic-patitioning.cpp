// { Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    
    int dp[501][501];
    
   
    bool isPalin(string String, int i, int j)
    {
        while(i < j)
        {
          if(String[i] != String[j])
            return false; 
          i++;
          j--;
        }
        return true;
    }
    
    int helper(string a,int i,int j){
        
        if(i>=j) return 0;
        
        if(isPalin(a,i,j) == true) return 0;
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        int min=INT_MAX;
        
        for(int k=i;k<j;k++){
            
            int left=(dp[i][k]!=-1)?dp[i][k]:helper(a,i,k);
            int right=(dp[k+1][j]!=-1)?dp[k+1][j]:helper(a,k+1,j);
            
            int temp = 1 + left + right;
            
            min = (temp<min)? temp:min;
        }
        return dp[i][j]=min;
    }
    
    int palindromicPartition(string str)
    {
        // code here
        int n=str.length();
        int i=0,j=n-1;
        if(isPalin(str,i,j)==true) return 0;
        for(int i=0;i<501;i++){
            for(int j=0;j<501;j++){
                dp[i][j]=-1;
            }
        }
        return helper(str,i,j);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}  // } Driver Code Ends