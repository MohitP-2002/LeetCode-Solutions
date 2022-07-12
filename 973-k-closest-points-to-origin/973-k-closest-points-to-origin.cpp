class Solution {
public:
    struct comp{
        bool operator()(pair<pair<int,int>, double> a, pair<pair<int,int>, double>b){
            return a.second < b.second;
        }
    };
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> ans;
        priority_queue<pair<pair<int,int>, double>, vector<pair<pair<int, int>, double>>, comp> q;
        for(int i=0;i<points.size();i++){
            double dist = sqrt((points[i][0]*points[i][0])+(points[i][1]*points[i][1]));
            q.push({{points[i][0], points[i][1]}, dist});
            if(q.size() > k)q.pop();
        }
        while(!q.empty()){
            ans.push_back({q.top().first.first, q.top().first.second});
            q.pop();
        }
        return  ans;
    }
};