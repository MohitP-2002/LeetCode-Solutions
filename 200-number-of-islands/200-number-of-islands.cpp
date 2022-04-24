class Solution {
public:
    
    void util(vector<vector<char>>& grid, int i,int j,int r, int c){
        if(i<0 || i>=r || j<0 || j>=c || grid[i][j]!='1') return ;
        grid[i][j]='2';
        util(grid,i-1,j,r,c);
        util(grid,i,j-1,r,c);
        util(grid,i+1,j,r,c);
        util(grid,i,j+1,r,c);
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int rows=grid.size();
        if(rows==0) return 0;
        int ans=0,col=grid[0].size();
        for(int i=0;i<rows;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]=='1'){
                    util(grid,i,j,rows,col);
                    ans++;
                }
            }
        }
        return ans;
    }
};