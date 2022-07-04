class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        unordered_set<int> s;
        vector<bool> vis(rooms.size(),false);
        vis[0]=true;
        queue<int>q;
        for(int i=0;i<rooms[0].size();i++) {
            q.push(rooms[0][i]);
        }
        while(!q.empty()){
            int t=q.front();
            cout<<t<<" ";
            q.pop();
            if(vis[t]) continue;
            for(int i=0;i<rooms[t].size();i++){
                q.push(rooms[t][i]);
            }
            vis[t]=true;
        }
        for(int i=0;i<vis.size();i++){
            if(!vis[i]) return false;
        }
        return true;
    }
};