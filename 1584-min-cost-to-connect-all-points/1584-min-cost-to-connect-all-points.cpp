class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        int cost=0;
        int i=0,k=0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
        vector<bool> vis(n,false);
        while(++k < n){
            vis[i]=true;
            for(int j=0;j<n;j++){
                q.push({abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]),j});
            }
            while(vis[q.top().second]){
                q.pop();
            }
            cost+=q.top().first;
            i=q.top().second;
            q.pop();
        }
        return cost;
    }
};