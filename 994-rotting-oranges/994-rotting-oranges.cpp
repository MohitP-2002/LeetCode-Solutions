class Solution {
public:
    struct Node{
        int x;
        int y;
        int time;
    };
    int orangesRotting(vector<vector<int>>& grid) {
        queue<Node> q;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==2){
                    q.push({i,j,0});
                }
            }
        }
        int count=0;
        while(!q.empty()){
            Node cur = q.front();
            q.pop();
            int x = cur.x;
            int y = cur.y;
            count=cur.time;
            if(x-1>=0){
                if(grid[x-1][y]==1){
                    grid[x-1][y]=2;
                    q.push({x-1,y,cur.time+1});
                }
            }
            if(x+1<grid.size()){
                if(grid[x+1][y]==1){
                    grid[x+1][y]=2;
                    q.push({x+1,y,cur.time+1});
                }
            }
            if(y-1>=0){
                if(grid[x][y-1]==1){
                    grid[x][y-1]=2;
                    q.push({x,y-1,cur.time+1});
                }
            }
            if(y+1<grid[0].size()){
                if(grid[x][y+1]==1){
                    grid[x][y+1]=2;
                    q.push({x,y+1,cur.time+1});
                }
            }
        }
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }
        return count;
    }
};