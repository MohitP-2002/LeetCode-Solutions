class Solution {
public:
    void dfs(vector<vector<int>>& grid, int i, int j, int& res){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]==0) return;
        grid[i][j]=0;
        res++;
        dfs(grid,i-1,j,res);
        dfs(grid,i+1,j,res);
        dfs(grid,i,j-1,res);
        dfs(grid,i,j+1,res);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        int ans=0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]==0) continue;
                int res=0;
                dfs(grid,i,j,res);
                ans=max(ans,res);
            }
        }
        return ans;
    }
};