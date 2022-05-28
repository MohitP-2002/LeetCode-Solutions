class Solution {
public:
    int find(int u, vector<int>& parent){
        return (parent[u]==u)?u:find(parent[u],parent);
    }
    int makeConnected(int n, vector<vector<int>>& edges) {
        vector<int>parent(n);
        for(int i=0;i<n;i++) parent[i]=i;
        for(int i=0;i<edges.size();i++){
            int x=find(edges[i][0],parent);
            int y=find(edges[i][1],parent);
            if(x!=y){
                parent[y]=x;
            }
        }
        int not_con=0;
        for(int i=0;i<n;i++){
            if(parent[i]==i) not_con++;
        }
        not_con--;
        int m = edges.size();
        int con=n-not_con;
        if(m-(con-1)>=not_con) return not_con;
        return -1;
    }
};