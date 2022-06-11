// { Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function Template for C++

class Solution
{   
public:
vector<int> repeatedRows(vector<vector<int>> mat, int m, int n) 
{ 
    // Your code here
    unordered_map<string,int> mp;
   vector<int> v;
   for(int i=0;i<m;i++){
       string ans="";
       for(int j=0;j<n;j++){
           ans+=to_string(mat[i][j]);
       }
       if(mp[ans]==0){
           mp[ans]=1;
       }
       else{
           v.push_back(i);        
       }
       //cout<<ans<<endl;;
   }
   return v;
} 
};


// { Driver Code Starts.
int main() {
    int t;
    cin>>t;
    while(t--) 
    {
        int row, col;
        cin>> row>> col;
        vector<vector<int> > matrix(row); 
        for(int i=0; i<row; i++)
        {
            matrix[i].assign(col, 0);
            for( int j=0; j<col; j++)
            {
                cin>>matrix[i][j];
            }
        }
        
        Solution ob;
        vector<int> ans = ob.repeatedRows(matrix, row, col);


        for (int i = 0; i < ans.size(); ++i)
        {
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}


  // } Driver Code Ends