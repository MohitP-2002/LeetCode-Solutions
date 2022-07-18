class Solution {
public:
    int dx[4]={0,0,1,-1};
    int dy[4]={1,-1,0,0};
    int maxDistance(vector<vector<int>>& grid) {
        if(grid.size()==0) return -1;
        int dist=0;
        queue<pair<int,int>> q;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    q.push({i,j});
                }
            }
        }
        if(q.size()==(grid.size()*grid[0].size())) return -1;
        while(!q.empty()){
            int size = q.size();
            dist++;
            for(int k=0;k<size;k++){
                int p=q.front().first;
                int m=q.front().second;
                q.pop();
                for(int x=0;x<4;x++){
                    int i=p+dx[x];
                    int j=m+dy[x];
                    if(i>=0 && i<grid.size() && j>=0 && j<grid[0].size() && grid[i][j]==0){
                        q.push({i,j});
                        grid[i][j]=1;
                    }
                }
            }
        }
        return dist-1;
    }
};