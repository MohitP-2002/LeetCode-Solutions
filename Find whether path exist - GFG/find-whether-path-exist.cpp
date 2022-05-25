// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    //Function to find whether a path exists from the source to destination.
    int flag=false;
   void dfs(int i,int j,vector<vector<int>>& grid)
   {
       int m=grid.size();
       int n=grid[0].size();
        if(i>=0 and j>=0 and i<grid.size()and j<grid[0].size() and grid[i][j]==0 )
        return;
       if(i>=0 and j>=0 and i<grid.size()and j<grid[0].size() and grid[i][j]==2 )
       {
           flag =true;
           return;
       }
      
       if(i>=0 and j>=0 and i<grid.size() and j<grid[0].size() )
       {
           grid[i][j]=0;
               dfs(i-1,j,grid);
               dfs(i,j+1,grid);
               dfs(i+1,j,grid);
               dfs(i,j-1,grid);
       }
       return;
   }
   bool is_Possible(vector<vector<int>>& grid) 
   {
       int m=grid.size();
       int n=grid[0].size();
       int src_i,src_j,dst_i,dst_j;
       for(int i=0;i<m;i++)
       for(int j=0;j<n;j++)
       {
           if(grid[i][j]==1)
           src_i=i,src_j=j;
       }
       
       dfs(src_i,src_j,grid);
       return flag;
       
   }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		bool ans = obj.is_Possible(grid);
		cout << ((ans) ? "1\n" : "0\n");
	}
	return 0;
}  // } Driver Code Ends